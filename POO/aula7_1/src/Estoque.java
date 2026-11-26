import java.util.*;

public class Estoque {
    private ArrayList<Produto> produtos = new ArrayList<>();
    Scanner in = new Scanner(System.in);

    public boolean adicionar(Produto p) {
        boolean existe = false;
        if (p == null){
            return false;
        }

        for(Produto prod : produtos)
            if(prod.getNome().equalsIgnoreCase(p.getNome())){
                existe = true;
        }

        if (existe){
            System.err.println("Produto ja existente!!!");
        }
        else{
            produtos.add(p);
            return true;
        }
        return false;
    }

    public ArrayList<Produto> abaixoDoMinimo(int minimo) {
        ArrayList<Produto> resultado = new ArrayList<>();
        for (Produto p : produtos) {
            if (p.getQuantidade() < minimo) {
                resultado.add(p);
            }
        }
        return resultado;
    }

    public Produto buscar(String nome){
        for (Produto p : produtos){
            if(p.getNome() == nome){
                return p;
            }
        }
        return null;
    }

    public boolean remover(String nome){
        int i=0;
        for(Produto p : produtos){
            if(p.getNome() == nome){
                produtos.remove(i);
                return true;
            }
            i++;
        }
        return false;
    }
}