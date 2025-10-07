# 💻 TechCode Academy - Cursos de Programação

Bem-vindo(a) ao projeto **TechCode Academy**, uma plataforma de ensino de programação com visual moderno **dark** e interatividade completa.  
Este README detalha **todas as funcionalidades implementadas**, incluindo **HTML, CSS e JS**, animações e seções adicionais.

---

## 🗂 Estrutura do Projeto

O projeto é composto por três arquivos principais:

| Arquivo         | Tipo        | Descrição                                                                 |
|-----------------|------------|---------------------------------------------------------------------------|
| `index.html`    | HTML       | Estrutura da página, seções, cursos, login, FAQ e rodapé expandido.      |
| `style.css`     | CSS        | Estilo dark, layout responsivo, animações, mascote e interações visuais. |
| `script.js`     | JavaScript | Interações, animações, validações de formulários e mascote animado.      |

---

## 📌 Seções da Página

| Seção                     | Descrição                                                                 |
|----------------------------|---------------------------------------------------------------------------|
| **Hero**                  | Apresenta a plataforma, com mascote animado, texto chamativo e botão.    |
| **Cursos**                | Lista de 20 cursos com imagens, títulos e botões de ação.                |
| **Como Funciona**         | Explicação de metodologia e funcionamento da plataforma.                 |
| **Empresa**               | Informações sobre a empresa, missão, visão e equipe.                     |
| **Planos de Estudo**      | Diferentes planos de assinatura com destaques e benefícios.              |
| **Login / Registro**      | Área de usuário para login e registro com validação em JS.               |
| **FAQ**                   | Perguntas frequentes com toggle de respostas animadas.                   |
| **Contato**               | Formulário de contato com validação e alerta ao enviar.                  |
| **Rodapé Expandido**       | Links, informações de contato e redes sociais, com estilo dark.          |

---

## 🎨 CSS e Layout

O CSS foi desenvolvido para **visual dark moderno**, responsivo, com **Flexbox e Grid**. Principais características:

- **Hero Section** com mascote animado
- **Cursos em grid responsivo**  
- **Login e Registro** estilizados, card centralizado  
- **FAQ toggle** com animação de abrir e fechar  
- **Rodapé expandido** com 4 colunas de informação  
- **Mascote animado** segue o mouse suavemente  

Exemplo de classe:

```css
.mascote {
  position: fixed;          
  width: 60px;              
  pointer-events: none;     
  z-index: 1000;            
  transition: transform 0.1s linear;
}
