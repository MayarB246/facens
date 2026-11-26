public class Cachorro extends Animal{
    private boolean temPulga;

    public Cachorro(String nome, int idade, boolean temPulga){
        super(nome, idade);
        this.temPulga = temPulga;
    }

    public boolean temPulgaCach(){
        return temPulga;
    }

    @Override 
    public void emitirSom(){
        System.out.println("Au Au!!!");
    }

    public void imprimir(){
        System.out.println("Nome:" + getNome()); //nao consigo acessar nome por ser private (Animal)
        System.out.println("Idade:" + idade); //consigo acessar idade por ser protected (Animal)
        System.out.println("Tem pulga?"+temPulgaCach());
    }
}
