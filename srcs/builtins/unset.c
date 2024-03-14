/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:20:47 by kchillon          #+#    #+#             */
/*   Updated: 2024/03/14 16:33:00 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "env.h"
#include "libft.h"
#include "executor.h"

#include <unistd.h>

int	builtin_unset(t_executor *exec, char **argv)
{
	size_t		i;

	if (!argv)
		return (FAILURE);
	i = -1;
	while (argv[++i])
	{
		if (del_var(exec->env, argv[i]))
			return (FAILURE);
	}
	return (SUCCESS);
}

// AA=2 AB=3 AC=4 AD=5 AE=6 AF=7 AG=8 AH=9 AI=10 AJ=11 AK=12 AL=13 AM=14 AN=15 AO=16 AP=17 AQ=18 AR=19 AS=20 AT=21 AU=22 AV=23 AW=24 AX=25 AY=26 AZ=27 BA=28 BB=29 BC=30 BD=31 BE=32 BF=33 BG=34 BH=35 BI=36 BJ=37 BK=38 BL=39 BM=40 BN=41 BO=42 BP=43 BQ=44 BR=45 BS=46 BT=47 BU=48 BV=49 BW=50 BX=51 BY=52 BZ=53 CA=54 CB=55 CC=56 CD=57 CE=58 CF=59 CG=60 CH=61 CI=62 CJ=63 CK=64 CL=65 CM=66 CN=67 CO=68 CP=69 CQ=70 CR=71 CS=72 CT=73 CU=74 CV=75 CW=76 CX=77 CY=78 CZ=79 DA=80 DB=81 DC=82 DD=83 DE=84 DF=85 DG=86 DH=87 DI=88 DJ=89 DK=90 DL=91 DM=92 DN=93 DO=94 DP=95 DQ=96 DR=97 DS=98 DT=99 DU=100 DV=101 DW=102 DX=103 DY=104 DZ=105 EA=106 EB=107 EC=108 ED=109 EE=110 EF=111 EG=112 EH=113 EI=114 EJ=115 EK=116 EL=117 EM=118 EN=119 EO=120 EP=121 EQ=122 ER=123 ES=124 ET=125 EU=126 EV=127 EW=128 EX=129 EY=130 EZ=131 FA=132 FB=133 FC=134 FD=135 FE=136 FF=137 FG=138 FH=139 FI=140 FJ=141 FK=142 FL=143 FM=144 FN=145 FO=146 FP=147 FQ=148 FR=149 FS=150 FT=151 FU=152 FV=153 FW=154 FX=155 FY=156 FZ=157 GA=158 GB=159 GC=160 GD=161 GE=162 GF=163 GG=164 GH=165 GI=166 GJ=167 GK=168 GL=169 GM=170 GN=171