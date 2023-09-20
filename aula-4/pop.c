int pop(TPilha *pilha) {
	int aux = pilha->topo, val;
	pilha->topo = pilha->topo->prox;

	val = aux->info;
	return val;
}
