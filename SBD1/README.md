# Sistema de Banco de Dados 1 (SBD1)
## MER - MODELOS DE ENTIDADE RELACIONAMENTO
- Voltado apra a representação dos *aspectos estáticos*, informações, do Domínio da Aplicação
- Diagrama Entidade-Relacionamento
#### CONSTRUTORES SINTÁTICOS
Constituem:
- Conjunto de Entidades
- Conjunto de Relacionamentos
- Atributos de Entidades
- Atributos de Relacionamentos

São:
- Um modelo de dados que definem um conjunto (limitado) de construtores sintáticos. Um mesmo Construtor Sintático pode ser usado para representar diversas situações reais. Chamamos isso de **Sobrecarga Semântica**.
#### NO MER
- Entidades são coisas, objetos, pessoas, etc.
- Conjunto de Entidades são coleções de entidades que têm a mesma "estrutura" e mesmo "significado" na modelagem. Estrutural e semanticamente semelhantes
#### CONJUNTO DE ENTIDADES
- O MER não trata de entidades individuais, apenas **Conjunto de Entidades
**
- Notação DER: retângulo
```mermaid
graph TD
    A[Pessoa] 
    B[Disciplina]
    
```
#### CONJUNTO DE RELACIONAMENTO
- **Relacionamentos** são associações entre entidades do mundo real
- **Conjunto de Relacionamentos** são as relações entre entidades dos mesmos **CEs**
- Notação DER: losango
```mermaid
graph TD
    A[Pessoa] --> B{Trabalha}
    A --> C{Matricula}
    C --> D[Disciplina]
    B --> E[Escola]
```
#### ATRIBUTOS
- São valores que representam **propriedades** das entidades e relacionamentos no mundo real.
    - Atributos de entidades.
    - Atributos de relacionamentos.

O mais importante na confecção de um MER é o entendimento das relações entre entidades, não os atributos das entidades entre si.
#### CONJUNTO
- Não devemos assumir que há uma ordem entre os dados.
- São a base dos SGBD, principalmente os relacionais.

**Como definir conjuntos em SGBD?**
- Por restrição de unicidade
    - Todo conjunto deve ter um atributo, ou conjunto de atributos, que identifique **univocamente** cada entidade. Isso é chamado de **chave**.
##### RESTRIÇÃO DE UNICIDADE - CHAVE
- Chave Simples
    - Notação DER: o atributo chave deve ser grifado.
- Chave Estrangeira
    - É referenciando uma entidade a uma chave que se é possível referenciar uma entidade com outra.
    - Principal meio de acesso a uma entidade.
    - Outros atributos identificadores possíveis podem ser anotados de forma separada, para efeito de documentção e projeto lógico.
- Chave Composta
    - Entidade precisa de mais de um atributo para identificação, para robustes e identificação precisa.
    - Vários dados trabalhando como se fossem uma coisa só. Concatenação de atributos, indicando uma **chave única**.
    - Notação DER: todos os atributos da chave grifados.
- Obs: Chave primária deve ter um sublinhado, chaves segundárias devem ter duas.
#### ATRIBUTOS
> Exemplo: Onde colocar o atributo Nota?
![pessoa-disciplina](/SBD1/imgs/image.png)
Deve ser colocado no **relacionamento** entre pessoa e disciplina.
- Atributos simples vs Composto:
    - Simples (atômico): não divido; uma única parte (CPF).
        - Para CPF, pode-se fazer um espaço do tipo único para o CPF.
    - Composto: dividido em partes; possui sub-atributos (endereço).
        - Para endereços, **não é uma boa prática colocar tudo num campo *String***, mas sim separar em sub-atributos.
> Em bancos de dados, o ideal é fechar e deixar o mais estruturado possível.
![atributo-composto](/SBD1/imgs/image-1.png)
- Bancos de dados são extremamente tipados.
- Nas tabelas em conjunto de dados
    - Pense como uma planilha do Excel.
    - Na Tabela do Conjunto de Entidades Aluno, cada linha representa uma tupla, uma entidade única, com as colunas sendo os atributos desse Conjunto de Entidades.
    - **Pode-se relacionar com OO, onde Aluno seria a classe e cada linha seria uma instância de Aluno.**

**Tipos de Atributos**
- Monovalorado vs Multivalorado:
    - Monovalorado: pode assumir um único valor para um(a) entidade/relacionamento .
    - Multivalorado: pode assumir mais de um valor para um(a) entidade/relacionamento
        - Para um único aluno há várias instâncias de notas, como um array.
        - Notação: elipse dupla.
- Armazenado vs Derivado:
    - Armazenado: atributo da entidade.
    - Derivado: são valores obtidos a partir de outros valores. Não necessariamente está no banco.
        - Pode ser um atributo que toda hora é calculado, como IRA, idade.
        - Pode ser um atributo derivado, mas já armazenado, como nº de alunos.
    - > Vida máxima pode ser derivada se for baseada em força/stamina, por exemplo.
        - Caso o sistema não tenha muitos acessos, é viável armazenar um atributo e então atualizar apenas quando necessário. Ex: número de alunos de uma turma, feito com incremento e decremento, ao invés de calcular todas as vezes.
        - > So o atributo for derivado do calculo de outros atributos, mesmo que esteja no banco, o mesmo deve ser tracejado.
        ![atributo-derivado](/SBD1/imgs/image-2.png)
#### CONJUNTO DE RELACIONAMENTOS - PAPÉIS
> Cada CE que participa de um CR tem um **papel** no CR, com uma indicação opcional. Pode-se entender isso como um requisito não-funcional.
![CR-papeis](/SBD1/imgs/image-3.png)
>Indicação de papéis deve ser feita para evitar ambiguidade na interpretação do CR
Quando há papéis distinto nos CEs em Crs distintos, pode-se adotar os papéis para auxiliar no entendimento do Modelo.
![Ce-CR-papeis-distintos](/SBD1/imgs/image-4.png)

**Auto-Relacionamento**
- Quando um mesmo CE desempenha mais de um papel num mesmo CR.
```mermaid
graph TD
    A[Disciplina] -->|tem pré-requisito| B{Pré-Requisito}
    A -->|é pré-requisito| B{Pré-Requisito}
```
#### CARDINALIDADE
- Garante que seja impossível relacionar um pedido para dois clientes distintos.
- É uma restrição estrutural.
- Determina o nº de relacionamentos das quais cada entidade pode participar
> Uma sala pode ter (0:N) personagens, um personagem pode estar em (1:1) sala.

#### EFICIÊNCIA NO ARMAZENAMENTO
- Ao entrar na UnB, entregamos a foto. Essa foto precisa ser amazenada numa coluna do tipo blob (binary large object) ou string de bits (4M, 25M, ...). Faz-se uma tabela para foto, por ser grande, e referencia por uma chave a tabela com os outros atributos de Aluno. Pois assim o sistema não fica lento em consultas.
    - Para matricula em alguma matéria não é necessário ler a foto, os 25M, apenas dados leves, strings, numeros, bits de dados para a matrícula.


#### CONJUNTO DE RELACIONAMENTOS - RESTRIÇÃO DE PARTICIPAÇÃO
**Participação Total ou Dependência Existencial**
- Toda entidade de um CE deve obrigatoriamente participar de ao menos um relacionamento do CR, sendo assim associada a uma entidade.
- Uma entidade só deve exisit se estiver associada a outra entidade por meio de um relacionamento.

**Notação DER**: linha dupla conectando o CE ao CR.

> Exemplo: toda entidade **Disciplina** participa de um relacionamento **Possui** e deve estar associada a uma entidade **Curso**.
![participação-total](/SBD1/imgs/image-8.png)

**Participação Parcial**
> - Nem todas as entidades de um CE participam de um CR. Podendo existir sem estar associada a outra.
**Notação DER**: linha simples conectando o CE ao CR.
![participação-parcial](/SBD1/imgs/image-9.png)

#### CONJUNTO DE RELACIONAMENTOS - ENTIDADE FRACA
**Entidade Fraca**
- Não possui identificador único (chave), ou atributo identificador **univoco semânticamente** do domínio da aplicação.
- Identificação depende do relacionamento com outra entidade ou outro conjunto. Chamado **owner**.
**Notação DER**.
- Entidade Fraca: traço duplo no retângulo.
- CR Identificador: traço duplo no losango.
> Chave Parcial: *um ou mais* atributos de CEs Fracas para **identificação univoca em relação a um mesmo owner**
![CE-fraca](/SBD1/imgs/image-5.png)

**Conjunto de Entidades Fracas**
- Possui **participação total** no CR, chamado de **CR identificador**
- Cardinalidade é sempre 1:N ou 1:1, mas nunca N:M.

**Quando modelar como Entidade Fraca?**
- Quando tiver muitos atributos.
- Quando participar de outros relacionamentos além do owner.
> ![exemplo-entidade-fraca](/SBD1/imgs/image-6.png)

#### CONJUNTO DE RELACIONAMENTOS - GRAU
- Um Conjunto de Relacionamentos (CR) pode envolver **dois** ou **mais** Conjuntos de Entidades (CE).
- **Grau** do CR é o número de CEs envolvidos.
    - Dois CEs -> CR Binários.
    - Trẽs CEs -> CR Ternário.
    >![grau-CR](/SBD1/imgs/image-7.png)
    - Aqui, não era necessário ter utilizado Professor que auxilia, pois cada Disciplina tem um Professor específico. Caso contário, qualquer professor poderia auxiliar em uma matéria, que poderia nem ser de seu domínio.
    - Para relacionamento binário, fixar um lado (0:1) e abrir do outro (0,N). Ex: um aluno está monitorando uma disciplina.

> Problema criado ao transformar **relacionamento ternário** em **relacionamento binário**
> ![problema-ternario](image.png)
> Mauricio ministra X, Jose monitora x, y e z e Mauricio auxiliou Jose (perdemos a disciplina)
- Se pensar em algum relacionamento ternário no projeto, tente mudar para binário e veja se existe a perda de alguma informação. Se não houver, o CR ternário está *errado*. **Sempre pensar se tem algo de errado ao fazer CR ternários.**
- Um CE pode ter **vários papés**. Exemplo: uma empresa negocia *Produtos* com outra *Empresa* compradora.
>![rel-ternario-papeis](image-1.png)
- Auto-Relacionamento Ternário pode ocorrer quando há mesmas instâncias de um mesmo CE, como *Empresa*, com papeis de *Compra, Venda, Assessoria*, por meio do relacionamento *Promover Vendas*.

**CR - Significado semântico**
-  Conjuntos de Relacionamento tem **significado semântico**.
    - Não deixar nada **implícito** no modelo.
    - Não deixe nada **dúbio**, para que a implementação de um outro desenvolvedor não seja **obscura**.
    - O principal objetido do modelo é facilitar o entendimento do modelo de banco de dados.
    - Evite verbos como *"possui"*.
    - Relacionamentos são como **arestas** em grafos.

- Relaciomanetos binarios ou ternarios que possuem (0,N), não significam possibilidade criar um relacionamento com uma das partes faltando. Ex: medico (0,N) - Atende (0,N) Paciente.

- Um dos problemas de Eng. Software é a correção de modelos, mas deixando a documentação no passado, sem atualizar. **As coisas tem que bater**.



- ID serial incremental 
>![cr-significadosemantico](image-2.png)
- O CR **Monitora**  incorpora a idéia que *professor ministra
disciplinas com o auxílio de um aluno monitor*.
- CR **Cria** representa quem criou cada disciplina.

---
### MER-X AGREGAÇÃO
- Objetivo: construir **objetos compostos** a partir de **objetos componentes**.
#### ABSTRAÇÃO DE AGREGAÇÃO
- Pode-se pensar como algo *Orientado a Eventos*
    - Ex: personagem derrota monstro, e quando isso acontece, queremos ligar coisas a isso.
    - Ex: um personagem completa missão e esse evento destrava um novo mapa. **Agregação**
- Exemplo da consulta e relacionamento entre paciente e médico.
>![abstração-de-agregação](image-3.png)
>- **Nomenclatura**
![abstração-de-agregação-nomenclatura](image-4.png)
- Neste caso, a chave de **Consulta** é composta pelas **Chaves primárias** de cada elemento. Sendo **RG, CRM** e **Data**.
- A chave do relacionamento poderia ser um *ID* criado. *Data* poderia ser tracejado[ (chave parcial), pois precisa dos outros dados, RG e CRM. E também poderia ser utilizado como *chave secundária*, após a criação do *ID*, para busca com outros parâmetros. Como por exemplo a seguinte chave composta:
>![agragação-paciente-chave-composta](image-8.png)
- No modelo, existem 3 tabelas
    - Paciente;
    - Médico;
    - Consulta.
- Outro exemplo de um projeto de pesquisa. Onde o *atributo* **Título** de um projeto pode ser utilizado como *chave* do modelo.
  - Antes da agregação
  >![agregação-antes](image-5.png)
  - Após a agregação
  >![agregação-projeto](image-6.png)
  - Com um relacionamento de financiamento, onde um projeto é financiado por 1 (uma) agência
  >![financia-agregação-projeto](image-7.png)
  - Um relacionamento (N:N) exige uma nova tabela. Exemplo: Agência (N) - Financia (N) Projeto
  Tabela "Financia"
  - 
    |Projeto | Agencia |
    |--|--|
    |10 | CNPQ |
    |10 | FAPDF |
    |20 | CNPQ |
**Notas sobre Agregação**
- Toda agregação é gerada semrpe a partir de **um e somente um CR**.
- Toda instância do CR gera, **obrigatoriamente, pelo menos um** elemento composto (agregado).

**Notas sobre uso de Agregação**
- Semanticamente, instâncias de um CE participam de mais de um relacionamento.
  - Exemplo: CEs paciente e médico, com o CR atende.
- CR possui identificador próprio.
  - Exemplo: título,d o CR orienta entre os CEs professor e aluno
- Necessidade de associar dois relacionamentos.
  - Quando se começa a associar um relacionamento a um *substantivo*, é um início de agregação* ou a tentativa de *associar dois relacionamentos, ligando dois relacionamentos entre si*.
- Necessidade de fazer relacionamento com atributo.
  - Podemos transformar esse atributo numa entidade fraca, caso seja necessário realizar um "relacionamento com esse atributo".

- Nunca ao fazer um relacionamento (professor ministra uma disciplina por exemplo), dar uma agregação para esse relacionamento, não precisa de chave neste caso.

#### ABSTRAÇÃO DE GENERALIZAÇÃO/ESPECIALIZAÇÃO
- Generalizações e especializações de CEs é feito utilizando o conceito de **herança**.
- **Chave** é **herdada** do CE genérico.
- CEs específicos **herdam todos os CRs** dado um CE genérico.
Ao fazer generalização/especialização da mais trabalho para fazer as tabelas/MER, mas no jogo fica bem mais lógico conceitualmente.
>![herança-CE-CR](image-9.png)
**Herança em múltiplos níveis**
- É possível fazer herança em múltiplos níveis, para especialização.
>![herança-multiplos-niveis](image-10.png)
**Herança Múltipla**
- Assim como pode-se fazer herança múltipla caso necessário
>![herança-multipla](image-11.png)
-  Múltiplas especializações podem ser úteis para especializar dados distintos, mas que fazem parte de um mesmo CE, como em pessoa com vínculo e nacionalidade especializadas
>![especialização-múltipla](image-12.png)

**Restrição de Disjunção**
- Exclusão Mútua: ou um ou outro (pessoa física/jurídica)
- Sobreposição: vários (ex: disciplinas cursando)

**Restrição de Totalidade**
- Especialização Total: tem que ter ou dados de um ou dados de outro (ex: pessoa física/jurídica). No mínimo um
>![restrição-de-totalidade](image-13.png)
- Especialização Parcial: não preciisa ter dados de um ou outro, pode ser apenas uma generalização. (ex: item. poderia ter item arma e item armadura, mas uma tocha é apenas um item)

#### TIPOS DE RESTRIÇÃO
- Total exclusiva (T,E)
    - Ou é um ou é outro, não pode ser genérico
    >![total-exclusiva](image-18.png)
- Total sobreposta (T,S)
    - É no mínimo de um tipo, e pode ser de um ou mais tipos
    > ![total-sobreposta](image-19.png)
- Parcial exclusiva (P,E)
    - Ou é disciplina (generalizada) ou disciplina de graduação ou disciplina de pós-grad. 
    > ![parcial-exclusiva](image-14.png)
    - **Melhor maneira de representar**
    > ![parcial-exclusiva-representação](image-15.png)
- Parcial sobreposta (P, S)
    - Pode ter múltiplas funções, ou apenas ser uma Pessoa
    > ![parcial-sobreposta](image-16.png)
    - **Melhor maneira de respresentar**
    > ![parcial-sobreposta-representação](image-17.png)

## Modelo Relacional
**Qual a diferença entre Modelo Entidade Relacionamento e Modelo Relacional?**
- MER independe da tecnologia.
    - Entidade Relacionamento se modela o mundo como Entidades e Relacionamentos (modelo conceitual), independe da tecnologia.
- Modelo Relacional depende da tecnologia.
    - Já o Modelo Relacional depende da tecnologia do banco.

### Definição de Modelo Relacional
- Valores são dados do mundo real.
- Tabelas mantêm os dados, chamadas de ***relações***.
    - Dados guardados em formato de linha, ou seja, não possuem ordem.
### Terminologia
- Relação:
    - Tabela.
- Tupla:
    - Registro, linha.
- Atributo:
    - Campo
- Valor.
- Relation Intension:
    - Definindo como é a tabela estruturalmente.
    - Esquema.
- Relation Extension:
    - São os registros da tabela
    - Instância.

### Modelo
![modelo-intuitivo](image-20.png)
### Valores
- **Atômicos**.
    - Indivisível: não pode ser recuperado em partes:
        - Ex: sobrenome, idade.
        - Ex de uso: Ao trabalhar com CPF, separar os dados em duas colunas. Salvar 9 dígitos numa coluna e 2 em outra, para fazer a **validação**, pois recuperar o campo completo e trabalhar com funções de string é **mais lento**.
    - Monovalorado ou Multivalorado: pode ter apenas um valor ou vários:
        - Ex: idade (monovalorado), irmãos (multivalorado).

![modelo-intuitivo-2](image-21.png)
### Domínios
- De aplicação:
    - Escola;
    - Universidade;
    - Cidade.
- De atributo:
    - Nomes de Alunos;
    - Código de Disciplinas;
    - Idade.

> **[!Nota]** Ao guardar um valor **NULL** no banco, é gasto **o mesmo valor de um campo que está completo, seja ele com 2 chars ou 2 mil chars**

Em bancos, estamos sempre olhando o que é mais importante: *Espaço em Disco* ou *Desempenho*    Banco de Dados

### Como mapear Conjuntos de Entidades?
**Para entidades Fracas**
- Faz-se com a utilização de setas, saindo da Entidade mais fraca até a entidade forte
![entidade-fraca(2)](image-23.png)
![entidade-fraca](image-22.png)
**Para relacionamento binário obrigatório**
- Pode-se utilizar a restrição de *NULL*.
**Alternativas para relacionamentos (1:1)**
- Fazer uma só relação
![uma relação](image-24.png)
**Para relacionamentos com *Pouca Participação***
- Ao tentar mapear 






























## Dicas Projeto

Poção. O personagem toma, pegar essa poção e "jogar" de volta para a loja.

Para guardar um atributo que foi modificado ex: o monstro muda de comportamento quando viu o personagem. Mas daí o monstro morre e queremos que ele ainda lembre dessa informação. Devemos mandar esse monstro pra sala do limbo e depois respawnar essa mesma instância sem apagar os dados.

Não ter 58 itens iguais na tabela, pois todos os atributos daquele item serão iguais (ex: 38). Sol: uma linha só, com os dados da 38, e então criar instâncias

> **[!NOTA]** Devemos criar uma linha para cada TIPO de monstro/item, e depois apenas instâncias para interagir com o jogo.

> **[!NOTA]** Para monstro e itens, devemos ter o molde, e as instâncias de cada um deles. Ps: obrigado João.
> - Um monstro pode fugir se estiver com pouca vida. 
> - Um monstro pode ter seus atributos aleatórios assim que for "gerado". 

> **[!Recomendação]** Tocha, pedra, monstro: **usar como instâncias**

> **[!NOTA]** Por exemplo, você tem um item, falamos que um item está em várias salas. PQ em várias salas? Pois pode ter pedra em qualquer lugar, por isso o item está em várias salas (isso tem um lado ruim). Ex: o personagem tem uma espada e numa batalha ele leva uma falha crítica, pode-se dizer que a espada quebrou. Como qeubrar só a espada dele sem quebrar a dos outros? Como dizer q ele pegou os restos da espada?

> **[!NOTA]** A espada vai perdendo o dano ao dar golpes. Como identificar que a espada daquele personagem está perdendo "vida" ao atacar? Resposta: INSTÂNCIAS

> **[!NOTA]** O inventário do personagem é uma entidade fraca 1:1 com o personagem

> **[!NOTA]** No jogo, o personagem mata um monstro, para anotar o nro de ataques, esse numero deve ser anotado no "Derrota", não no personagem ou no monstro. 

> **MER de item**
>
> Item -> Possui (CR Fraca) -> Instância (CE Fraca) (0,N) -> Está -> (0,1) Sala

> Exemplo de **Generalização/Especialização** em **Armas/Itens/Personagens/Habilidades**: 
> - Armas de uso infinito, armas que dependem de munição (arco e flecha, 38, fuzil, etc), armas que dependem de bateria (lazer), arma mágica (mana), arma psiquica...
> - Itens do tipo craftável e não craftável
> - Personagens do tipo monstro, do tipo NPC, do tipo jogador...
> - Habilidades do tipo física/intelectuais com pre-requisitos distintos
> - 


> **[!Recomendação e Uso de PA]** Grafos para menor caminho entre inimigos e jogar em perseguição, DFS para movimentos mais random icos e BFS para padronizados.


> Assistir aulas 1 e 2
> - [Aula 1](https://aprender3.unb.br/mod/url/view.php?id=1404588)
> - [Aula 2](https://aprender3.unb.br/mod/url/view.php?id=1404590)


#### FATOS INTERESSANTES

> **Pq não armazenar informações no banco como um grafo?**
>
> Diretamente impactado pelo Hardware. Hoje **banco de dados Não-relacionais são feitos em grafos**. No HD, por conta da cabeça de leitura que tem que ir pra FAT (File Alocation Table), para saber onde estão os arquivos e depois voltar para ler o arquivo. A latência é muito grande ao invés de ser uma leitura sequencial.
>
> A leitura que o HD faz é por **blocos**. 
> Quando o sistema vai ler um arquivo sequencial, o primeiro bloco que o HD trás, de mil alunos por exemplo, já posso trazer o próximo bloco de alunos. Em grafos, o sitema lê o primeiro bloco, aproveito apenas o primeiro aluno dos mil e depois busca outro bloco, para aproveitar apenas o primeiro novamente, gerando latência.