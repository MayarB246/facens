public class App {
    public static void main(String[] args) throws Exception {
        folha folha1 = new folha();

        Funcionario f = new Funcionario("Ana S.", "F001", 3000);
        folha1.adicionar(f);
        Funcionario p = new Professor("Bruno L.", "P001", 2000, 80, 45);
        folha1.adicionar(p);
        Funcionario c = new Coordenador("Carla M.", "C001", 6000, 0.25);
        folha1.adicionar(c);
        
        System.out.println("Somatoria dos salarios: RS"+ folha1.calcTotal());
        folha1.listar();
    }
}
