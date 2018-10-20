#include "../include/sparx.h"

uint16* SPECKEY(uint16 *x, uint16 *y)
{
	uint16 tmp[2];
	tmp[0] = ROTL((*x), 9) + (*y);
	tmp[1] = ROTL((*y), 2) ^ tmp[0];

	return tmp;
}
//void K_4(uint32 *out_k, uint32 *in_k, uint32 r)
//{
//	uint16 *tmp;
//	tmp = SPECKEY((uint16 *)in_k + 1, (uint16 *)in_k);
//	out_k[0] = in_k[3] + r + 1;
//	out_k[3] = in_k[2];
//	*(((uint16 *)out_k) + 5) = *(((uint16 *)in_k) + 3) + tmp[0];
//	*(((uint16 *)out_k) + 4) = *(((uint16 *)in_k) + 2) + tmp[1];
//	out_k[1] = ((uint32)tmp[0] << 16) ^ ((uint32)tmp[1]);
//}
void K_4(uint16 *in_k, uint16 r)
{
	uint16 *tmp;
	tmp = SPECKEY(in_k, in_k + 1);
	in_k[0] = in_k[6];
	in_k[1] = in_k[7] + r + 1;
	in_k[6] = in_k[4];
	in_k[7] = in_k[5];
	in_k[4] = tmp[0] + in_k[2];
	in_k[5] = tmp[1] + in_k[3];
	in_k[2] = tmp[0];
	in_k[3] = tmp[1];
}
void SPARX_KeySchedule(SPARX_RK *sparx_rk, uint16 *mk)
{
	uint16 i, j, k;
	

	*((uint16 *)sparx_rk->rk + 1) = *mk;
	*((uint16 *)sparx_rk->rk + 3) = *(mk + 1);
	*((uint16 *)sparx_rk->rk + 5) = *(mk + 2);
	*((uint16 *)sparx_rk->rk + 7) = *(mk + 3);
	*((uint16 *)sparx_rk->rk + 9) = *(mk + 4);
	*((uint16 *)sparx_rk->rk + 11) = *(mk + 5);
	K_4(mk, 0);
	*((uint16 *)sparx_rk->rk) = *mk;
	*((uint16 *)sparx_rk->rk + 2) = *(mk + 1);
	*((uint16 *)sparx_rk->rk + 4) = *(mk + 2);
	*((uint16 *)sparx_rk->rk + 6) = *(mk + 3);
	*((uint16 *)sparx_rk->rk + 8) = *(mk + 4);
	*((uint16 *)sparx_rk->rk + 10) = *(mk + 5);
	K_4(mk, 1);
	*((uint16 *)sparx_rk->rk + 13) = *mk;
	*((uint16 *)sparx_rk->rk + 15) = *(mk + 1);
	*((uint16 *)sparx_rk->rk + 17) = *(mk + 2);
	*((uint16 *)sparx_rk->rk + 19) = *(mk + 3);
	*((uint16 *)sparx_rk->rk + 21) = *(mk + 4);
	*((uint16 *)sparx_rk->rk + 23) = *(mk + 5);
	K_4(mk, 2);
	*((uint16 *)sparx_rk->rk + 12) = *mk;
	*((uint16 *)sparx_rk->rk + 14) = *(mk + 1);
	*((uint16 *)sparx_rk->rk + 16) = *(mk + 2);
	*((uint16 *)sparx_rk->rk + 18) = *(mk + 3);
	*((uint16 *)sparx_rk->rk + 20) = *(mk + 4);
	*((uint16 *)sparx_rk->rk + 22) = *(mk + 5);

}