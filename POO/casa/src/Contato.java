public class Contato {
    private String nome, ender, email, num;

    public Contato(String nome, String ender, String email, String num){
        this.nome = nome;
        this.ender = ender;
        this.email = email;
        this.num = num;
    }
    
    public Contato(){
        this.nome = "";
        this.ender = "";
        this.email = "";
        this.num = "";
    }

    public String getNome(){
        return nome;
    }
    public void setNome(String nome){
        this.nome = nome;
    }

    public String getEnder(){
        return ender;
    }
    public void setEnder(String ender){
        this.ender = ender;
    }

    public String getEmail(){
        return email;
    }
    public void setEmail(String email){
        this.email = email;
    }

    public String getNum(){
        return num;
    }
    public void setNum(String num){
        this.num = num;
    }

    public void mostra(){
        System.out.println("Nome: "+nome);
        System.out.println("\nEndereco: "+ender);
        System.out.println("\nE-mail: "+email);
        System.out.println("\nNumero: "+num);
        System.out.println("\n\n-------------------------\n");
    }
}