import java.util.*;

public class Main {
    public static void main(String args[]) {
        HashMap<String, Collection<String> > groups = new HashMap<String, Collection<String> >(); // group-email, emails
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt(); scanner.nextLine();
        for (int i=0; i<cases; ++i) {
            String realemail = scanner.nextLine();
            String emailArray[] = realemail.toLowerCase().split("\\@");
            String domain = emailArray[1], account = emailArray[0];
            String newid;
            //System.err.println( account + "@" + domain);
            if (domain.equals("bmail.com")) {
                account = account.replaceAll("\\.","");
                String prefix;
                if (account.indexOf('+')>=0)
                    prefix = account.split("\\+")[0];
                else
                    prefix = account;
                newid  = prefix + "@" + "bmail.com";
            } else {
                newid = account + "@" + domain;
            }
            //System.out.println(newid);
            if (groups.containsKey(newid)) {
                ArrayList<String> temp = (ArrayList<String>)(groups.get(newid));
                temp.add(realemail);
                groups.put(newid, temp);
            } else {
                ArrayList<String> temp = new ArrayList<String>();
                temp.add(realemail);
                groups.put(newid, (Collection<String>)temp);
            }
        }
        System.out.println(groups.size());
        for (HashMap.Entry<String, Collection<String> > gs : groups.entrySet()) {
            ArrayList<String> temp = (ArrayList<String>)gs.getValue();
            System.out.print(temp.size());
            for (String acc : temp) {
                System.out.print(" " + acc);
            }
            System.out.println("");
        }
    }
}
