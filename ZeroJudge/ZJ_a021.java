import java.util.Scanner;
class JAVA {
    public static void main(String args[]) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            String s1, s2, op;
            s1 = cin.next();
            op = cin.next();
            s2 = cin.next();
            //System.out.println(s1+" "+op+" "+s2);
            Bigint b1 = new Bigint(s1);
            Bigint b2 = new Bigint(s2);
            if(op.equals("+")) {
                System.out.println(b1.Add(b2));
            } else if(op.equals("-")) {
                if(b1.isLessThan(b2))
                    System.out.println("-"+b1.Diff(b2));
                else
                    System.out.println(b1.Diff(b2));
            } else if(op.equals("*")) {
                    System.out.println(b1.Mul(b2));
            } else if(op.equals("/")) {
                    System.out.println(b1.Div(b2));
            }
        }
    }
};
class Bigint {
    // private:
    private java.util.ArrayList<Integer> data; // Initialize in constructor
    private int dataLength;
    private void regulate () {
        int i=0;
        for (i=this.data.size()-1; i>=0 && this.data.get(i)==0; --i);
        this.dataLength = i+1;
    }
    private void strToBigint(String str) {
        char [] charArr = str.toCharArray();
        int strLen = str.length();
        for (int i=0, j=strLen-1; j>=0; ++i, --j) {
            this.data.add((int)(charArr[j]) - '0'); // push into array
        }
        this.dataLength = strLen;
        this.regulate();
    }
    private int _cmp(Bigint ext) {
        if ( this.dataLength > ext.dataLength ) return 1; // this > ext
        else if (this.dataLength < ext.dataLength ) return -1; // this < ext
        // same degree
        for (int i=this.dataLength-1; i>=0; --i) {
            if ( this.data.get(i) > ext.data.get(i) ) return 1; // this > ext
            else if ( this.data.get(i) < ext.data.get(i) ) return -1; // this < ext
            // else same
        }
        return 0; // same
    }

    // public:
    public String toString() {
        if (this.dataLength==0) return "0";
        String str="";
        for (int i=this.dataLength-1; i>=0; --i) {
            str = str + this.data.get(i);
        }
        return str;
        // not implement yet.
    }
    public double toDouble() {
        double val=0.0;
        for (int i=0; i<this.dataLength; ++i) {
            val*=10.0;
            val+=(this.data.get(i));
        }
        return val;
        // not implement yet
    }
    public boolean isGreaterThan (Bigint ext) {
        return this._cmp(ext) > 0;
    }
    public boolean isLessThan (Bigint ext) {
        return this._cmp(ext) < 0;
    }
    public boolean isEqualTo (Bigint ext) {
        return this._cmp(ext) == 0;
    }
    public boolean isNotEqualTo (Bigint ext) {
        return this._cmp(ext) != 0;
    }
    public boolean isGreaterThanOrEqulTo (Bigint ext) {
        return this._cmp(ext) >= 0;
    }
    public boolean isLessThanOrEqulTo (Bigint ext) {
        return this._cmp(ext) <= 0;
    }
    public Bigint Add (Bigint ext) {
        // not implement yet
        int maxLen = Math.max(ext.dataLength,this.dataLength);
        java.util.ArrayList<Integer> temp = new java.util.ArrayList<Integer> (maxLen+2);
        for (int t=maxLen+1; t>=0; --t) temp.add(0); // initialize maxLen elemnts
        for (int i=0; i<this.dataLength; ++i)
            temp.set(i,temp.get(i)+this.data.get(i));
        for (int i=0; i<ext.dataLength; ++i)
            temp.set(i,temp.get(i)+ext.data.get(i));
        for (int i=0; i<maxLen; ++i) {
            temp.set(i+1, temp.get(i+1)+temp.get(i)/10);
            temp.set(i, temp.get(i)%10 );
        }
        return new Bigint(temp);
    }
    public Bigint Diff (Bigint ext) {
        // not implement yet
        Bigint ref1=null, ref2=null;
        if (this.isLessThan(ext)) {
            ref1 = ext;
            ref2 = this;
        } else {
            ref1 = this;
            ref2 = ext;
        }
        int maxLen = ref1.dataLength;
        java.util.ArrayList<Integer> temp = new java.util.ArrayList<Integer> (maxLen+2);
        for (int t=maxLen+1; t>=0; --t) temp.add(0); // initialize maxLen elemnts
        for (int i=0; i<maxLen; ++i) {
            temp.set(i, (i<ref1.dataLength?ref1.data.get(i):0) - (i<ref2.dataLength?ref2.data.get(i):0));
        }
        for (int i=0; i<maxLen-1; ++i) {
            if ( temp.get(i) < 0 ) {
                temp.set(i+1, temp.get(i+1)-1);
                temp.set(i, temp.get(i)+10 );
            }
        }
        return new Bigint(temp);
    }

    public Bigint Mul (Bigint ext) {
        int maxLen = this.dataLength + ext.dataLength;
        java.util.ArrayList<Integer> temp = new java.util.ArrayList<Integer>(maxLen+2);
        for (int i=maxLen; i>=0; --i) temp.add(0);
        for (int i=0; i<this.dataLength; ++i) {
            for (int j=0; j<ext.dataLength; ++j) {
                temp.set ( i+j, temp.get(i+j) + this.data.get(i) * ext.data.get(j));
            }
        }
        for (int i=0; i<maxLen; ++i) {
            temp.set ( i+1, temp.get(i+1)+temp.get(i)/10);
            temp.set ( i  , temp.get(i)%10 );
        }
        return new Bigint(temp);
    }
    public Bigint mul_int (int k) {
        int maxLen = this.dataLength;
        java.util.ArrayList<Integer> temp = new java.util.ArrayList<Integer>(maxLen+2);
        for (int i=maxLen; i>=0; --i) temp.add(0);
        for (int i=0; i<maxLen; ++i) {
            temp.set(i, this.data.get(i)*k);
        }
        for (int i=0; i<maxLen; ++i) {
            temp.set(i+1, temp.get(i+1)+temp.get(i)/10);
            temp.set(i  , temp.get(i)%10 );
        }
        return new Bigint(temp);
    }
    public Bigint subBigint(int from, int to) { //exclusive-to
        java.util.ArrayList<Integer> temp = new java.util.ArrayList<Integer> (this.data.subList(from, to));
        return new Bigint(temp);
    }
    public void append(Bigint ext) {
        this.data.addAll(ext.data); //append
        this.dataLength += ext.dataLength;
    }
    public Bigint Div (Bigint ext) {
        int Len=this.dataLength - ext.dataLength;
        if(Len<0) return new Bigint("0");
        Bigint m = new Bigint(this);
        java.util.ArrayList<Integer> res=new java.util.ArrayList<Integer>();
        for(int i=0; i<=Len; ++i) res.add(0);
        for(int i=Len; i>=0; --i) {
            for(int q=9; q>0; --q) {
                Bigint t1 = ext.mul_int(q);
                Bigint t2 = m.subBigint(i, m.dataLength);
                if( t1.isLessThanOrEqulTo(t2)) {
                    t1 = t2.Diff(t1);
                    m = m.subBigint(0,i);
                    m.append(t1);
                    res.set(i,q);
                    break;
                }
            }
        }
        return new Bigint(res);
    }
    public Bigint Mod (Bigint ext) {
        int Len=this.dataLength - ext.dataLength;
        Bigint m = new Bigint(this);
        if(Len<0) return m;
        for(int i=Len; i>=0; --i) {
            for(int q=9; q>0; --q) {
                Bigint t1 = ext.mul_int(q);
                Bigint t2 = m.subBigint(i, m.dataLength);
                if( t1.isLessThanOrEqulTo(t2)) {
                    t1 = t2.Diff(t1);
                    m = m.subBigint(0,i);
                    m.append(t1);
                    break;
                }
            }
        }
        return m;
    }
    // constructor:
    Bigint(Bigint target) {
        this.dataLength = target.dataLength;
        this.data = new java.util.ArrayList<Integer>( target.data);
    }
    Bigint(String str) {
        // not implment yet
        this.data = new java.util.ArrayList<Integer> ();
        this.strToBigint(str);
    }
    Bigint(java.util.ArrayList<Integer> arr) {
        this.data = arr;
        this.dataLength = arr.size();
        this.regulate();
    }
};
