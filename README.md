# Sistema de Cadastro de Alunos e Disciplinas em C

Este projeto em linguagem C implementa um sistema de cadastro de alunos com suporte a múltiplas disciplinas por aluno, utilizando uma lista encadeada dinâmica. Ele permite adicionar, consultar, listar e remover alunos, organizando os dados de forma eficiente por RGM.

## Funcionalidades

- ✅ Cadastrar alunos com RGM único  
- ✅ Adicionar múltiplas disciplinas por aluno  
- ✅ Manter a lista de alunos ordenada por RGM (ordenação por inserção)  
- ✅ Buscar aluno por RGM usando busca binária  
- ✅ Remover aluno e liberar a memória das disciplinas  
- ✅ Listar todos os alunos e suas disciplinas  
- ✅ Liberar memória corretamente ao final da execução  

## Estrutura de Dados

- `Aluno`: contém o RGM e um ponteiro para uma lista de disciplinas.  
- `Disciplina`: representa cada disciplina como um nó de uma lista encadeada.

## Importância do Projeto

Este sistema é uma aplicação prática de conceitos fundamentais de estrutura de dados, como **listas encadeadas**, **vetores ordenados** e **busca binária**. Ele é importante tanto para a formação acadêmica quanto para o desenvolvimento da lógica de programação, pois:

- 📚 **Reforça a lógica de estruturas dinâmicas** ao gerenciar listas de disciplinas por aluno;  
- 🧠 **Desenvolve o raciocínio algorítmico** com ordenação, inserção, busca e remoção eficientes;  
- 🛠️ **Simula um sistema real de controle escolar**, servindo como base para sistemas maiores (como CRMs, ERPs educacionais e bancos de dados);  
- 🧼 **Incentiva boas práticas** como modularização, alocação e liberação de memória, fundamentais para evitar vazamentos e garantir desempenho;  
- 🏗️ **Prepara o programador para resolver problemas complexos** em sistemas onde os dados mudam com frequência e precisam ser manipulados dinamicamente.

## Aplicações no Dia a Dia

Embora este sistema seja um projeto acadêmico, os conceitos aplicados nele são diretamente úteis em cenários reais, como:

- Sistemas de gestão escolar e universitária (alunos, cursos, matrículas);  
- Aplicações administrativas que lidam com dados hierárquicos (clientes e pedidos, pacientes e exames);  
- Qualquer programa que precise armazenar e manipular dados de forma eficiente e dinâmica.
