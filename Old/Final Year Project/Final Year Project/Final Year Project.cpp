// Final Year Project.cpp : Defines the entry point for the console application.
// url : https://www.hackerrank.com/contests/holi-code/challenges/final-year-project

#include <stdio.h>


int main()
{
	int T, N, i, nPP, nPN, nNP, nNN;
	long arr[2][1000], PPU, PPL, PNU, PNL, NPU, NPL, NNU, NNL, PP[2][1000], PN[2][1000], NP[2][1000], NN[2][1000];
	long long sum[12], ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		PPU = PPL = PNU = PNL = NPU = NPL = NNU = NNL = 0;
		nPP = nPN = nNP = nNN = 0;
		for (i = 0;i < N;i++)
			scanf("%ld", &arr[0][i]);
		for (i = 0;i < N;i++)
		{
			scanf("%ld", &arr[1][i]);


			if (arr[0][i] >= 0 && arr[1][i] >= 0)
			{
				PPU += arr[0][i];
				PPL += arr[1][i];
				PP[0][nPP] = arr[0][i];
				PP[1][nPP] = arr[1][i];
				nPP++;
			}
			else if (arr[0][i] <= 0 && arr[1][i] <= 0)
			{
				NNU += arr[0][i];
				NNL += arr[1][i];
				NN[0][nNN] = arr[0][i];
				NN[1][nNN] = arr[1][i];
				nNN++;
			}
			else if (arr[0][i]>0 && arr[1][i] < 0)
			{
				PNU += arr[0][i];
				PNL += arr[1][i];
				PN[0][nPN] = arr[0][i];
				PN[1][nPN] = arr[1][i];
				nPN++;
			}
			else
			{
				NPU += arr[0][i];
				NPL += arr[1][i];
				NP[0][nNP] = arr[0][i];
				NP[1][nNP] = arr[1][i];
				nNP++;
			}
		}

		sum[0] =  PPU*PPU + PPL*PPL;
		sum[1] =  PNU*PNU + PNL*PNL;
		sum[2] =  NPU*NPU + NPL*NPL;
		sum[3] =  NNU*NNU + NNL*NNL;

		long pppnu = PPU, pppnl = PPL;
		for (i = 0;i < nPN;i++)		//pp+pn
		{
			if (pppnu*pppnu + pppnl*pppnl < (pppnu + PN[0][i])*(pppnu + PN[0][i]) + (pppnl + PN[1][i])*(pppnl + PN[1][i]))
			{
				pppnu += PN[0][i];
				pppnl += PN[1][i];
			}


		}
		sum[4] = pppnu*pppnu + pppnl*pppnl;

		long ppnpu = PPU, ppnpl = PPL;
		for (i = 0;i < nNP;i++)		//pp+np
		{
			if (ppnpu*ppnpu + ppnpl*ppnpl < (ppnpu + NP[0][i])*(ppnpu + NP[0][i]) + (ppnpl + NP[1][i])*(ppnpl + NP[1][i]))
			{
				ppnpu += NP[0][i];
				ppnpl += NP[1][i];
			}


		}
		sum[5] = ppnpu*ppnpu + ppnpl*ppnpl;

		long npppu = NPU, npppl = NPL;
		for (i = 0;i < nPP;i++)		//np+pp
		{
			if (npppu*npppu + npppl*npppl < (npppu + PP[0][i])*(npppu + PP[0][i]) + (npppl + PP[1][i])*(npppl + PP[1][i]))
			{
				npppu += PP[0][i];
				npppl += PP[1][i];
			}


		}
		sum[6] = npppu*npppu + npppl*npppl;

		long npnnu = NPU, npnnl = NPL;
		for (i = 0;i < nNN;i++)		//np+nn
		{
			if (npnnu*npnnu + npnnl*npnnl < (npnnu + NN[0][i])*(npnnu + NN[0][i]) + (npnnl + NN[1][i])*(npnnl + NN[1][i]))
			{
				npnnu += NN[0][i];
				npnnl += NN[1][i];
			}


		}
		sum[7] = npnnu*npnnu + npnnl*npnnl;

		long pnppu = PNU, pnppl = PNL;
		for (i = 0;i < nPP;i++)		//pn+pp
		{
			if (pnppu*pnppu + pnppl*pnppl < (pnppu + PP[0][i])*(pnppu + PP[0][i]) + (pnppl + PP[1][i])*(pnppl + PP[1][i]))
			{
				pnppu += PP[0][i];
				pnppl += PP[1][i];
			}


		}
		sum[8] = pnppu*pnppu + pnppl*pnppl;

		long pnnnu = PNU, pnnnl = PNL;
		for (i = 0;i < nNN;i++)		//pn+nn
		{
			if (pnnnu*pnnnu + npnnl*npnnl < (pnnnu + NN[0][i])*(pnnnu + NN[0][i]) + (pnnnl + NN[1][i])*(pnnnl + NN[1][i]))
			{
				pnnnu += NN[0][i];
				pnnnl += NN[1][i];
			}


		}
		sum[9] = pnnnu*pnnnu + pnnnl*pnnnl;

		long nnpnu = NNU, nnpnl = NNL;
		for (i = 0;i < nPN;i++)		//nn+pn
		{
			if (nnpnu*nnpnu + nnpnl*nnpnl < (nnpnu + PN[0][i])*(nnpnu + PN[0][i]) + (nnpnl + PN[1][i])*(nnpnl + PN[1][i]))
			{
				nnpnu += PN[0][i];
				nnpnl += PN[1][i];
			}


		}
		sum[10] = nnpnu*nnpnu + nnpnl*nnpnl;

		long nnnpu = NNU, nnnpl = NNL;
		for (i = 0;i < nPN;i++)		//nn+np
		{
			if (nnnpu*nnnpu + nnnpl*nnnpl < (nnnpu + NP[0][i])*(nnnpu + NP[0][i]) + (nnnpl + NP[1][i])*(nnnpl + NP[1][i]))
			{
				nnnpu += NP[0][i];
				nnnpl += NP[1][i];
			}


		}
		sum[11] = nnnpu*nnnpu + nnnpl*nnnpl;

		ans = sum[0];
		for (i = 1;i < 12;i++)
		{
			if (ans < sum[i])
			{
				ans = sum[i];
			}
		}
		printf("%lld\n", ans);
	}








	return 0;
}

