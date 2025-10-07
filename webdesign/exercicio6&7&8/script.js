// ============================
// MENU MOBILE
// ============================
const menuBtn = document.querySelector(".menu-btn");
const navUl = document.querySelector(".navbar ul");

menuBtn.addEventListener("click", () => {
  navUl.classList.toggle("active");
});

// ============================
// SCROLL SUAVE PARA LINKS
// ============================
const navLinks = document.querySelectorAll(".navbar ul li a");

navLinks.forEach(link => {
  link.addEventListener("click", function(e) {
    e.preventDefault();
    const targetId = this.getAttribute("href").substring(1);
    const targetSection = document.getElementById(targetId);
    targetSection.scrollIntoView({ behavior: "smooth", block: "start" });
    if(navUl.classList.contains("active")) {
      navUl.classList.remove("active");
    }
  });
});

// ============================
// ANIMAÇÃO HERO SECTION
// ============================
const heroContent = document.querySelector(".hero-content");
window.addEventListener("load", () => {
  heroContent.style.opacity = 0;
  heroContent.style.transform = "translateY(50px)";
  setTimeout(() => {
    heroContent.style.transition = "all 1s ease";
    heroContent.style.opacity = 1;
    heroContent.style.transform = "translateY(0)";
  }, 500);
});

// ============================
// ANIMAÇÃO DAS ILUSTRAÇÕES
// ============================
const illustrations = document.querySelectorAll(".illustration");
window.addEventListener("scroll", () => {
  const triggerBottom = window.innerHeight / 5 * 4;
  illustrations.forEach(ill => {
    const illTop = ill.getBoundingClientRect().top;
    if(illTop < triggerBottom) {
      ill.style.opacity = 1;
      ill.style.transform = "translateY(0)";
      ill.style.transition = "all 0.8s ease";
    } else {
      ill.style.opacity = 0;
      ill.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// HOVER ANIMADO NOS CURSOS
// ============================
const courseCards = document.querySelectorAll(".course-card");
courseCards.forEach(card => {
  card.addEventListener("mouseenter", () => {
    card.style.transform = "scale(1.05)";
    card.style.transition = "all 0.3s ease";
    card.style.boxShadow = "0 10px 20px rgba(0,0,0,0.5)";
  });
  card.addEventListener("mouseleave", () => {
    card.style.transform = "scale(1)";
    card.style.boxShadow = "none";
  });
});

// ============================
// BOTÃO EXPLORAR CURSOS
// ============================
const exploreBtn = document.getElementById("explore-btn");
const coursesSection = document.getElementById("cursos");

exploreBtn.addEventListener("click", () => {
  coursesSection.scrollIntoView({ behavior: "smooth" });
});

// ============================
// FUNÇÃO DE APARECER COM SCROLL (GLOBAL PARA OUTRAS SEÇÕES)
// ============================
const fadeElements = document.querySelectorAll(".fade-in");
window.addEventListener("scroll", () => {
  const triggerPoint = window.innerHeight / 5 * 4;
  fadeElements.forEach(el => {
    const elTop = el.getBoundingClientRect().top;
    if(elTop < triggerPoint) {
      el.style.opacity = 1;
      el.style.transform = "translateY(0)";
      el.style.transition = "all 0.8s ease";
    } else {
      el.style.opacity = 0;
      el.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// ANIMAÇÃO SCROLL CURSOS EXTENDIDOS
// ============================
const extendedCourses = document.querySelectorAll(".courses-grid-extended .course-card");

window.addEventListener("scroll", () => {
  const triggerBottom = window.innerHeight / 5 * 4;
  extendedCourses.forEach(course => {
    const courseTop = course.getBoundingClientRect().top;
    if(courseTop < triggerBottom) {
      course.style.opacity = 1;
      course.style.transform = "translateY(0)";
      course.style.transition = "all 0.8s ease";
    } else {
      course.style.opacity = 0;
      course.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// ANIMAÇÃO COMO FUNCIONA
// ============================
const steps = document.querySelectorAll(".step");
window.addEventListener("scroll", () => {
  const triggerPoint = window.innerHeight / 5 * 4;
  steps.forEach(step => {
    const stepTop = step.getBoundingClientRect().top;
    if(stepTop < triggerPoint) {
      step.style.opacity = 1;
      step.style.transform = "translateY(0)";
      step.style.transition = "all 0.8s ease";
    } else {
      step.style.opacity = 0;
      step.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// ANIMAÇÃO EMPRESA
// ============================
const companyItems = document.querySelectorAll(".company-content > div");
window.addEventListener("scroll", () => {
  const triggerPoint = window.innerHeight / 5 * 4;
  companyItems.forEach(item => {
    const itemTop = item.getBoundingClientRect().top;
    if(itemTop < triggerPoint) {
      item.style.opacity = 1;
      item.style.transform = "translateY(0)";
      item.style.transition = "all 0.8s ease";
    } else {
      item.style.opacity = 0;
      item.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// ANIMAÇÃO ESTATÍSTICAS
// ============================
const stats = document.querySelectorAll(".stat h3");
let statsAnimated = false;

window.addEventListener("scroll", () => {
  const statsSection = document.querySelector(".stats-section");
  const sectionTop = statsSection.getBoundingClientRect().top;
  if(sectionTop < window.innerHeight - 100 && !statsAnimated) {
    stats.forEach(stat => {
      const finalValue = parseInt(stat.textContent.replace(/\D/g, ""));
      let current = 0;
      const increment = Math.ceil(finalValue / 100);
      const counter = setInterval(() => {
        current += increment;
        if(current >= finalValue) {
          stat.textContent = "+" + finalValue;
          clearInterval(counter);
        } else {
          stat.textContent = "+" + current;
        }
      }, 20);
    });
    statsAnimated = true;
  }
});

// ============================
// ANIMAÇÃO BLOG
// ============================
const blogCards = document.querySelectorAll(".blog-card");
window.addEventListener("scroll", () => {
  const triggerBottom = window.innerHeight / 5 * 4;
  blogCards.forEach(card => {
    const cardTop = card.getBoundingClientRect().top;
    if(cardTop < triggerBottom) {
      card.style.opacity = 1;
      card.style.transform = "translateY(0)";
      card.style.transition = "all 0.8s ease";
    } else {
      card.style.opacity = 0;
      card.style.transform = "translateY(50px)";
    }
  });
});

// ============================
// LOGIN / REGISTRO TOGGLE
// ============================
const loginCard = document.querySelector(".login-card");
const registerCard = document.querySelector(".register-card");
const showRegister = document.getElementById("showRegister");
const showLogin = document.getElementById("showLogin");

showRegister.addEventListener("click", () => {
  loginCard.style.display = "none";
  registerCard.style.display = "block";
});

showLogin.addEventListener("click", () => {
  loginCard.style.display = "block";
  registerCard.style.display = "none";
});

// ============================
// FAQ TOGGLE
// ============================
const faqItems = document.querySelectorAll(".faq-item");
faqItems.forEach(item => {
  item.addEventListener("click", () => {
    const answer = item.querySelector(".faq-answer");
    const isVisible = answer.style.display === "block";
    faqItems.forEach(i => i.querySelector(".faq-answer").style.display = "none");
    answer.style.display = isVisible ? "none" : "block";
  });
});

// ============================
// VALIDAR FORMULÁRIOS LOGIN/REGISTRO
// ============================
document.getElementById("loginForm").addEventListener("submit", e => {
  e.preventDefault();
  alert("Login efetuado com sucesso!");
});

document.getElementById("registerForm").addEventListener("submit", e => {
  e.preventDefault();
  alert("Registro realizado com sucesso!");
});

document.getElementById("footerContactForm").addEventListener("submit", e => {
  e.preventDefault();
  alert("Mensagem enviada! Entraremos em contato em breve.");
});

// ============================
// MASCOTE SUAVE SEGUINDO O MOUSE
// ============================
const mascote = document.getElementById("mascoteImg");

// Inicializa posição
let mouseX = 0, mouseY = 0;
let mascoteX = 0, mascoteY = 0;

// Atualiza a posição do mouse
document.addEventListener("mousemove", e => {
  mouseX = e.clientX;
  mouseY = e.clientY;
});

// Função para animar o mascote suavemente
function animateMascote() {
  // Interpolação suave (lerp)
  mascoteX += (mouseX - mascoteX - mascote.width / 2) * 0.1;
  mascoteY += (mouseY - mascoteY - mascote.height / 2) * 0.1;

  // Aplica transformação
  mascote.style.transform = `translate(${mascoteX}px, ${mascoteY}px)`;

  // Chama a função no próximo frame
  requestAnimationFrame(animateMascote);
}

// Inicia a animação
animateMascote();

// ============================
// MASCOTE PISCANDO LEVEMENTE
// ============================
setInterval(() => {
  mascote.style.opacity = 0.7; // fica mais transparente
  setTimeout(() => {
    mascote.style.opacity = 1; // volta ao normal
  }, 300); // duração do "piscar"
}, 3000); // intervalo entre piscadas (3 segundos)
