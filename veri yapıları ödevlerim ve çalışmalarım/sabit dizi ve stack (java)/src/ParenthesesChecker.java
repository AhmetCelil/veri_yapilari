import java.util.Scanner;

public class ParenthesesChecker {

    static class Node {  // node yapısı (tutulacak dataların türlerin ve pointerı) tanımlanır
        char data; // her bir nodun daya kısmı her bir parantez için
        Node next; // node a ait pointer

        public Node(char data) {
            this.data = data;  // structın data kısmı için atam işlemi yapılıyor
            this.next = null;  // başlangıçta node pointer herhangi biryeri işaret etmez
        }
    }

    static class Stack { // yıgın veri yapısı kur
        Node top;    // yığını en üst kısmı
        int indis = 1;  // node un indisi

        public Stack() {
            this.top = null;
            indis++;
        }

        public void push(char data) {  // listeye nodelar ekle
            Node newNode = new Node(data);
            newNode.next = top;
            top = newNode;
        }

        public boolean isEmpty() { // yığnı sıfırla
            return top == null;
        }

        public char pop() {
            if (isEmpty()) {
                return '0';
            } else {
                char poppedItem = top.data;
                top = top.next;
                return poppedItem;
            }
        }
    }

    public static boolean isBalanced(String str) {
        Stack stack = new Stack();
        for (int i = 0; i < str.length(); i++) { // girilen parantez dizisinin boyutuna kadar tara

            char currentChar = str.charAt(i); //tek tek parantez işaretleri alınır

            if (currentChar == '(' || currentChar == '{' || currentChar == '[') {    // alınan parantezlerin tipi
                stack.push(currentChar);       // eklencek eleman parantez açılımı ile başlıyorsa push la

            } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {

                if (stack.isEmpty()) {return false;} // eklenecek eleman parantez kapatma ile başlarsa 0 döndür(false)

                else {   // eklenen eleman parantez kapama ise ve dizinin ilk elemanı  değilse
                    char poppedItem = stack.pop();   // en üstteki elemanın alttakilerle eşleniği var mı diye bakılır

                    if (currentChar == ')' && poppedItem != '(') {
                        return false;
                    } else if (currentChar == '}' && poppedItem != '{') {
                        return false;
                    } else if (currentChar == ']' && poppedItem != '[') {
                        return false;
                    }
                }
            }
        }
        return stack.isEmpty(); // en üstteki eleman boş
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while(true) { // birden fazla kontrol için

            System.out.print("parantez stringi giriniz... ");
            String parantezString = scanner.nextLine();   // parantez stringi al örn:([]{})[]


            if (isBalanced(parantezString)) {  // alınan stringi eşli olup olmadığını kontrol et
                System.out.println("parantez eşlidir");
            } else {
                System.out.println("parantez eşli değil");
            }
        }
    }
}