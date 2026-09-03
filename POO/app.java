public class app{
    public static void main(String[] args){
        calcul cal = new calcul();
        int op = cal.opcao();
        float res = cal.calcular(op);
        cal.finalizar(res);
    }
}