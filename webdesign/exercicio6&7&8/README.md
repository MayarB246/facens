# 💻 TechCode Academy - Plataforma de Cursos de Programação

Bem-vindo(a) à **TechCode Academy**, uma plataforma moderna de ensino de programação, com foco em **interatividade, aprendizado prático e experiência do usuário**.  
Nosso objetivo é tornar o aprendizado acessível para iniciantes, intermediários e profissionais, oferecendo cursos atualizados em diversas linguagens de programação.

---

## 🌐 Sobre o Site

**TechCode Academy** é uma plataforma educacional online, com visual **dark moderno**, responsividade completa e mascote animado que interage com o usuário.  

Principais características:

- Ensinar programação de forma prática e intuitiva  
- Interface interativa com mascote e animações  
- Compatível com desktop, tablets e smartphones  
- Cursos atualizados com projetos, exercícios e certificações  
- Área de login/registro e formulários de contato  

---

## 🗂 Estrutura do Projeto

| Arquivo         | Tipo        | Descrição                                                                 |
|-----------------|------------|---------------------------------------------------------------------------|
| `index.html`    | HTML       | Estrutura completa do site, seções, cursos, login, FAQ, rodapé expandido. |
| `style.css`     | CSS        | Layout dark, responsivo, animações, hover nos cards e mascote animado.    |
| `script.js`     | JavaScript | Interatividade, validação de formulários, toggle FAQ e mascote animado.  |

---

## 🏗️ Estrutura do HTML

O site é dividido em seções:

| Seção                     | Descrição                                                                 |
|----------------------------|---------------------------------------------------------------------------|
| Hero                       | Introdução chamativa com mascote e botão CTA.                             |
| Cursos                     | Lista de 20 cursos com ícones, títulos, descrições e botões.             |
| Como Funciona              | Explicação da metodologia da plataforma e funcionamento.                 |
| Empresa                    | Missão, visão, equipe e valores da TechCode Academy.                     |
| Planos de Estudo           | Planos de assinatura com destaques e benefícios.                          |
| Login / Registro           | Área de usuário com toggle entre login e registro e validação JS.         |
| FAQ                        | Perguntas frequentes com toggle animado e respostas ocultas.              |
| Contato                    | Formulário funcional com validação JS e alerta de envio.                  |
| Rodapé Expandido           | Contato, links rápidos, redes sociais e informações legais.               |

---

## 🎨 CSS e Layout

O CSS é voltado para **design moderno e dark**, com responsividade e animações:

- Dark mode elegante  
- Flexbox e Grid para cards de cursos e seções  
- Cards animados com hover e transições suaves  
- Hero chamativo com botão CTA e mascote animado  
- Rodapé expandido com quatro colunas e formulário adicional  

Exemplo de CSS do mascote:

```css
.mascote {
  position: fixed;
  width: 60px;
  pointer-events: none;
  z-index: 1000;
  transition: transform 0.1s linear;
}

---

## ⚡ Funcionalidades em JavaScript

### Principais funções implementadas

| Função / Seção                | Descrição                                                                 |
|--------------------------------|---------------------------------------------------------------------------|
| Mascote segue o mouse          | Mascote animado acompanha o cursor suavemente.                            |
| Piscar do mascote              | Piscar leve do mascote a cada 3 segundos.                                 |
| Scroll suave                   | Rolagem suave ao clicar nos links do menu.                                 |
| Toggle FAQ                     | Expandir e recolher respostas das perguntas frequentes.                   |
| Toggle Perguntas Extras        | Perguntas secundárias aparecem apenas após clicar em “Ver mais”.           |
| Login / Registro               | Validação básica, toggle entre formulários e alert de envio.              |
| Formulário de Contato          | Validação de campos obrigatórios e alerta ao enviar.                      |
| Hover animado nos cursos       | Cards de cursos elevam e destacam ao passar o mouse.                      |
| Fade-in ao rolar a página      | Cards e seções aparecem com animação suave conforme o scroll.             |
| Destaque de plano profissional | Pulsar leve para chamar atenção ao usuário.                                |

---

### Exemplos de JS usados

**Mascote seguindo o mouse:**

```javascript
const mascote = document.querySelector(".mascote");
document.addEventListener("mousemove", e => {
  mascote.style.transform = `translate(${e.clientX}px, ${e.clientY}px)`;
});
