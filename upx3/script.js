let chart;
const ctx = document.getElementById('meuGrafico').getContext('2d');

// Inicialização do Gráfico
function iniciarGrafico() {
    chart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: [],
            datasets: [{
                label: 'Litros Consumidos',
                data: [],
                borderColor: '#3b82f6',
                backgroundColor: 'rgba(59, 130, 246, 0.1)',
                borderWidth: 3,
                fill: true,
                tension: 0.4, // Curva suave na linha
                pointRadius: 0
            }]
        },
        options: {
            responsive: true,
            plugins: { legend: { display: false } },
            scales: {
                x: { grid: { display: false }, ticks: { color: '#a1a1aa' } },
                y: { grid: { color: '#27272a' }, ticks: { color: '#a1a1aa' } }
            }
        }
    });
}

async function atualizarDashboard() {
    try {
        const response = await fetch('http://127.0.0.1:8000/');
        const historico = await response.json(); // Lembre-se: o Python está mandando invertido!

        if (historico.length > 0) {
            const atual = historico[0]; // O mais recente no topo

            // 1. Atualiza Cards
            document.getElementById('val-litros').innerText = `${atual.litros_total.toFixed(2)} L`;
            document.getElementById('val-tempo').innerText = `${atual.tempo_ligado_s}s`;
            document.getElementById('val-energia').innerText = `${atual.energia_kwh.toFixed(3)} kWh`;
            document.getElementById('val-custo').innerText = `R$ ${atual.custo_rs.toFixed(2)}`;

            // 2. Atualiza Tabela (Novo no Topo)
            const tabela = document.getElementById('tabela-corpo');
            tabela.innerHTML = historico.slice(0, 10).map(d => `
                <tr>
                    <td>${d.tempo_ligado_s}s</td>
                    <td>${d.litros_total.toFixed(2)}</td>
                    <td>R$ ${d.custo_rs.toFixed(2)}</td>
                    <td><span class="status-badge">Ativo</span></td>
                </tr>
            `).join('');

            // 3. Atualiza Gráfico (Precisa estar na ordem cronológica)
            const dadosCronologicos = [...historico].reverse();
            chart.data.labels = dadosCronologicos.map(d => `${d.tempo_ligado_s}s`);
            chart.data.datasets[0].data = dadosCronologicos.map(d => d.litros_total);
            chart.update('none'); // Update sem animação para ser fluido
        }
    } catch (error) {
        console.error("Erro ao buscar dados:", error);
    }
}

iniciarGrafico();
setInterval(atualizarDashboard, 2000);