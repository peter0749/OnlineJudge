// 3327951, AC, 24ms, 652KB
#pragma GCC target ("avx")
#pragma GCC optimize ("O3")

#include <stdexcept>
#include <queue>
// for bfs
#include <functional> 
// for pair
#include <cstring>
#include <cmath>
// for dist(sqrt)

/*
 * Image object structure:
 * some basic information: width, height, pointer to data
 */

struct Pix {
    uint8_t r,g,b,alpha;
    Pix(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) : r(r), g(g), b(b), alpha(alpha) {}
    Pix() {/*do nothing*/}
};

struct Image {
    size_t img_H, img_W;
    Pix *data;
    Image(const size_t W, const size_t H): img_H(H), img_W(W) {
        this->data = new Pix[img_H*img_W];
    }
    Image(const size_t W, const size_t H, Pix *input_Data): img_H(H), img_W(W) {
        using std::memcpy;
        if (input_Data==NULL) throw std::runtime_error("received NULL pointer");
        this->data = new Pix[img_H*img_W];
        memcpy(this->data, input_Data, img_H*img_W*sizeof(this->data[0]));
    }
    Image(const Image &copy): img_H(copy.img_H), img_W(copy.img_W) {
        using std::memcpy;
        this->data = new Pix[img_H*img_W];
        memcpy(this->data, copy.data, img_H*img_W*sizeof(this->data[0]));
    }
    ~Image() {
        delete[] data;
    }
};

/*
 * Input:     pointer of Image object, operation mode, selected X, selected Y, pixel distance
 * Output:    A processed image
 * Mode:      0: process all data, 1: process adjacenting data
 * Exception: selected coordinate out of range, mode is not 0/1, image pointer is a NULL pointer
 */
class Eraser {
#define EPS 1e-12
    private:
        Image *data;
        int mode;
        int opX, opY;
        double diff;
        // Compute rgb diff between two pixels
        double pixDist(const Pix &a, const Pix &b) {
            double dr = a.r-b.r;
            double dg = a.g-b.g;
            double db = a.b-b.b;
            return std::sqrt(dr*dr+dg*dg+db*db);
        }
        void processWholeImg() {
            int imgW = this->data->img_W;
            int imgH = this->data->img_H;
            Pix targetCol = this->data->data[opY*imgW+opX];
            for (int i=0; i<imgH; ++i) {
                for (int j=0; j<imgW; ++j) {
                    if (pixDist(this->data->data[i*imgW+j], targetCol) < diff + EPS) this->data->data[i*imgW+j].alpha=0;
                }
            }
        }

        void processAdjacingPix() {
            using std::queue;
            using std::pair;
            using std::make_pair;
            const pair<int,int> dir[4] = { // X , Y diff
                pair<int,int>(1,0),
                pair<int,int>(0,1),
                pair<int,int>(-1,0),
                pair<int,int>(0,-1),
            };
            int imgW = this->data->img_W;
            int imgH = this->data->img_H;
            Pix targetCol = this->data->data[opY*imgW+opX];
            queue< pair<int,int> > que; // store <X, Y> pair
#define X first
#define Y second
            bool *vis = NULL;
            vis = new bool[imgW*imgH]; 
            // 另外開一個紀錄拜訪的陣列，
            // 因為我認為只靠 alpha == 0 來判斷是否走過，不太合邏輯（因為 alpha 可能本來就為 0）
            if (vis==NULL) throw std::runtime_error("visit table is NULL!");
            memset(vis, 0x00, sizeof(bool)*imgW*imgH);
            this->data->data[opY*imgW+opX].alpha = 0; // 不論如何，進入點必須去背
            vis[opY*imgW+opX] = true; // 標記為已拜訪
            que.push(make_pair(opX, opY));
            while(!que.empty()) {
                pair<int,int> inst = que.front(); que.pop();
                for (int i=0; i<4; ++i) {
                    pair<int,int> nC(inst.X+dir[i].X, inst.Y+dir[i].Y);
                    if (nC.X>=0 && nC.X<imgW && nC.Y>=0 && nC.Y<imgH && \
                        !vis[nC.Y*imgW+nC.X] && pixDist(this->data->data[nC.Y*imgW+nC.X], targetCol) < diff + EPS) {
                        this->data->data[nC.Y*imgW+nC.X].alpha = 0;
                        vis[nC.Y*imgW+nC.X] = true;
                        que.push(nC);
                    }
                }
            }
            delete[] vis; vis=NULL;
#undef X
#undef Y
        }
    public:
        Eraser( Image *imgData, int mode,\
                int selectX, int selectY, double diff=0.3) : \
            mode(mode), opX(selectX), opY(selectY), diff(diff) {
                this->data = imgData;
                if (this->data==NULL) throw std::runtime_error("pointer of image object is a NULL pointer");
                if (this->diff < 0.0) throw std::runtime_error("diff is negative!");
                if (this->mode!=0 && this->mode!=1) 
                    throw std::runtime_error("mode is not 0/1");
                if (this->opX < 0 || this->opX >= (int)data->img_W || this->opY < 0 || this->opY >= (int)data->img_H) 
                    throw std::runtime_error("selected coordinate out of range");
            }

        inline void run(void) {
            switch(this->mode) {
                case 0:
                    this->processWholeImg();
                    break;
                case 1:
                    this->processAdjacingPix();
                    break;
                default:
                    throw std::runtime_error("mode is not 0/1 (this shouldn't happen :( )");
                    break;
            }
        }
        ~Eraser() {
            data = NULL;
        }
#undef EPS
};

#include <iostream>

int main(void) {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Image *img=NULL;
    int x, y, type, diff;
    while(cin>>x>>y>>type>>diff) {
        int w, h;
        cin >> w >> h;
        img = new Image(w,h);
        int r,g,b,a;
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin >> r >> g >> b >> a;
                img->data[i*w+j] = Pix((uint8_t)r,(uint8_t)g,(uint8_t)b,(uint8_t)a);
            }
        }
        try {
            Eraser eraser(img, type, x, y, (double)diff);
            eraser.run();
        } catch (...) {} // not process
        cout << w << ' ' << h << '\n';
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                Pix out = img->data[i*w+j];
                if (j!=0) cout << ' ';
                cout << (int)out.r << ' ' << (int)out.g << ' ' << (int)out.b << ' ' << (int)out.alpha;
            }
            cout << endl;
        }
        delete img;
        img=NULL;
    }
    return 0;
}
