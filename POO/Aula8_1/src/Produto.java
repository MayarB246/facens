public class Produto {
    private int codigo;
    private String nome;
    private double preco;

    public Produto(int codigo, String nome, double preco){
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
    }

    public void setPreco(double novoPreco){
        preco = novoPreco;
    }

    public double getPreco(){
        return this.preco;
    }
}
