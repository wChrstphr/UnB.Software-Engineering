# Resumo da Disciplina Fundamentos da Arquitetura de Computadores (FAC)

# Índice  
1. [Hierarquia de Memória](#1-hierarquia-de-memória)  
2. [Memória Virtual](#2-memória-virtual)  
3. [Registradores](#3-registradores)  
4. [Cache](#4-cache)  
5. [RAM](#5-ram)  
6. [SSD (Unidade de Estado Sólido)](#6-ssd-unidade-de-estado-sólido)  
7. [Barramentos](#7-barramentos)  
8. [Controladores de Memória](#8-controladores-de-memória)  
9. [Mapeamento de Memória](#9-mapeamento-de-memória)  
10. [Paginação](#10-paginação)  
11. [RISC (Reduced Instruction Set Computer)](#11-risc-reduced-instruction-set-computer)  
12. [CISC (Complex Instruction Set Computer)](#12-cisc-complex-instruction-set-computer)  
13. [Uniciclo](#13-uniciclo)  
14. [Multiciclo](#14-multiciclo)  
15. [Pipeline](#15-pipeline)  
16. [Hazards](#16-hazards)  
17. [Arquitetura de Von Neumann](#17-arquitetura-de-von-neumann)  

# 1. Hierarquia de Memória
Organização em camadas com diferentes características de velocidade, custo e capacidade. O topo da hierarquia (registradores, cache) é mais rápido e caro, enquanto a base (HD/SSD) é mais lenta e barata. Permite equilibrar desempenho e custo.

---

# 2. Memória Virtual
Técnica que utiliza espaço em disco (HD/SSD) para estender a capacidade da memória RAM física. Permite que programas utilizem mais memória do que a disponível fisicamente, através da ilusão de um espaço de endereçamento contíguo maior.
- Programas usam **endereços virtuais (VAs)**
- A **MMU (Memory Management Unit)** traduz VAs em endereços físicos (PAs)

## Definições
- **Page size**: Tamanho fixo (ex: 4KB) das unidades transferidas entre disco e RAM
- **Address translation**: Mecanismo hardware/software para converter VA → PA
- **Page table**: Estrutura hierárquica que mapeia páginas virtuais em quadros físicos
- **TLB (Translation Lookaside Buffer)**: Cache de traduções recentes para acelerar o processo
---

# 3. Registradores
Memória interna ao processador (CPU), com acesso em 1 ciclo de clock. Características:
- Velocidade máxima (nanossegundos)
- Capacidade extremamente limitada (ex: 32 registradores de 64 bits)
- Alto custo por bit
---

# 4. Cache
Memória SRAM que armazena dados/instruções frequentemente acessados. Hierarquia:
- **L1**: Integrada ao núcleo (1-4 ciclos de acesso)
- **L2**: Compartilhada entre núcleos (10-20 ciclos)
- **L3**: Cache última nível (20-60 ciclos)
Reduz o *gap* de velocidade entre CPU e RAM (Efeito de Localidade Física).
---

# 5. RAM
Memória DRAM volátil de acesso aleatório onde programas e dados são armazenados enquanto o computador está ligado. Características:
- Armazena dados em uso durante a execução
- Acesso em ~100ns (mais lenta que cache)
- Capacidade típica: 4GB-128GB
- Organizada em módulos (DIMMs/SO-DIMMs)
---

# 6. SSD (Unidade de Estado Sólido)  
Armazenamento não volátil baseado em memória flash NAND, que combina alta velocidade com persistência de dados. Atua como camada intermediária entre RAM (volátil) e HDD (mecânico), otimizando o desempenho do sistema

---

# 7. Barramentos  
Sistema de interconexão que permite a comunicação entre componentes do computador através de vias físicas. Atuam como canais de transmissão coordenada de dados, endereços e sinais de controle.  

## Tipos de Linhas  
1. **Linhas de Controle**  
   - Gerenciam operações do sistema:  
     - Sinalização de *read/write* para memória e dispositivos de E/S  
     - Controle de interrupções (*IRQ*) e *acknowledgement*  
     - Gerenciamento de acesso ao barramento (*bus request/grant*)  
     - Sincronização via clock e reset  

2. **Linhas de Dados**  
   - Transferem informações entre componentes (CPU, memória, periféricos).  
   - Largura do barramento (ex: 32/64 bits) define a quantidade de bits transmitidos por ciclo.  

3. **Linhas de Endereços**  
   - Especificam localizações físicas na memória ou dispositivos.  
   - Tamanho define o espaço endereçável (ex: 32 bits → 4GB).  


## Categorias de Barramentos  

### Barramento Paralelo  
- **Funcionamento**: Transmissão simultânea de múltiplos bits por vias separadas.  
- **Vantagens**:  
  - Alta taxa de transferência em curtas distâncias (ex: PCI – 133 MB/s).  
- **Desvantagens**:  
  - **Skew**: Dessincronização de bits em longas distâncias.  
  - **Crosstalk**: Interferência entre linhas adjacentes.  
  - Custo elevado (mais fios = maior complexidade).  
- **Aplicações**:  
  - Barramentos legados (ISA, ATA).  

### Barramento Serial  
- **Funcionamento**: Transmissão sequencial bit a bit, com codificação embarcada (ex: 8b/10b).  
- **Vantagens**:  
  - Menor interferência e custo (menos fios).  
  - Escalável para altas frequências (ex: PCIe 5.0 – ~128 GB/s por lane).  
  - Robustez em longas distâncias (ex: USB 3.2 até 2 metros).   
- **Aplicações**:  
  - Barramentos modernos (PCIe, SATA, USB, Thunderbolt).  


## Comparação Técnica  
| Característica       | Paralelo               | Serial                 |  
|----------------------|------------------------|------------------------|  
| **Velocidade**       | Alta (curtas distâncias)| Muito alta (largura de banda escalável)|  
| **Custo**            | Alto (mais fios)       | Baixo (menos fios)     |  
| **Complexidade**     | Sincronização crítica  | Gerenciamento de protocolo |  
| **Exemplos**         | PCI, DDR4              | PCIe 5.0, USB4        |  

---

# 8. Controladores de Memória  
Circuitos especializados que gerenciam a comunicação entre a CPU e os módulos de memória (RAM, cache), garantindo sincronização, integridade e eficiência no acesso aos dados.

## Funções Principais  
1. **Gerenciamento de Temporização**:  
2. **Tradução de Endereços**:   
3. **Multi-Canal**:   
4. **Controle de Erros**:  
5. **Interfaceamento**:  

---

# 9. Mapeamento de Memória  
Processo de tradução de endereços virtuais (espaço lógico visto pelos processos) para endereços físicos (localizações reais na RAM). Implementado via cooperação entre hardware (MMU - Memory Management Unit) e sistema operacional.

## Mecanismos de Implementação  
1. **Paginação** (Predominante em sistemas modernos):  
   - Divisão da memória em **páginas virtuais** (espaço lógico, tamanho fixo: 4KB, 2MB) e **quadros físicos** (frames, mesmo tamanho das páginas).  
   - **Page Table**: Estrutura hierárquica mantida pelo SO, mapeando páginas → quadros.  
     - Flags: Presente/Ausente, R/W, User/Supervisor.  
2. **Segmentação** (Obsoleto em sistemas gerais):  
   - Divisão lógica (código, dados, pilha) com tamanhos variáveis.  
   - Usa **Tabela de Segmentos**.

## Componentes Críticos  
| Componente          | Função                                                                 | Localização              |  
|---------------------|-----------------------------------------------------------------------|--------------------------|  
| **TLB** (Translation Lookaside Buffer) | Cache de traduções recentes (Virtual Adress (VA) → Physical Adress (PA)                     | Parte da MMU (CPU)       |  
| **Page Table**      | Mapeamento completo VA → PA (incluindo páginas em disco)              | Memória principal (RAM) |  
| **Page Directory**  | Estrutura de nível superior em sistemas multi-nível                   | RAM                      |  


## Hierarquia de Acesso  
1. **TLB Hit** (≈1 ciclo):  
   - Tradução imediata via cache da MMU.  
   - 1-3 ns
2. **TLB Miss → Page Table Walk** (≈10-100 ciclos):  
   - Consulta à page table na RAM.  
   - ~100 ns  
3. **Page Fault** (≈10^6 ciclos):  
   - Página ausente na RAM → Carregamento do disco (SSD/HD).  
   - SSD: ~100 μs (100.000x mais lento que RAM) 
   - HD: ~10 ms (10.000.000x mais lento que RAM)  

---

# 10. Paginação  
Técnica de gerenciamento de memória que divide o espaço de endereçamento virtual em **páginas** (unidades de tamanho fixo) e o espaço físico em **quadros** (frames). Implementada via hardware (MMU) e sistema operacional, permite alocação dinâmica e proteção de memória.

## **Principais Conceitos**  
1. **Page Table (Tabela de Páginas)**:  
   - Estrutura hierárquica que mapeia páginas virtuais (VA) → quadros físicos (PA).  
   - Cada entrada (*Page Table Entry - PTE*) contém:  
     - **Bit de Presença**: Indica se a página está na RAM.  
     - **Bits de Permissão**: R/W/X (leitura, escrita, execução).  
     - **Endereço Físico** (se presente).  

2. **TLB (Translation Lookaside Buffer)**:  
   - Cache de traduções VA→PA recentes, acelerando acesso à memória.  

3. **Page Fault**:  
   - Interrupção gerada quando uma página não está na RAM.  
   - O SO carrega a página do disco (swap) e atualiza a tabela.  


## **Funcionamento**  
1. **Divisão da Memória**:  
   - **Páginas Virtuais**: Tamanho fixo (ex: 4KB, 2MB, 1GB).  
   - **Quadros Físicos**: Correspondem ao tamanho das páginas.  

2. **Proteção**:  
   - Cada processo tem sua própria tabela de páginas, garantindo isolamento.  
   - Páginas de processos diferentes podem mapear para o mesmo quadro físico (memória compartilhada).  

3. **Demand Paging**:  
   - Apenas páginas necessárias são carregadas na RAM (não "algumas por vez").  


## **Fluxo de Page Fault**  
1. Acesso a um VA não mapeado na RAM.  
2. MMU detecta "bit de presença = 0" na PTE.  
3. Gera interrupção de **page fault**.  
4. SO:  
   - Identifica a localização da página no disco (swap file/pagefile.sys).  
   - Carrega a página em um quadro livre na RAM.  
   - Atualiza a PTE e TLB.  
   - Reinicia a instrução que causou o fault.  



## **Vantagens**  
- **Eficiência**: Alocação granular (evita desperdício por fragmentação externa).  
- **Segurança**: Isolamento entre processos (ex: processo A não acessa páginas do B).  
- **Flexibilidade**: Memória virtual maior que a física.  

---

# 11. RISC (Reduced Instruction Set Computer)  
Arquitetura de processadores que prioriza **instruções simples e altamente otimizadas**, executadas em **1 ciclo de clock** na maioria dos casos. Projetada para eficiência energética e desempenho previsível.

## Características Técnicas  
1. **Conjunto de Instruções**:  
   - **Reduzido**: ~50-100 instruções (ex: ADD, LOAD, STORE).  
   - **Tamanho Fixo**: Facilita *pipelining* (ex: 32 bits no ARMv8).  
2. **Eficiência**:  
   - **Pipeline Profundo**: Até 15 estágios (ex: ARM Cortex-A77).  
   - **Menos Transistores**: Design simplificado reduz consumo (ex: IoT devices).  
3. **Modelo de Execução**:  
   - **Load/Store**: Operações aritméticas só em registradores.  
   - **Memória**: Acessos via LOAD/STORE explícitos.  



## Vantagens  
- **Velocidade**: CPI (Clocks Per Instruction) próximo de 1.  
- **Energia**: Eficiente para dispositivos móveis (ex: smartphones Apple Silicon).  
- **Previsibilidade**: Ideal para sistemas em tempo real.  



## Exemplos  
- ARM (Cortex, Neoverse)  
- RISC-V (open-source)  
- MIPS (aplicações embarcadas)  

---

# 12. CISC (Complex Instruction Set Computer)  
Arquitetura que utiliza **instruções complexas e multifuncionais**, capazes de realizar múltiplas operações em um único comando. Foco em reduzir o número de instruções por programa.

## Características Técnicas  
1. **Conjunto de Instruções**:  
   - **Amplo**: ~300-500 instruções (ex: x86 `REP MOVSB` copia blocos de memória).  
   - **Tamanho Variável**: 1 a 15 bytes por instrução (ex: x86).  
2. **Modos de Endereçamento**:  
   - Direto à memória (ex: `ADD [AX], BX`).  
3. **Microcódigo**:  
   - Instruções complexas são decompostas em micro-operações (ex: Intel desde Pentium Pro).  


## Vantagens  
- **Compactação de Código**: Menos instruções por tarefa.  
- **Legado**: Suporte a software antigo (ex: DOS no x86 moderno).  


## Exemplos  
- x86 (Intel, AMD)  
- z/Architecture (IBM mainframes)  



## Comparação Técnica  
| Critério               | RISC                              | CISC                              |  
|------------------------|-----------------------------------|-----------------------------------|  
| **Instruções**         | Simples, ciclo único              | Complexas, multi-ciclo           |  
| **Uso de Memória**     | Apenas LOAD/STORE                 | Operações diretas                 |  
| **Pipeline**           | Eficiente (estágios homogêneos)   | Complexo (hazards frequentes)     |  
| **Custo de Hardware**  | Baixo (design simplificado)       | Alto (microcódigo, decoders)     |  
| **Energia**            | 0.1-2W (IoT/ARM)                  | 15-250W (servidores x86)         |  

---

# 13. Uniciclo  
Cada instrução é executada em um único ciclo de clock. Possui hardware mais simples, sem componentes complexos de controle de tempo de execução. O ciclo de clock é longo para acomodar a instrução mais demorada, o que limita a velocidade. O desempenho é restrito pelo caminho crítico (critical path) do datapath, que define o tempo necessário para a etapa mais lenta da execução.  

**Vantagens**:  
- Simplicidade de implementação  
- Facilidade de depuração  
- Menor complexidade de controle  
- Consistência temporal (todas as instruções têm latência fixa)  

**Desvantagens**:  
- Baixa eficiência (ciclo de clock ditado pela instrução mais lenta)  

**Passos**:  
1. **Instruction Fetch**: Busca da instrução na memória (RAM ou cache).  
2. **Instruction Decode**: Decodificação da instrução e identificação de operandos.  
3. **Execute**: Operações lógicas/aritméticas na ULA.  
4. **Memory Access**: Leitura/escrita em memória.  
5. **Write Back**: Escrita do resultado no registrador de destino.  
6. **Atualização do PC**: Determinação do próximo endereço (PC + 4).  

---

# 14. Multiciclo  
Cada instrução é dividida em etapas executadas em ciclos de clock separados. Permite reutilização de componentes do hardware (ex: ULA usada em múltiplas etapas) e ciclos de clock mais curtos. Controle sequencial centralizado.  

**Vantagens**:  
- Ciclo de clock otimizado (menor que o uniciclo)  
- Uso eficiente de hardware  
- Balanceamento de estágios  

**Desvantagens**:  
- Controle mais complexo (máquina de estados finitos)  
- Overhead de sincronização entre estágios  

**Passos**:  
1. **Instruction Fetch**: Busca da instrução.  
2. **Instruction Decode**: Decodificação e leitura de registradores.  
3. **Execute**: Cálculo na ULA.  
4. **Memory Access**: Acesso a memória (se necessário).  
5. **Write Back**: Escrita no registrador.  
6. **Atualização do PC**: Próxima instrução.  

---

# 15. Pipeline  
Técnica que permite a execução paralela de múltiplas instruções, sobrepondo suas etapas de processamento. Cada estágio do pipeline opera em uma instrução diferente simultaneamente, aumentando a taxa de throughput.  

**Vantagens**:  
- Alto desempenho (IPC > 1 em condições ideais)  
- Eficiência no uso de recursos  
- Escalabilidade (aumento de estágios melhora frequência)  

**Desvantagens**:  
- Hazards (conflitos estruturais, de dados e de controle)  
- Overhead de sincronização entre estágios  

**Passos**:  
1. **Instruction Fetch**: Busca da instrução.  
2. **Instruction Decode**: Decodificação e leitura de registradores.  
3. **Execute**: Operação na ULA.  
4. **Memory Access**: Leitura/escrita em memória.  
5. **Write Back**: Escrita no registrador.  
6. **Atualização do PC**: Próxima instrução.  

**Observação**: Apesar dos mesmos estágios do multiciclo, o pipeline permite que até 5 instruções estejam em execução simultânea (uma por estágio).  

---

# 16. Hazards  
Problemas que ocorrem em processadores pipeline quando instruções dependentes ou conflitantes interferem na execução paralela. Podem causar stalls (paradas) ou resultados incorretos, reduzindo a eficiência do pipeline.


## Tipos de Hazards  

### 1. **Hazard Estrutural**  
- **Causa**: Conflito por recursos físicos (ex: duas instruções precisam da ULA simultaneamente).  
- **Exemplo**: Acesso simultâneo à memória de instruções e dados se compartilharem o mesmo barramento.  
- **Solução**: Duplicação de recursos (ex: Harvard Architecture) ou escalonamento.  

### 2. **Hazard de Dados**  
- Ocorre quando uma instrução depende do resultado de outra ainda em execução.  
   - **RAW (Read After Write)**: Instrução lê dado antes de ser escrito.  
   - **WAR (Write After Read)**: Instrução escreve antes de outra ler.  
   - **WAW (Write After Write)**: Duas instruções escrevem no mesmo registrador fora de ordem.  
- **Exemplo**:  
  ```asm  
  ADD R1, R2, R3  
  SUB R4, R1, R5  // RAW: SUB depende do resultado de ADD  

---

# 17. Arquitetura de Von Neumann  
Modelo de computação que integra CPU, memória e dispositivos de E/S através de um **barramento único** para dados e instruções. Fundamentada no conceito de **programa armazenado** (instruções e dados na mesma memória).

## Componentes Principais  
1. **CPU**:  
   - **ULA (Unidade Lógica Aritmética)**: Executa operações matemáticas.  
   - **Unidade de Controle**: Coordena fluxo de dados e instruções.  
   - **Registradores**: Armazenamento temporário de alta velocidade (ex: PC, AC).  

2. **Memória Principal (RAM)**:  
   - Armazena instruções e dados de forma não diferenciada.  
   - Acesso sequencial via barramento compartilhado.  

3. **Barramento Único**:  
   - Canal de comunicação para transferência de dados e instruções.  


## Princípios de Operação  
- **Ciclo Fetch-Decode-Execute**:  
  1. Busca da instrução na memória.  
  2. Decodificação pela unidade de controle.  
  3. Execução na ULA.  


## Vantagens  
- **Simplicidade**: Projeto unificado facilita implementação.  
- **Flexibilidade**: Programas podem ser modificados dinamicamente.  


## Limitações  
- **Gargalo de Von Neumann**:  
  - Competição pelo barramento único entre operações de leitura de instruções e acesso a dados.  
  - Limitação teórica de throughput (ex: CPUs modernas perdem ~40% de desempenho devido a stalls).  

---

## Evolução Moderna  
- **Cache Hierárquico**: Minimiza acesso à RAM (não presente no modelo original).  
- **Pipeline**: Paraleliza estágios de execução.  
- **Arquiteturas Híbridas**: Uso de barramentos separados para dados/instruções em nível de cache (ex: Harvard modificada).  

## Impacto Histórico  
- Base para todos os computadores de propósito geral pós-1945 (ex: EDVAC, IAS Machine).  
- Influenciou projetos mesmo em sistemas com elementos Harvard (ex: ARM Cortex-M).  