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
| `script.js`     | JS         | Interatividade, validação de formulários, toggle FAQ e mascote animado.  |

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
}```
Exemplo de hover animado em cards:

```css
Sempre exibir os detalhes

Copiar código
.course-card:hover {
  transform: translateY(-10px);
  box-shadow: 0 10px 20px rgba(0,0,0,0.3);
}```
Exemplo de fade-in ao rolar a página:

```css
Sempre exibir os detalhes

Copiar código
.fade-in {
  opacity: 0;
  transform: translateY(20px);
  transition: opacity 0.6s ease-out, transform 0.6s ease-out;
}

.fade-in.appear {
  opacity: 1;
  transform: translateY(0);
}```
🖼️ Hero Section
Título chamativo: “Aprenda Programação do Zero ao Avançado”

Subtítulo motivador com CTA “Ver Cursos”

Mascote animado segue o mouse

Botão CTA com scroll suave até cursos

🏫 Cursos e Como Funciona
20 cursos disponíveis, incluindo HTML, CSS, JS, Python, React, Node.js, Java, PHP, C++, TypeScript e mais

Cada curso possui ícone, título, descrição e botão de ação

Seção “Como Funciona” explica a metodologia: aulas práticas, projetos, mentorias e certificação
"""