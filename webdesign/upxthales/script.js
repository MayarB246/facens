// === VARIÁVEIS GLOBAIS ===
let lishoos = 0;

const lishooDisplay = document.getElementById("lishoo-count");
const addCoinsBtn = document.getElementById("add-coins-btn");
const rewardListContainer = document.querySelector(".reward-list");

const rewardDetailsSection = document.getElementById("reward-details");
const imagesContainer = document.getElementById("images-container");
const rewardDescription = document.getElementById("reward-description");
const rewardCost = document.getElementById("reward-cost");
const collectBtn = document.getElementById("collect-btn");
const closeDetailsBtn = document.getElementById("close-details-btn");

const animationContainer = document.getElementById("animation-container");
const animationImg = document.getElementById("animation-img");

// === LISTA DE PRÊMIOS ===
const rewards = [
  {
    name: "Plante uma arvore",
    cost: 5,
    description: "Nós da EcoWin plantamos uma arvore em lugares pré-determinados. As arvores plantadas podem ser ipê ou pau-brasil. Valores estimado: R$ 100",
    images: ["assets/a1.jpeg", "assets/a2.jpeg", "assets/a3.jpeg"]
  },
  {
    name: "Garrafa térmica reciclada",
    cost: 30,
    description: "Capacidade de 750ml. Feita com aluminio reciclado. Cor: verde, laranja ou branca. Valor estimado: R$ 45.",
    images: ["assets/Garrafa 1.jpeg", "assets/Garrafa 2.jpeg", "assets/Garrafa 3.jpeg"]
  },
  {
    name: "Bicicleta Aro 29",
    cost: 75,
    description: "Bicicleta Aro 29, 24 velocidades. Feita de aluminio e plastico reciclado. Cor: preto com detalhes vermehos. Valor estimado: R$ 2000.",
    images: ["assets/b1.jpeg", "assets/b2.jpeg", "assets/b3.jpeg"]
  },
  {
    name: "Ecobag de Algodão Orgânico",
    cost: 20,
    description: "Bolsa resistente com alças reforçadas. Cor: branca. Valor estimado: R$ 100.",
    images: ["assets/eco1.jpg", "assets/eco2.jpeg", "assets/eco3.jpeg"]
  },
  {
    name: "Filtro de Barro Sustentável",
    cost: 40,
    description: "Filtro de barro com capacidade de 7L. Cor: marrom com detalhes vermelhos. Valor estimado: R$ 300.",
    images: ["assets/fb1.jpeg", "assets/fb2.jpeg", "assets/fb3.jpeg"]
  }
];

// === INVENTÁRIO DO USUÁRIO ===
const userInventory = {};
rewards.forEach(r => userInventory[r.name] = 0);

// === ATUALIZA CONTADOR DE MOEDAS ===
function updateLishoosDisplay() {
  lishooDisplay.textContent = lishoos;
}

// === ADICIONA MOEDAS COM BASE NO LIXO RECICLADO ===
addCoinsBtn.addEventListener("click", () => {
  const input = prompt("Quantos kg de lixo você reciclou?");
  const kg = parseInt(input);
  if (!isNaN(kg) && kg > 0) {
    lishoos += kg;
    updateLishoosDisplay();
    renderRewards();
    triggerAnimation("coins");
  } else {
    alert("Por favor, insira um valor válido em kg.");
  }
});

// === RENDERIZA OS PRÊMIOS NA TELA ===
function renderRewards() {
  rewardListContainer.innerHTML = "";
  rewards.forEach((reward, index) => {
    const card = document.createElement("div");
    card.className = "reward-card";

    // Imagem principal do prêmio (primeira do array)
    const imageHTML = `<img src="${reward.images[0]}" alt="${reward.name}" class="reward-thumbnail" />`;

    card.innerHTML = `
      <h3>${reward.name}</h3>
      ${imageHTML}
      <p>Custa ${reward.cost} lishoos</p>
      <p>Coletado: ${userInventory[reward.name]}/2</p>
    `;
    card.onclick = () => showRewardDetails(index);
    rewardListContainer.appendChild(card);
  });
}


// === EXIBE DETALHES DO PRÊMIO EM TELA CHEIA ===
function showRewardDetails(index) {
  const reward = rewards[index];
  rewardDetailsSection.classList.remove("hidden");
  rewardDetailsSection.classList.add("fullscreen");

  imagesContainer.innerHTML = "";
  reward.images.forEach(src => {
    const img = document.createElement("img");
    img.src = src;
    img.alt = reward.name;
    imagesContainer.appendChild(img);
  });

  rewardDescription.textContent = reward.description;
  rewardCost.textContent = `Custo: ${reward.cost} lishoos`;
  collectBtn.onclick = () => collectReward(index);
}

// === RESGATA O PRÊMIO ===
function collectReward(index) {
  const reward = rewards[index];

  if (lishoos < reward.cost) {
    alert("Você não tem lishoos suficientes.");
    return;
  }

  if (userInventory[reward.name] >= 2) {
    alert(`✅ Você já coletou o máximo de "${reward.name}".`);
    return;
  }

  userInventory[reward.name]++;
  lishoos -= reward.cost;
  updateLishoosDisplay();
  renderRewards();
  triggerAnimation("gift");

  if (userInventory[reward.name] === 2) {
    alert(`🎉 Prêmio "${reward.name}" coletado com sucesso!`);
  }

  closeRewardDetails();
}

// === FECHA DETALHES DO PRÊMIO ===
function closeRewardDetails() {
  rewardDetailsSection.classList.add("hidden");
  rewardDetailsSection.classList.remove("fullscreen");
}

// === ANIMAÇÃO DO PLANETA TERRA ===
function triggerAnimation(type) {
  animationContainer.classList.remove("hidden");

  if (type === "coins") {
    animationImg.src = "earth-coins.gif"; // imagem cartoon do planeta entregando moedas
  } else if (type === "gift") {
    animationImg.src = "earth-gift.gif"; // imagem cartoon do planeta entregando presente
  }

  setTimeout(() => {
    animationContainer.classList.add("hidden");
  }, 2000);
}

// === EVENTO PARA FECHAR DETALHES ===
closeDetailsBtn.addEventListener("click", closeRewardDetails);

// === INICIALIZAÇÃO ===
updateLishoosDisplay();
renderRewards();
