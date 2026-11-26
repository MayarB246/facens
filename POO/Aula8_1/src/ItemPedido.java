public class ItemPedido {
    private Produto prod;
    private int quant;
    private double precoUnit;
    
    private ItemPedido(Produto prod, int quant, double precoUnit){
        this.prod = prod;
        this.quant = quant;
        this.precoUnit = prod.getPreco();
    }

}
