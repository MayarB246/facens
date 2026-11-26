public class Produto {
    private String nome;
    private double preco;
    private int quantidade;

    public Produto(String nome, double preco, int quantidade) {
        if (preco <= 0 || quantidade < 0) {
            throw new IllegalArgumentException("Dados inválidos");
        }
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    public Produto(){
    }

    public void darEntrada(int qtd) {
        if (qtd <= 0)
            throw new IllegalArgumentException("Quantidade inválida");
        quantidade += qtd;
    }

    public void darSaida(int qtd) {
        if (qtd <= 0 || qtd > quantidade)
            throw new IllegalArgumentException("Saída inválida");
        quantidade -= qtd;
    }

    public void reajustarPreco(double novoPreco) {
        if (novoPreco <= 0)
            throw new IllegalArgumentException("Preço inválido");
        preco = novoPreco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco){
        this.preco = preco;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQntd(int quantidade){
        this.quantidade = quantidade;
    }

    public double getValorEmEstoque(){
        return preco*quantidade;
    }

    public String toString(){
        return nome + " - RS" + String.format("%.2f", preco) + " - " + quantidade + " un.";
    }
}