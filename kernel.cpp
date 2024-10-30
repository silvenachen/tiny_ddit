
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
using namespace std;

extern "C" {

void PE_kernel_modulate_0_0(
  hls::stream< float > &v0 /* v0[8] */,
  hls::stream< float > &v1 /* v1[8] */,
  hls::stream< float > &v2 /* v2[8] */,
  hls::stream< float > &v3 /* v3[8] */,
  float v4[1][2],
  int v5,
  int v6
) {	// L5
//   #pragma HLS stream variable=v0 depth=2
//   #pragma HLS stream variable=v1 depth=3
//   #pragma HLS stream variable=v2 depth=2
//   #pragma HLS stream variable=v3 depth=3
    #pragma HLS stream variable=v0 depth=8
    #pragma HLS stream variable=v1 depth=8
    #pragma HLS stream variable=v2 depth=8
    #pragma HLS stream variable=v3 depth=8
    #pragma HLS array_partition variable=v4 complete dim=2

  float v;	// L8
  v = 0.000000;	// L9
  l_S_k_0_k: for (int k = 0; k < 8; k++) {	// L10
    float v9 = v0.read(); // v0[k];	// L11
    float a;	// L12
    a = v9;	// L13
    float v11 = v1.read(); // v1[k];	// L14
    float b;	// L15
    b = v11;	// L16
    float v13 = a;	// L17
    float v14 = b;	// L18
    float v15 = v13 * v14;	// L19
    float v16 = v;	// L20
    float v17 = v16 + v15;	// L21
    v = v17;	// L22
    float v18 = a;	// L23
    v2.write(v18); // v2[k] = v18;	// L24
    float v19 = b;	// L25
    v3.write(v19); // v3[k] = v19;	// L26
  }
  float v20 = v;	// L28
  v4[v5][v6] = v20;	// L29
}

void PE_kernel_modulate_1_0(
  hls::stream< float > &v21 /* v21[8] */,
  hls::stream< float > &v22 /* v22[8] */,
  hls::stream< float > &v23 /* v23[8] */,
  hls::stream< float > &v24 /* v24[8] */,
  float v25[1][2],
  int v26,
  int v27
) {	// L32
//   #pragma HLS stream variable=v21 depth=2
//   #pragma HLS stream variable=v22 depth=3
//   #pragma HLS stream variable=v23 depth=2
//   #pragma HLS stream variable=v24 depth=3
  #pragma HLS stream variable=v21 depth=8
  #pragma HLS stream variable=v22 depth=8
  #pragma HLS stream variable=v23 depth=8
  #pragma HLS stream variable=v24 depth=8
  #pragma HLS array_partition variable=v25 complete dim=2

  float v1;	// L35
  v1 = 0.000000;	// L36
  l_S_k_0_k1: for (int k1 = 0; k1 < 8; k1++) {	// L37
    float v30 = v21.read(); // v21[k1];	// L38
    float a1;	// L39
    a1 = v30;	// L40
    float v32 = v22.read(); // v22[k1];	// L41
    float b1;	// L42
    b1 = v32;	// L43
    float v34 = a1;	// L44
    float v35 = b1;	// L45
    float v36 = v34 * v35;	// L46
    float v37 = v1;	// L47
    float v38 = v37 + v36;	// L48
    v1 = v38;	// L49
    float v39 = a1;	// L50
    v23.write(v39); // v23[k1] = v39;	// L51
    float v40 = b1;	// L52
    v24.write(v40); // v24[k1] = v40;	// L53
  }
  float v41 = v1;	// L55
  v25[v26][v27] = v41;	// L56
}

void systolic_tile_modulate(
  float v42[1][8],
  float v43[8][2],
  float v44[1][2]
) {	// L59
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v43 complete dim=2

  #pragma HLS array_partition variable=v44 complete dim=2

  hls::stream< float > A_fifo[1][3] /* A_fifo[1][3][8] */;	// L60
  #pragma HLS stream variable=A_fifo depth=2
  hls::stream< float > B_fifo[2][2] /* B_fifo[2][2][8] */;	// L61
  #pragma HLS stream variable=B_fifo depth=3
  float A_drain;	// L62
  float B_drain[2];	// L63
  l_data_load_k2: for (int k2 = 0; k2 < 8; k2++) {	// L64
    l_S_m_0_m: for (int m = 0; m < 1; m++) {	// L65
      float v51 = v42[m][k2];	// L66
      A_fifo[m][0].write(v51); // A_fifo[m][0][k2] = v51;	// L67
    }
    l_S_n_1_n: for (int n = 0; n < 2; n++) {	// L69
      float v53 = v43[k2][n];	// L70
      B_fifo[n][0].write(v53); // B_fifo[n][0][k2] = v53;	// L71
    }
  }
  hls::stream< float > &v54 /* v54[8] */ = A_fifo[0][0];	// L75
  hls::stream< float > &v55 /* v55[8] */ = B_fifo[0][0];	// L76
  hls::stream< float > &v56 /* v56[8] */ = A_fifo[0][1];	// L82
  hls::stream< float > &v57 /* v57[8] */ = B_fifo[0][1];	// L83
  PE_kernel_modulate_0_0(v54, v55, v56, v57, v44, 0, 0);	// L84
  hls::stream< float > &v58 /* v58[8] */ = A_fifo[0][1];	// L86
  hls::stream< float > &v59 /* v59[8] */ = B_fifo[1][0];	// L87
  hls::stream< float > &v60 /* v60[8] */ = A_fifo[0][2];	// L91
  hls::stream< float > &v61 /* v61[8] */ = B_fifo[1][1];	// L92
  PE_kernel_modulate_1_0(v58, v59, v60, v61, v44, 0, 1);	// L93
  l_data_drain_k3: for (int k3 = 0; k3 < 8; k3++) {	// L94
    l_S_m_4_m1: for (int m1 = 0; m1 < 1; m1++) {	// L95
      float v64 = A_fifo[m1][2].read(); // A_fifo[m1][2][k3];	// L96
      A_drain = v64;	// L97
    }
    l_S_n_5_n1: for (int n1 = 0; n1 < 2; n1++) {	// L99
      float v66 = B_fifo[n1][1].read(); // B_fifo[n1][1][k3];	// L100
      B_drain[n1] = v66;	// L101
    }
  }
}

void systolic_modulate(
  float v67[1][8],
  float v68[8][192],
  float v69[1][192]
) {	// L106
  float local_A[1][8];	// L107
  float local_B[8][2];	// L108
  #pragma HLS array_partition variable=local_B complete dim=2

  float local_C[1][2];	// L109
  #pragma HLS array_partition variable=local_C complete dim=2

  l_outer_tile_mi: for (int mi = 0; mi < 1; mi++) {	// L110
    l_ni: for (int ni = 0; ni < 96; ni++) {	// L111
    #pragma HLS dataflow
      l_load_A_tile_ak: for (int ak = 0; ak < 8; ak++) {	// L112
      #pragma HLS pipeline II=1
        l_ai: for (int ai = 0; ai < 1; ai++) {	// L113
          ap_int<33> v77 = ni;	// L114
          bool v78 = v77 == 0;	// L117
          if (v78) {	// L118
            float v79 = v67[(mi + ai)][ak];	// L119
            local_A[ai][ak] = v79;	// L120
          }
        }
      }
      l_load_B_tile_bk: for (int bk = 0; bk < 8; bk++) {	// L124
        l_bj: for (int bj = 0; bj < 2; bj++) {	// L125
        #pragma HLS pipeline II=1
          float v82 = v68[bk][((ni * 2) + bj)];	// L126
          local_B[bk][bj] = v82;	// L127
        }
      }
      systolic_tile_modulate(local_A, local_B, local_C);	// L130
      l_store_C_tile_sj: for (int sj = 0; sj < 2; sj++) {	// L131
      #pragma HLS pipeline II=1
        l_si: for (int si = 0; si < 1; si++) {	// L132
          float v85 = local_C[si][sj];	// L133
          v69[(mi + si)][((ni * 2) + sj)] = v85;	// L134
        }
      }
    }
  }
}

void adaLN_modulate(
  float v86[1][8],
  float v87[8][192],
  float v88[192],
  float v89[32],
  float v90[32],
  float v91[32],
  float v92[32],
  float v93[32],
  float v94[32]
) {	// L141
  float Y[1][192];	// L144
  for (int v96 = 0; v96 < 1; v96++) {	// L145
    for (int v97 = 0; v97 < 192; v97++) {	// L145
      Y[v96][v97] = 0.000000;	// L145
    }
  }
  systolic_modulate(v86, v87, Y);	// L146
  float Z[192];	// L147
  for (int v99 = 0; v99 < 192; v99++) {	// L148
    Z[v99] = 0.000000;	// L148
  }
  l_bias_add_i: for (int i = 0; i < 1; i++) {	// L149
    l_j: for (int j = 0; j < 192; j++) {	// L150
      float v102 = Y[i][j];	// L151
      float v103 = v88[j];	// L152
      float v104 = v102 + v103;	// L153
      Z[j] = v104;	// L154
    }
  }
  l_slice_i1: for (int i1 = 0; i1 < 32; i1++) {	// L157
    float v106 = Z[i1];	// L158
    v89[i1] = v106;	// L159
    float v107 = Z[(i1 + 32)];	// L160
    v90[i1] = v107;	// L161
    float v108 = Z[(i1 + 64)];	// L162
    v91[i1] = v108;	// L163
    float v109 = Z[(i1 + 96)];	// L164
    v92[i1] = v109;	// L165
    float v110 = Z[(i1 + 128)];	// L166
    v93[i1] = v110;	// L167
    float v111 = Z[(i1 + 160)];	// L168
    v94[i1] = v111;	// L169
  }
}

void layer_norm(
  float v112[64][32],
  float v113[32],
  float v114[32],
  float v115[64][32]
) {	// L173
  float mean[64];	// L175
  for (int v117 = 0; v117 < 64; v117++) {	// L177
    mean[v117] = 0.000000;	// L177
  }
  float mean2[64];	// L178
  for (int v119 = 0; v119 < 64; v119++) {	// L179
    mean2[v119] = 0.000000;	// L179
  }
  float var[64];	// L180
  l_sum_i2: for (int i2 = 0; i2 < 64; i2++) {	// L181
    l_j1: for (int j1 = 0; j1 < 32; j1++) {	// L182
      float v123 = v112[i2][j1];	// L183
      float v124 = mean[i2];	// L184
      float v125 = v124 + v123;	// L185
      mean[i2] = v125;	// L186
      float v126 = v112[i2][j1];	// L187
      float v127 = v126 * v126;	// L188
      float v128 = mean2[i2];	// L189
      float v129 = v128 + v127;	// L190
      mean2[i2] = v129;	// L191
    }
  }
  l_mean_var_i3: for (int i3 = 0; i3 < 64; i3++) {	// L194
    float v131 = mean[i3];	// L195
    float v132 = v131 / 32.000000;	// L198
    mean[i3] = v132;	// L199
    float v133 = mean2[i3];	// L200
    float v134 = v133 / 32.000000;	// L201
    mean2[i3] = v134;	// L202
    float v135 = mean2[i3];	// L203
    float v136 = mean[i3];	// L204
    float v137 = v136 * v136;	// L205
    float v138 = v135 - v137;	// L206
    var[i3] = v138;	// L207
  }
  l_norm_i4: for (int i4 = 0; i4 < 64; i4++) {	// L209
    l_j2: for (int j2 = 0; j2 < 32; j2++) {	// L210
      float v141 = v113[j2];	// L211
      float v142 = v112[i4][j2];	// L212
      float v143 = mean[i4];	// L213
      float v144 = v142 - v143;	// L214
      float v145 = v141 * v144;	// L215
      float v146 = var[i4];	// L216
      float v147 = v146 + 0.000010;	// L218
      float v148 = sqrt(v147);	// L219
      float v149 = v145 / v148;	// L220
      float v150 = v114[j2];	// L221
      float v151 = v149 + v150;	// L222
      v115[i4][j2] = v151;	// L223
    }
  }
}

void modulate_fused(
  float v152[64][32],
  float v153[32],
  float v154[32],
  float v155[64][32]
) {	// L228
  l_m_fused_i5: for (int i5 = 0; i5 < 64; i5++) {	// L230
    l_j3: for (int j3 = 0; j3 < 32; j3++) {	// L231
      float v158 = v152[i5][j3];	// L232
      float v159 = v153[j3];	// L233
      float v160 = v159 + 1.000000;	// L236
      float v161 = v158 * v160;	// L237
      float v162 = v154[j3];	// L238
      float v163 = v161 + v162;	// L239
      v155[i5][j3] = v163;	// L240
    }
  }
}

void PE_kernel_Q_0_0(
  hls::stream< float > &v164 /* v164[32] */,
  hls::stream< float > &v165 /* v165[32] */,
  hls::stream< float > &v166 /* v166[32] */,
  hls::stream< float > &v167 /* v167[32] */,
  float v168[2][2],
  int v169,
  int v170
) {	// L245
  #pragma HLS stream variable=v164 depth=3
  #pragma HLS stream variable=v165 depth=3
  #pragma HLS stream variable=v166 depth=3
  #pragma HLS stream variable=v167 depth=3
  #pragma HLS array_partition variable=v168 complete dim=1
  #pragma HLS array_partition variable=v168 complete dim=2

  float v2;	// L248
  v2 = 0.000000;	// L249
  l_S_k_0_k4: for (int k4 = 0; k4 < 32; k4++) {	// L250
    float v173 = v164.read(); // v164[k4];	// L251
    float a2;	// L252
    a2 = v173;	// L253
    float v175 = v165.read(); // v165[k4];	// L254
    float b2;	// L255
    b2 = v175;	// L256
    float v177 = a2;	// L257
    float v178 = b2;	// L258
    float v179 = v177 * v178;	// L259
    float v180 = v2;	// L260
    float v181 = v180 + v179;	// L261
    v2 = v181;	// L262
    float v182 = a2;	// L263
    v166.write(v182); // v166[k4] = v182;	// L264
    float v183 = b2;	// L265
    v167.write(v183); // v167[k4] = v183;	// L266
  }
  float v184 = v2;	// L268
  v168[v169][v170] = v184;	// L269
}

void PE_kernel_Q_1_0(
  hls::stream< float > &v185 /* v185[32] */,
  hls::stream< float > &v186 /* v186[32] */,
  hls::stream< float > &v187 /* v187[32] */,
  hls::stream< float > &v188 /* v188[32] */,
  float v189[2][2],
  int v190,
  int v191
) {	// L272
  #pragma HLS stream variable=v185 depth=3
  #pragma HLS stream variable=v186 depth=3
  #pragma HLS stream variable=v187 depth=3
  #pragma HLS stream variable=v188 depth=3
  #pragma HLS array_partition variable=v189 complete dim=1
  #pragma HLS array_partition variable=v189 complete dim=2

  float v3;	// L275
  v3 = 0.000000;	// L276
  l_S_k_0_k5: for (int k5 = 0; k5 < 32; k5++) {	// L277
    float v194 = v185.read(); // v185[k5];	// L278
    float a3;	// L279
    a3 = v194;	// L280
    float v196 = v186.read(); // v186[k5];	// L281
    float b3;	// L282
    b3 = v196;	// L283
    float v198 = a3;	// L284
    float v199 = b3;	// L285
    float v200 = v198 * v199;	// L286
    float v201 = v3;	// L287
    float v202 = v201 + v200;	// L288
    v3 = v202;	// L289
    float v203 = a3;	// L290
    v187.write(v203); // v187[k5] = v203;	// L291
    float v204 = b3;	// L292
    v188.write(v204); // v188[k5] = v204;	// L293
  }
  float v205 = v3;	// L295
  v189[v190][v191] = v205;	// L296
}

void PE_kernel_Q_0_1(
  hls::stream< float > &v206 /* v206[32] */,
  hls::stream< float > &v207 /* v207[32] */,
  hls::stream< float > &v208 /* v208[32] */,
  hls::stream< float > &v209 /* v209[32] */,
  float v210[2][2],
  int v211,
  int v212
) {	// L299
  #pragma HLS stream variable=v206 depth=3
  #pragma HLS stream variable=v207 depth=3
  #pragma HLS stream variable=v208 depth=3
  #pragma HLS stream variable=v209 depth=3
  #pragma HLS array_partition variable=v210 complete dim=1
  #pragma HLS array_partition variable=v210 complete dim=2

  float v4;	// L302
  v4 = 0.000000;	// L303
  l_S_k_0_k6: for (int k6 = 0; k6 < 32; k6++) {	// L304
    float v215 = v206.read(); // v206[k6];	// L305
    float a4;	// L306
    a4 = v215;	// L307
    float v217 = v207.read(); // v207[k6];	// L308
    float b4;	// L309
    b4 = v217;	// L310
    float v219 = a4;	// L311
    float v220 = b4;	// L312
    float v221 = v219 * v220;	// L313
    float v222 = v4;	// L314
    float v223 = v222 + v221;	// L315
    v4 = v223;	// L316
    float v224 = a4;	// L317
    v208.write(v224); // v208[k6] = v224;	// L318
    float v225 = b4;	// L319
    v209.write(v225); // v209[k6] = v225;	// L320
  }
  float v226 = v4;	// L322
  v210[v211][v212] = v226;	// L323
}

void PE_kernel_Q_1_1(
  hls::stream< float > &v227 /* v227[32] */,
  hls::stream< float > &v228 /* v228[32] */,
  hls::stream< float > &v229 /* v229[32] */,
  hls::stream< float > &v230 /* v230[32] */,
  float v231[2][2],
  int v232,
  int v233
) {	// L326
  #pragma HLS stream variable=v227 depth=3
  #pragma HLS stream variable=v228 depth=3
  #pragma HLS stream variable=v229 depth=3
  #pragma HLS stream variable=v230 depth=3
  #pragma HLS array_partition variable=v231 complete dim=1
  #pragma HLS array_partition variable=v231 complete dim=2

  float v5;	// L329
  v5 = 0.000000;	// L330
  l_S_k_0_k7: for (int k7 = 0; k7 < 32; k7++) {	// L331
    float v236 = v227.read(); // v227[k7];	// L332
    float a5;	// L333
    a5 = v236;	// L334
    float v238 = v228.read(); // v228[k7];	// L335
    float b5;	// L336
    b5 = v238;	// L337
    float v240 = a5;	// L338
    float v241 = b5;	// L339
    float v242 = v240 * v241;	// L340
    float v243 = v5;	// L341
    float v244 = v243 + v242;	// L342
    v5 = v244;	// L343
    float v245 = a5;	// L344
    v229.write(v245); // v229[k7] = v245;	// L345
    float v246 = b5;	// L346
    v230.write(v246); // v230[k7] = v246;	// L347
  }
  float v247 = v5;	// L349
  v231[v232][v233] = v247;	// L350
}

void systolic_tile_Q(
  float v248[2][32],
  float v249[32][2],
  float v250[2][2]
) {	// L353
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v248 complete dim=1

  #pragma HLS array_partition variable=v249 complete dim=2

  #pragma HLS array_partition variable=v250 complete dim=1
  #pragma HLS array_partition variable=v250 complete dim=2

  hls::stream< float > A_fifo1[2][3] /* A_fifo1[2][3][32] */;	// L354
  #pragma HLS stream variable=A_fifo1 depth=3
  hls::stream< float > B_fifo1[2][3] /* B_fifo1[2][3][32] */;	// L355
  #pragma HLS stream variable=B_fifo1 depth=3
  float A_drain1[2];	// L356
  float B_drain1[2];	// L357
  l_data_load_k8: for (int k8 = 0; k8 < 32; k8++) {	// L358
    l_S_m_0_m2: for (int m2 = 0; m2 < 2; m2++) {	// L359
      float v257 = v248[m2][k8];	// L360
      A_fifo1[m2][0].write(v257); // A_fifo1[m2][0][k8] = v257;	// L361
    }
    l_S_n_1_n2: for (int n2 = 0; n2 < 2; n2++) {	// L363
      float v259 = v249[k8][n2];	// L364
      B_fifo1[n2][0].write(v259); // B_fifo1[n2][0][k8] = v259;	// L365
    }
  }
  hls::stream< float > &v260 /* v260[32] */ = A_fifo1[0][0];	// L369
  hls::stream< float > &v261 /* v261[32] */ = B_fifo1[0][0];	// L370
  hls::stream< float > &v262 /* v262[32] */ = A_fifo1[0][1];	// L376
  hls::stream< float > &v263 /* v263[32] */ = B_fifo1[0][1];	// L377
  PE_kernel_Q_0_0(v260, v261, v262, v263, v250, 0, 0);	// L378
  hls::stream< float > &v264 /* v264[32] */ = A_fifo1[0][1];	// L380
  hls::stream< float > &v265 /* v265[32] */ = B_fifo1[1][0];	// L381
  hls::stream< float > &v266 /* v266[32] */ = A_fifo1[0][2];	// L385
  hls::stream< float > &v267 /* v267[32] */ = B_fifo1[1][1];	// L386
  PE_kernel_Q_1_0(v264, v265, v266, v267, v250, 0, 1);	// L387
  hls::stream< float > &v268 /* v268[32] */ = A_fifo1[1][0];	// L388
  hls::stream< float > &v269 /* v269[32] */ = B_fifo1[0][1];	// L389
  hls::stream< float > &v270 /* v270[32] */ = A_fifo1[1][1];	// L390
  hls::stream< float > &v271 /* v271[32] */ = B_fifo1[0][2];	// L391
  PE_kernel_Q_0_1(v268, v269, v270, v271, v250, 1, 0);	// L392
  hls::stream< float > &v272 /* v272[32] */ = A_fifo1[1][1];	// L393
  hls::stream< float > &v273 /* v273[32] */ = B_fifo1[1][1];	// L394
  hls::stream< float > &v274 /* v274[32] */ = A_fifo1[1][2];	// L395
  hls::stream< float > &v275 /* v275[32] */ = B_fifo1[1][2];	// L396
  PE_kernel_Q_1_1(v272, v273, v274, v275, v250, 1, 1);	// L397
  l_data_drain_k9: for (int k9 = 0; k9 < 32; k9++) {	// L398
    l_S_m_4_m3: for (int m3 = 0; m3 < 2; m3++) {	// L399
      float v278 = A_fifo1[m3][2].read(); // A_fifo1[m3][2][k9];	// L400
      A_drain1[m3] = v278;	// L401
    }
    l_S_n_5_n3: for (int n3 = 0; n3 < 2; n3++) {	// L403
      float v280 = B_fifo1[n3][2].read(); // B_fifo1[n3][2][k9];	// L404
      B_drain1[n3] = v280;	// L405
    }
  }
}

void systolic_Q(
  float v281[64][32],
  float v282[32][32],
  float v283[64][32]
) {	// L410
  float local_A1[2][32];	// L411
  #pragma HLS array_partition variable=local_A1 complete dim=1

  float local_B1[32][2];	// L412
  #pragma HLS array_partition variable=local_B1 complete dim=2

  float local_C1[2][2];	// L413
  #pragma HLS array_partition variable=local_C1 complete dim=1
  #pragma HLS array_partition variable=local_C1 complete dim=2

  l_outer_tile_mi1: for (int mi1 = 0; mi1 < 32; mi1++) {	// L414
    l_ni1: for (int ni1 = 0; ni1 < 16; ni1++) {	// L415
    #pragma HLS dataflow
      l_load_A_tile_ak1: for (int ak1 = 0; ak1 < 32; ak1++) {	// L416
        l_ai1: for (int ai1 = 0; ai1 < 2; ai1++) {	// L417
        #pragma HLS pipeline II=1
          ap_int<33> v291 = ni1;	// L418
          bool v292 = v291 == 0;	// L421
          if (v292) {	// L422
            float v293 = v281[((mi1 * 2) + ai1)][ak1];	// L423
            local_A1[ai1][ak1] = v293;	// L424
          }
        }
      }
      l_load_B_tile_bk1: for (int bk1 = 0; bk1 < 32; bk1++) {	// L428
        l_bj1: for (int bj1 = 0; bj1 < 2; bj1++) {	// L429
        #pragma HLS pipeline II=1
          float v296 = v282[bk1][((ni1 * 2) + bj1)];	// L430
          local_B1[bk1][bj1] = v296;	// L431
        }
      }
      systolic_tile_Q(local_A1, local_B1, local_C1);	// L434
      l_store_C_tile_sj1: for (int sj1 = 0; sj1 < 2; sj1++) {	// L435
        l_si1: for (int si1 = 0; si1 < 2; si1++) {	// L436
        #pragma HLS pipeline II=1
          float v299 = local_C1[si1][sj1];	// L437
          v283[((mi1 * 2) + si1)][((ni1 * 2) + sj1)] = v299;	// L438
        }
      }
    }
  }
}

void PE_kernel_K_0_0(
  hls::stream< float > &v300 /* v300[32] */,
  hls::stream< float > &v301 /* v301[32] */,
  hls::stream< float > &v302 /* v302[32] */,
  hls::stream< float > &v303 /* v303[32] */,
  float v304[2][2],
  int v305,
  int v306
) {	// L445
  #pragma HLS stream variable=v300 depth=3
  #pragma HLS stream variable=v301 depth=3
  #pragma HLS stream variable=v302 depth=3
  #pragma HLS stream variable=v303 depth=3
  #pragma HLS array_partition variable=v304 complete dim=1
  #pragma HLS array_partition variable=v304 complete dim=2

  float v6;	// L448
  v6 = 0.000000;	// L449
  l_S_k_0_k10: for (int k10 = 0; k10 < 32; k10++) {	// L450
    float v309 = v300.read(); // v300[k10];	// L451
    float a6;	// L452
    a6 = v309;	// L453
    float v311 = v301.read(); // v301[k10];	// L454
    float b6;	// L455
    b6 = v311;	// L456
    float v313 = a6;	// L457
    float v314 = b6;	// L458
    float v315 = v313 * v314;	// L459
    float v316 = v6;	// L460
    float v317 = v316 + v315;	// L461
    v6 = v317;	// L462
    float v318 = a6;	// L463
    v302.write(v318); // v302[k10] = v318;	// L464
    float v319 = b6;	// L465
    v303.write(v319); // v303[k10] = v319;	// L466
  }
  float v320 = v6;	// L468
  v304[v305][v306] = v320;	// L469
}

void PE_kernel_K_1_0(
  hls::stream< float > &v321 /* v321[32] */,
  hls::stream< float > &v322 /* v322[32] */,
  hls::stream< float > &v323 /* v323[32] */,
  hls::stream< float > &v324 /* v324[32] */,
  float v325[2][2],
  int v326,
  int v327
) {	// L472
  #pragma HLS stream variable=v321 depth=3
  #pragma HLS stream variable=v322 depth=3
  #pragma HLS stream variable=v323 depth=3
  #pragma HLS stream variable=v324 depth=3
  #pragma HLS array_partition variable=v325 complete dim=1
  #pragma HLS array_partition variable=v325 complete dim=2

  float v7;	// L475
  v7 = 0.000000;	// L476
  l_S_k_0_k11: for (int k11 = 0; k11 < 32; k11++) {	// L477
    float v330 = v321.read(); // v321[k11];	// L478
    float a7;	// L479
    a7 = v330;	// L480
    float v332 = v322.read(); // v322[k11];	// L481
    float b7;	// L482
    b7 = v332;	// L483
    float v334 = a7;	// L484
    float v335 = b7;	// L485
    float v336 = v334 * v335;	// L486
    float v337 = v7;	// L487
    float v338 = v337 + v336;	// L488
    v7 = v338;	// L489
    float v339 = a7;	// L490
    v323.write(v339); // v323[k11] = v339;	// L491
    float v340 = b7;	// L492
    v324.write(v340); // v324[k11] = v340;	// L493
  }
  float v341 = v7;	// L495
  v325[v326][v327] = v341;	// L496
}

void PE_kernel_K_0_1(
  hls::stream< float > &v342 /* v342[32] */,
  hls::stream< float > &v343 /* v343[32] */,
  hls::stream< float > &v344 /* v344[32] */,
  hls::stream< float > &v345 /* v345[32] */,
  float v346[2][2],
  int v347,
  int v348
) {	// L499
  #pragma HLS stream variable=v342 depth=3
  #pragma HLS stream variable=v343 depth=3
  #pragma HLS stream variable=v344 depth=3
  #pragma HLS stream variable=v345 depth=3
  #pragma HLS array_partition variable=v346 complete dim=1
  #pragma HLS array_partition variable=v346 complete dim=2

  float v8;	// L502
  v8 = 0.000000;	// L503
  l_S_k_0_k12: for (int k12 = 0; k12 < 32; k12++) {	// L504
    float v351 = v342.read(); // v342[k12];	// L505
    float a8;	// L506
    a8 = v351;	// L507
    float v353 = v343.read(); // v343[k12];	// L508
    float b8;	// L509
    b8 = v353;	// L510
    float v355 = a8;	// L511
    float v356 = b8;	// L512
    float v357 = v355 * v356;	// L513
    float v358 = v8;	// L514
    float v359 = v358 + v357;	// L515
    v8 = v359;	// L516
    float v360 = a8;	// L517
    v344.write(v360); // v344[k12] = v360;	// L518
    float v361 = b8;	// L519
    v345.write(v361); // v345[k12] = v361;	// L520
  }
  float v362 = v8;	// L522
  v346[v347][v348] = v362;	// L523
}

void PE_kernel_K_1_1(
  hls::stream< float > &v363 /* v363[32] */,
  hls::stream< float > &v364 /* v364[32] */,
  hls::stream< float > &v365 /* v365[32] */,
  hls::stream< float > &v366 /* v366[32] */,
  float v367[2][2],
  int v368,
  int v369
) {	// L526
  #pragma HLS stream variable=v363 depth=3
  #pragma HLS stream variable=v364 depth=3
  #pragma HLS stream variable=v365 depth=3
  #pragma HLS stream variable=v366 depth=3
  #pragma HLS array_partition variable=v367 complete dim=1
  #pragma HLS array_partition variable=v367 complete dim=2

  float v9;	// L529
  v9 = 0.000000;	// L530
  l_S_k_0_k13: for (int k13 = 0; k13 < 32; k13++) {	// L531
    float v372 = v363.read(); // v363[k13];	// L532
    float a9;	// L533
    a9 = v372;	// L534
    float v374 = v364.read(); // v364[k13];	// L535
    float b9;	// L536
    b9 = v374;	// L537
    float v376 = a9;	// L538
    float v377 = b9;	// L539
    float v378 = v376 * v377;	// L540
    float v379 = v9;	// L541
    float v380 = v379 + v378;	// L542
    v9 = v380;	// L543
    float v381 = a9;	// L544
    v365.write(v381); // v365[k13] = v381;	// L545
    float v382 = b9;	// L546
    v366.write(v382); // v366[k13] = v382;	// L547
  }
  float v383 = v9;	// L549
  v367[v368][v369] = v383;	// L550
}

void systolic_tile_K(
  float v384[2][32],
  float v385[32][2],
  float v386[2][2]
) {	// L553
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v384 complete dim=1

  #pragma HLS array_partition variable=v385 complete dim=2

  #pragma HLS array_partition variable=v386 complete dim=1
  #pragma HLS array_partition variable=v386 complete dim=2

  hls::stream< float > A_fifo2[2][3] /* A_fifo2[2][3][32] */;	// L554
  #pragma HLS stream variable=A_fifo2 depth=3
  hls::stream< float > B_fifo2[2][3] /* B_fifo2[2][3][32] */;	// L555
  #pragma HLS stream variable=B_fifo2 depth=3
  float A_drain2[2];	// L556
  float B_drain2[2];	// L557
  l_data_load_k14: for (int k14 = 0; k14 < 32; k14++) {	// L558
    l_S_m_0_m4: for (int m4 = 0; m4 < 2; m4++) {	// L559
      float v393 = v384[m4][k14];	// L560
      A_fifo2[m4][0].write(v393); // A_fifo2[m4][0][k14] = v393;	// L561
    }
    l_S_n_1_n4: for (int n4 = 0; n4 < 2; n4++) {	// L563
      float v395 = v385[k14][n4];	// L564
      B_fifo2[n4][0].write(v395); // B_fifo2[n4][0][k14] = v395;	// L565
    }
  }
  hls::stream< float > &v396 /* v396[32] */ = A_fifo2[0][0];	// L569
  hls::stream< float > &v397 /* v397[32] */ = B_fifo2[0][0];	// L570
  hls::stream< float > &v398 /* v398[32] */ = A_fifo2[0][1];	// L576
  hls::stream< float > &v399 /* v399[32] */ = B_fifo2[0][1];	// L577
  PE_kernel_K_0_0(v396, v397, v398, v399, v386, 0, 0);	// L578
  hls::stream< float > &v400 /* v400[32] */ = A_fifo2[0][1];	// L580
  hls::stream< float > &v401 /* v401[32] */ = B_fifo2[1][0];	// L581
  hls::stream< float > &v402 /* v402[32] */ = A_fifo2[0][2];	// L585
  hls::stream< float > &v403 /* v403[32] */ = B_fifo2[1][1];	// L586
  PE_kernel_K_1_0(v400, v401, v402, v403, v386, 0, 1);	// L587
  hls::stream< float > &v404 /* v404[32] */ = A_fifo2[1][0];	// L588
  hls::stream< float > &v405 /* v405[32] */ = B_fifo2[0][1];	// L589
  hls::stream< float > &v406 /* v406[32] */ = A_fifo2[1][1];	// L590
  hls::stream< float > &v407 /* v407[32] */ = B_fifo2[0][2];	// L591
  PE_kernel_K_0_1(v404, v405, v406, v407, v386, 1, 0);	// L592
  hls::stream< float > &v408 /* v408[32] */ = A_fifo2[1][1];	// L593
  hls::stream< float > &v409 /* v409[32] */ = B_fifo2[1][1];	// L594
  hls::stream< float > &v410 /* v410[32] */ = A_fifo2[1][2];	// L595
  hls::stream< float > &v411 /* v411[32] */ = B_fifo2[1][2];	// L596
  PE_kernel_K_1_1(v408, v409, v410, v411, v386, 1, 1);	// L597
  l_data_drain_k15: for (int k15 = 0; k15 < 32; k15++) {	// L598
    l_S_m_4_m5: for (int m5 = 0; m5 < 2; m5++) {	// L599
      float v414 = A_fifo2[m5][2].read(); // A_fifo2[m5][2][k15];	// L600
      A_drain2[m5] = v414;	// L601
    }
    l_S_n_5_n5: for (int n5 = 0; n5 < 2; n5++) {	// L603
      float v416 = B_fifo2[n5][2].read(); // B_fifo2[n5][2][k15];	// L604
      B_drain2[n5] = v416;	// L605
    }
  }
}

void systolic_K(
  float v417[64][32],
  float v418[32][32],
  float v419[64][32]
) {	// L610
  float local_A2[2][32];	// L611
  #pragma HLS array_partition variable=local_A2 complete dim=1

  float local_B2[32][2];	// L612
  #pragma HLS array_partition variable=local_B2 complete dim=2

  float local_C2[2][2];	// L613
  #pragma HLS array_partition variable=local_C2 complete dim=1
  #pragma HLS array_partition variable=local_C2 complete dim=2

  l_outer_tile_mi2: for (int mi2 = 0; mi2 < 32; mi2++) {	// L614
    l_ni2: for (int ni2 = 0; ni2 < 16; ni2++) {	// L615
    #pragma HLS dataflow
      l_load_A_tile_ak2: for (int ak2 = 0; ak2 < 32; ak2++) {	// L616
        l_ai2: for (int ai2 = 0; ai2 < 2; ai2++) {	// L617
        #pragma HLS pipeline II=1
          ap_int<33> v427 = ni2;	// L618
          bool v428 = v427 == 0;	// L621
          if (v428) {	// L622
            float v429 = v417[((mi2 * 2) + ai2)][ak2];	// L623
            local_A2[ai2][ak2] = v429;	// L624
          }
        }
      }
      l_load_B_tile_bk2: for (int bk2 = 0; bk2 < 32; bk2++) {	// L628
        l_bj2: for (int bj2 = 0; bj2 < 2; bj2++) {	// L629
        #pragma HLS pipeline II=1
          float v432 = v418[bk2][((ni2 * 2) + bj2)];	// L630
          local_B2[bk2][bj2] = v432;	// L631
        }
      }
      systolic_tile_K(local_A2, local_B2, local_C2);	// L634
      l_store_C_tile_sj2: for (int sj2 = 0; sj2 < 2; sj2++) {	// L635
        l_si2: for (int si2 = 0; si2 < 2; si2++) {	// L636
        #pragma HLS pipeline II=1
          float v435 = local_C2[si2][sj2];	// L637
          v419[((mi2 * 2) + si2)][((ni2 * 2) + sj2)] = v435;	// L638
        }
      }
    }
  }
}

void PE_kernel_V_0_0(
  hls::stream< float > &v436 /* v436[32] */,
  hls::stream< float > &v437 /* v437[32] */,
  hls::stream< float > &v438 /* v438[32] */,
  hls::stream< float > &v439 /* v439[32] */,
  float v440[2][2],
  int v441,
  int v442
) {	// L645
  #pragma HLS stream variable=v436 depth=3
  #pragma HLS stream variable=v437 depth=3
  #pragma HLS stream variable=v438 depth=3
  #pragma HLS stream variable=v439 depth=3
  #pragma HLS array_partition variable=v440 complete dim=1
  #pragma HLS array_partition variable=v440 complete dim=2

  float v10;	// L648
  v10 = 0.000000;	// L649
  l_S_k_0_k16: for (int k16 = 0; k16 < 32; k16++) {	// L650
    float v445 = v436.read(); // v436[k16];	// L651
    float a10;	// L652
    a10 = v445;	// L653
    float v447 = v437.read(); // v437[k16];	// L654
    float b10;	// L655
    b10 = v447;	// L656
    float v449 = a10;	// L657
    float v450 = b10;	// L658
    float v451 = v449 * v450;	// L659
    float v452 = v10;	// L660
    float v453 = v452 + v451;	// L661
    v10 = v453;	// L662
    float v454 = a10;	// L663
    v438.write(v454); // v438[k16] = v454;	// L664
    float v455 = b10;	// L665
    v439.write(v455); // v439[k16] = v455;	// L666
  }
  float v456 = v10;	// L668
  v440[v441][v442] = v456;	// L669
}

void PE_kernel_V_1_0(
  hls::stream< float > &v457 /* v457[32] */,
  hls::stream< float > &v458 /* v458[32] */,
  hls::stream< float > &v459 /* v459[32] */,
  hls::stream< float > &v460 /* v460[32] */,
  float v461[2][2],
  int v462,
  int v463
) {	// L672
  #pragma HLS stream variable=v457 depth=3
  #pragma HLS stream variable=v458 depth=3
  #pragma HLS stream variable=v459 depth=3
  #pragma HLS stream variable=v460 depth=3
  #pragma HLS array_partition variable=v461 complete dim=1
  #pragma HLS array_partition variable=v461 complete dim=2

  float v11;	// L675
  v11 = 0.000000;	// L676
  l_S_k_0_k17: for (int k17 = 0; k17 < 32; k17++) {	// L677
    float v466 = v457.read(); // v457[k17];	// L678
    float a11;	// L679
    a11 = v466;	// L680
    float v468 = v458.read(); // v458[k17];	// L681
    float b11;	// L682
    b11 = v468;	// L683
    float v470 = a11;	// L684
    float v471 = b11;	// L685
    float v472 = v470 * v471;	// L686
    float v473 = v11;	// L687
    float v474 = v473 + v472;	// L688
    v11 = v474;	// L689
    float v475 = a11;	// L690
    v459.write(v475); // v459[k17] = v475;	// L691
    float v476 = b11;	// L692
    v460.write(v476); // v460[k17] = v476;	// L693
  }
  float v477 = v11;	// L695
  v461[v462][v463] = v477;	// L696
}

void PE_kernel_V_0_1(
  hls::stream< float > &v478 /* v478[32] */,
  hls::stream< float > &v479 /* v479[32] */,
  hls::stream< float > &v480 /* v480[32] */,
  hls::stream< float > &v481 /* v481[32] */,
  float v482[2][2],
  int v483,
  int v484
) {	// L699
  #pragma HLS stream variable=v478 depth=3
  #pragma HLS stream variable=v479 depth=3
  #pragma HLS stream variable=v480 depth=3
  #pragma HLS stream variable=v481 depth=3
  #pragma HLS array_partition variable=v482 complete dim=1
  #pragma HLS array_partition variable=v482 complete dim=2

  float v12;	// L702
  v12 = 0.000000;	// L703
  l_S_k_0_k18: for (int k18 = 0; k18 < 32; k18++) {	// L704
    float v487 = v478.read(); // v478[k18];	// L705
    float a12;	// L706
    a12 = v487;	// L707
    float v489 = v479.read(); // v479[k18];	// L708
    float b12;	// L709
    b12 = v489;	// L710
    float v491 = a12;	// L711
    float v492 = b12;	// L712
    float v493 = v491 * v492;	// L713
    float v494 = v12;	// L714
    float v495 = v494 + v493;	// L715
    v12 = v495;	// L716
    float v496 = a12;	// L717
    v480.write(v496); // v480[k18] = v496;	// L718
    float v497 = b12;	// L719
    v481.write(v497); // v481[k18] = v497;	// L720
  }
  float v498 = v12;	// L722
  v482[v483][v484] = v498;	// L723
}

void PE_kernel_V_1_1(
  hls::stream< float > &v499 /* v499[32] */,
  hls::stream< float > &v500 /* v500[32] */,
  hls::stream< float > &v501 /* v501[32] */,
  hls::stream< float > &v502 /* v502[32] */,
  float v503[2][2],
  int v504,
  int v505
) {	// L726
  #pragma HLS stream variable=v499 depth=3
  #pragma HLS stream variable=v500 depth=3
  #pragma HLS stream variable=v501 depth=3
  #pragma HLS stream variable=v502 depth=3
  #pragma HLS array_partition variable=v503 complete dim=1
  #pragma HLS array_partition variable=v503 complete dim=2

  float v13;	// L729
  v13 = 0.000000;	// L730
  l_S_k_0_k19: for (int k19 = 0; k19 < 32; k19++) {	// L731
    float v508 = v499.read(); // v499[k19];	// L732
    float a13;	// L733
    a13 = v508;	// L734
    float v510 = v500.read(); // v500[k19];	// L735
    float b13;	// L736
    b13 = v510;	// L737
    float v512 = a13;	// L738
    float v513 = b13;	// L739
    float v514 = v512 * v513;	// L740
    float v515 = v13;	// L741
    float v516 = v515 + v514;	// L742
    v13 = v516;	// L743
    float v517 = a13;	// L744
    v501.write(v517); // v501[k19] = v517;	// L745
    float v518 = b13;	// L746
    v502.write(v518); // v502[k19] = v518;	// L747
  }
  float v519 = v13;	// L749
  v503[v504][v505] = v519;	// L750
}

void systolic_tile_V(
  float v520[2][32],
  float v521[32][2],
  float v522[2][2]
) {	// L753
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v520 complete dim=1

  #pragma HLS array_partition variable=v521 complete dim=2

  #pragma HLS array_partition variable=v522 complete dim=1
  #pragma HLS array_partition variable=v522 complete dim=2

  hls::stream< float > A_fifo3[2][3] /* A_fifo3[2][3][32] */;	// L754
  #pragma HLS stream variable=A_fifo3 depth=3
  hls::stream< float > B_fifo3[2][3] /* B_fifo3[2][3][32] */;	// L755
  #pragma HLS stream variable=B_fifo3 depth=3
  float A_drain3[2];	// L756
  float B_drain3[2];	// L757
  l_data_load_k20: for (int k20 = 0; k20 < 32; k20++) {	// L758
    l_S_m_0_m6: for (int m6 = 0; m6 < 2; m6++) {	// L759
      float v529 = v520[m6][k20];	// L760
      A_fifo3[m6][0].write(v529); // A_fifo3[m6][0][k20] = v529;	// L761
    }
    l_S_n_1_n6: for (int n6 = 0; n6 < 2; n6++) {	// L763
      float v531 = v521[k20][n6];	// L764
      B_fifo3[n6][0].write(v531); // B_fifo3[n6][0][k20] = v531;	// L765
    }
  }
  hls::stream< float > &v532 /* v532[32] */ = A_fifo3[0][0];	// L769
  hls::stream< float > &v533 /* v533[32] */ = B_fifo3[0][0];	// L770
  hls::stream< float > &v534 /* v534[32] */ = A_fifo3[0][1];	// L776
  hls::stream< float > &v535 /* v535[32] */ = B_fifo3[0][1];	// L777
  PE_kernel_V_0_0(v532, v533, v534, v535, v522, 0, 0);	// L778
  hls::stream< float > &v536 /* v536[32] */ = A_fifo3[0][1];	// L780
  hls::stream< float > &v537 /* v537[32] */ = B_fifo3[1][0];	// L781
  hls::stream< float > &v538 /* v538[32] */ = A_fifo3[0][2];	// L785
  hls::stream< float > &v539 /* v539[32] */ = B_fifo3[1][1];	// L786
  PE_kernel_V_1_0(v536, v537, v538, v539, v522, 0, 1);	// L787
  hls::stream< float > &v540 /* v540[32] */ = A_fifo3[1][0];	// L788
  hls::stream< float > &v541 /* v541[32] */ = B_fifo3[0][1];	// L789
  hls::stream< float > &v542 /* v542[32] */ = A_fifo3[1][1];	// L790
  hls::stream< float > &v543 /* v543[32] */ = B_fifo3[0][2];	// L791
  PE_kernel_V_0_1(v540, v541, v542, v543, v522, 1, 0);	// L792
  hls::stream< float > &v544 /* v544[32] */ = A_fifo3[1][1];	// L793
  hls::stream< float > &v545 /* v545[32] */ = B_fifo3[1][1];	// L794
  hls::stream< float > &v546 /* v546[32] */ = A_fifo3[1][2];	// L795
  hls::stream< float > &v547 /* v547[32] */ = B_fifo3[1][2];	// L796
  PE_kernel_V_1_1(v544, v545, v546, v547, v522, 1, 1);	// L797
  l_data_drain_k21: for (int k21 = 0; k21 < 32; k21++) {	// L798
    l_S_m_4_m7: for (int m7 = 0; m7 < 2; m7++) {	// L799
      float v550 = A_fifo3[m7][2].read(); // A_fifo3[m7][2][k21];	// L800
      A_drain3[m7] = v550;	// L801
    }
    l_S_n_5_n7: for (int n7 = 0; n7 < 2; n7++) {	// L803
      float v552 = B_fifo3[n7][2].read(); // B_fifo3[n7][2][k21];	// L804
      B_drain3[n7] = v552;	// L805
    }
  }
}

void systolic_V(
  float v553[64][32],
  float v554[32][32],
  float v555[64][32]
) {	// L810
  float local_A3[2][32];	// L811
  #pragma HLS array_partition variable=local_A3 complete dim=1

  float local_B3[32][2];	// L812
  #pragma HLS array_partition variable=local_B3 complete dim=2

  float local_C3[2][2];	// L813
  #pragma HLS array_partition variable=local_C3 complete dim=1
  #pragma HLS array_partition variable=local_C3 complete dim=2

  l_outer_tile_mi3: for (int mi3 = 0; mi3 < 32; mi3++) {	// L814
    l_ni3: for (int ni3 = 0; ni3 < 16; ni3++) {	// L815
    #pragma HLS dataflow
      l_load_A_tile_ak3: for (int ak3 = 0; ak3 < 32; ak3++) {	// L816
        l_ai3: for (int ai3 = 0; ai3 < 2; ai3++) {	// L817
        #pragma HLS pipeline II=1
          ap_int<33> v563 = ni3;	// L818
          bool v564 = v563 == 0;	// L821
          if (v564) {	// L822
            float v565 = v553[((mi3 * 2) + ai3)][ak3];	// L823
            local_A3[ai3][ak3] = v565;	// L824
          }
        }
      }
      l_load_B_tile_bk3: for (int bk3 = 0; bk3 < 32; bk3++) {	// L828
        l_bj3: for (int bj3 = 0; bj3 < 2; bj3++) {	// L829
        #pragma HLS pipeline II=1
          float v568 = v554[bk3][((ni3 * 2) + bj3)];	// L830
          local_B3[bk3][bj3] = v568;	// L831
        }
      }
      systolic_tile_V(local_A3, local_B3, local_C3);	// L834
      l_store_C_tile_sj3: for (int sj3 = 0; sj3 < 2; sj3++) {	// L835
        l_si3: for (int si3 = 0; si3 < 2; si3++) {	// L836
        #pragma HLS pipeline II=1
          float v571 = local_C3[si3][sj3];	// L837
          v555[((mi3 * 2) + si3)][((ni3 * 2) + sj3)] = v571;	// L838
        }
      }
    }
  }
}

void RoPE(
  float v572[64][32],
  float v573[64][2],
  float v574[64][2],
  float v575[64][32]
) {	// L845
  l_S_h_0_h: for (int h = 0; h < 8; h++) {	// L847
    float X_1_h[64][2];	// L848
    float X_2_h[64][2];	// L849
    l_rope_split_1_i6: for (int i6 = 0; i6 < 64; i6++) {	// L850
      l_j4: for (int j4 = 0; j4 < 2; j4++) {	// L851
        float v581 = v572[i6][((h * 4) + j4)];	// L852
        X_1_h[i6][j4] = v581;	// L853
      }
    }
    l_rope_split_2_i7: for (int i7 = 0; i7 < 64; i7++) {	// L856
      l_j5: for (int j5 = 0; j5 < 2; j5++) {	// L857
        float v584 = v572[i7][(((h * 4) + j5) + 2)];	// L858
        X_2_h[i7][j5] = v584;	// L859
      }
    }
    float X_1_rotary[64][2];	// L864
    for (int v586 = 0; v586 < 64; v586++) {	// L865
      for (int v587 = 0; v587 < 2; v587++) {	// L865
        X_1_rotary[v586][v587] = 0.000000;	// L865
      }
    }
    float X_2_rotary[64][2];	// L866
    for (int v589 = 0; v589 < 64; v589++) {	// L867
      for (int v590 = 0; v590 < 2; v590++) {	// L867
        X_2_rotary[v589][v590] = 0.000000;	// L867
      }
    }
    l_rotary_1_i8: for (int i8 = 0; i8 < 64; i8++) {	// L868
      l_j6: for (int j6 = 0; j6 < 2; j6++) {	// L869
        float v593 = v573[i8][j6];	// L870
        float v594 = X_1_h[i8][j6];	// L871
        float v595 = v593 * v594;	// L872
        float v596 = v574[i8][j6];	// L873
        float v597 = X_2_h[i8][j6];	// L874
        float v598 = v596 * v597;	// L875
        float v599 = v595 - v598;	// L876
        X_1_rotary[i8][j6] = v599;	// L877
      }
    }
    l_rotary_2_i9: for (int i9 = 0; i9 < 64; i9++) {	// L880
      l_j7: for (int j7 = 0; j7 < 2; j7++) {	// L881
        float v602 = v574[i9][j7];	// L882
        float v603 = X_1_h[i9][j7];	// L883
        float v604 = v602 * v603;	// L884
        float v605 = v573[i9][j7];	// L885
        float v606 = X_2_h[i9][j7];	// L886
        float v607 = v605 * v606;	// L887
        float v608 = v604 + v607;	// L888
        X_2_rotary[i9][j7] = v608;	// L889
      }
    }
    l_rotary_merge_1_i10: for (int i10 = 0; i10 < 64; i10++) {	// L892
      l_j8: for (int j8 = 0; j8 < 2; j8++) {	// L893
        float v611 = X_1_rotary[i10][j8];	// L894
        v575[i10][((h * 4) + j8)] = v611;	// L895
      }
    }
    l_rotary_merge_2_i11: for (int i11 = 0; i11 < 64; i11++) {	// L898
      l_j9: for (int j9 = 0; j9 < 2; j9++) {	// L899
        float v614 = X_2_rotary[i11][j9];	// L900
        v575[i11][(((h * 4) + j9) + 2)] = v614;	// L901
      }
    }
  }
}

void PE_kernel_QKT_0_0(
  hls::stream< float > &v615 /* v615[4] */,
  hls::stream< float > &v616 /* v616[4] */,
  hls::stream< float > &v617 /* v617[4] */,
  hls::stream< float > &v618 /* v618[4] */,
  float v619[2][2],
  int v620,
  int v621
) {	// L907
  #pragma HLS stream variable=v615 depth=3
  #pragma HLS stream variable=v616 depth=3
  #pragma HLS stream variable=v617 depth=3
  #pragma HLS stream variable=v618 depth=3
  #pragma HLS array_partition variable=v619 complete dim=1
  #pragma HLS array_partition variable=v619 complete dim=2

  float v14;	// L910
  v14 = 0.000000;	// L911
  l_S_k_0_k22: for (int k22 = 0; k22 < 4; k22++) {	// L912
    float v624 = v615.read(); // v615[k22];	// L913
    float a14;	// L914
    a14 = v624;	// L915
    float v626 = v616.read(); // v616[k22];	// L916
    float b14;	// L917
    b14 = v626;	// L918
    float v628 = a14;	// L919
    float v629 = b14;	// L920
    float v630 = v628 * v629;	// L921
    float v631 = v14;	// L922
    float v632 = v631 + v630;	// L923
    v14 = v632;	// L924
    float v633 = a14;	// L925
    v617.write(v633); // v617[k22] = v633;	// L926
    float v634 = b14;	// L927
    v618.write(v634); // v618[k22] = v634;	// L928
  }
  float v635 = v14;	// L930
  v619[v620][v621] = v635;	// L931
}

void PE_kernel_QKT_1_0(
  hls::stream< float > &v636 /* v636[4] */,
  hls::stream< float > &v637 /* v637[4] */,
  hls::stream< float > &v638 /* v638[4] */,
  hls::stream< float > &v639 /* v639[4] */,
  float v640[2][2],
  int v641,
  int v642
) {	// L934
  #pragma HLS stream variable=v636 depth=3
  #pragma HLS stream variable=v637 depth=3
  #pragma HLS stream variable=v638 depth=3
  #pragma HLS stream variable=v639 depth=3
  #pragma HLS array_partition variable=v640 complete dim=1
  #pragma HLS array_partition variable=v640 complete dim=2

  float v15;	// L937
  v15 = 0.000000;	// L938
  l_S_k_0_k23: for (int k23 = 0; k23 < 4; k23++) {	// L939
    float v645 = v636.read(); // v636[k23];	// L940
    float a15;	// L941
    a15 = v645;	// L942
    float v647 = v637.read(); // v637[k23];	// L943
    float b15;	// L944
    b15 = v647;	// L945
    float v649 = a15;	// L946
    float v650 = b15;	// L947
    float v651 = v649 * v650;	// L948
    float v652 = v15;	// L949
    float v653 = v652 + v651;	// L950
    v15 = v653;	// L951
    float v654 = a15;	// L952
    v638.write(v654); // v638[k23] = v654;	// L953
    float v655 = b15;	// L954
    v639.write(v655); // v639[k23] = v655;	// L955
  }
  float v656 = v15;	// L957
  v640[v641][v642] = v656;	// L958
}

void PE_kernel_QKT_0_1(
  hls::stream< float > &v657 /* v657[4] */,
  hls::stream< float > &v658 /* v658[4] */,
  hls::stream< float > &v659 /* v659[4] */,
  hls::stream< float > &v660 /* v660[4] */,
  float v661[2][2],
  int v662,
  int v663
) {	// L961
  #pragma HLS stream variable=v657 depth=3
  #pragma HLS stream variable=v658 depth=3
  #pragma HLS stream variable=v659 depth=3
  #pragma HLS stream variable=v660 depth=3
  #pragma HLS array_partition variable=v661 complete dim=1
  #pragma HLS array_partition variable=v661 complete dim=2

  float v16;	// L964
  v16 = 0.000000;	// L965
  l_S_k_0_k24: for (int k24 = 0; k24 < 4; k24++) {	// L966
    float v666 = v657.read(); // v657[k24];	// L967
    float a16;	// L968
    a16 = v666;	// L969
    float v668 = v658.read(); // v658[k24];	// L970
    float b16;	// L971
    b16 = v668;	// L972
    float v670 = a16;	// L973
    float v671 = b16;	// L974
    float v672 = v670 * v671;	// L975
    float v673 = v16;	// L976
    float v674 = v673 + v672;	// L977
    v16 = v674;	// L978
    float v675 = a16;	// L979
    v659.write(v675); // v659[k24] = v675;	// L980
    float v676 = b16;	// L981
    v660.write(v676); // v660[k24] = v676;	// L982
  }
  float v677 = v16;	// L984
  v661[v662][v663] = v677;	// L985
}

void PE_kernel_QKT_1_1(
  hls::stream< float > &v678 /* v678[4] */,
  hls::stream< float > &v679 /* v679[4] */,
  hls::stream< float > &v680 /* v680[4] */,
  hls::stream< float > &v681 /* v681[4] */,
  float v682[2][2],
  int v683,
  int v684
) {	// L988
  #pragma HLS stream variable=v678 depth=3
  #pragma HLS stream variable=v679 depth=3
  #pragma HLS stream variable=v680 depth=3
  #pragma HLS stream variable=v681 depth=3
  #pragma HLS array_partition variable=v682 complete dim=1
  #pragma HLS array_partition variable=v682 complete dim=2

  float v17;	// L991
  v17 = 0.000000;	// L992
  l_S_k_0_k25: for (int k25 = 0; k25 < 4; k25++) {	// L993
    float v687 = v678.read(); // v678[k25];	// L994
    float a17;	// L995
    a17 = v687;	// L996
    float v689 = v679.read(); // v679[k25];	// L997
    float b17;	// L998
    b17 = v689;	// L999
    float v691 = a17;	// L1000
    float v692 = b17;	// L1001
    float v693 = v691 * v692;	// L1002
    float v694 = v17;	// L1003
    float v695 = v694 + v693;	// L1004
    v17 = v695;	// L1005
    float v696 = a17;	// L1006
    v680.write(v696); // v680[k25] = v696;	// L1007
    float v697 = b17;	// L1008
    v681.write(v697); // v681[k25] = v697;	// L1009
  }
  float v698 = v17;	// L1011
  v682[v683][v684] = v698;	// L1012
}

void systolic_tile_QKT(
  float v699[2][4],
  float v700[4][2],
  float v701[2][2]
) {	// L1015
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v699 complete dim=1

  #pragma HLS array_partition variable=v700 complete dim=2

  #pragma HLS array_partition variable=v701 complete dim=1
  #pragma HLS array_partition variable=v701 complete dim=2

  hls::stream< float > A_fifo4[2][3] /* A_fifo4[2][3][4] */;	// L1016
  #pragma HLS stream variable=A_fifo4 depth=3
  hls::stream< float > B_fifo4[2][3] /* B_fifo4[2][3][4] */;	// L1017
  #pragma HLS stream variable=B_fifo4 depth=3
  float A_drain4[2];	// L1018
  float B_drain4[2];	// L1019
  l_data_load_k26: for (int k26 = 0; k26 < 4; k26++) {	// L1020
    l_S_m_0_m8: for (int m8 = 0; m8 < 2; m8++) {	// L1021
      float v708 = v699[m8][k26];	// L1022
      A_fifo4[m8][0].write(v708); // A_fifo4[m8][0][k26] = v708;	// L1023
    }
    l_S_n_1_n8: for (int n8 = 0; n8 < 2; n8++) {	// L1025
      float v710 = v700[k26][n8];	// L1026
      B_fifo4[n8][0].write(v710); // B_fifo4[n8][0][k26] = v710;	// L1027
    }
  }
  hls::stream< float > &v711 /* v711[4] */ = A_fifo4[0][0];	// L1031
  hls::stream< float > &v712 /* v712[4] */ = B_fifo4[0][0];	// L1032
  hls::stream< float > &v713 /* v713[4] */ = A_fifo4[0][1];	// L1038
  hls::stream< float > &v714 /* v714[4] */ = B_fifo4[0][1];	// L1039
  PE_kernel_QKT_0_0(v711, v712, v713, v714, v701, 0, 0);	// L1040
  hls::stream< float > &v715 /* v715[4] */ = A_fifo4[0][1];	// L1042
  hls::stream< float > &v716 /* v716[4] */ = B_fifo4[1][0];	// L1043
  hls::stream< float > &v717 /* v717[4] */ = A_fifo4[0][2];	// L1047
  hls::stream< float > &v718 /* v718[4] */ = B_fifo4[1][1];	// L1048
  PE_kernel_QKT_1_0(v715, v716, v717, v718, v701, 0, 1);	// L1049
  hls::stream< float > &v719 /* v719[4] */ = A_fifo4[1][0];	// L1050
  hls::stream< float > &v720 /* v720[4] */ = B_fifo4[0][1];	// L1051
  hls::stream< float > &v721 /* v721[4] */ = A_fifo4[1][1];	// L1052
  hls::stream< float > &v722 /* v722[4] */ = B_fifo4[0][2];	// L1053
  PE_kernel_QKT_0_1(v719, v720, v721, v722, v701, 1, 0);	// L1054
  hls::stream< float > &v723 /* v723[4] */ = A_fifo4[1][1];	// L1055
  hls::stream< float > &v724 /* v724[4] */ = B_fifo4[1][1];	// L1056
  hls::stream< float > &v725 /* v725[4] */ = A_fifo4[1][2];	// L1057
  hls::stream< float > &v726 /* v726[4] */ = B_fifo4[1][2];	// L1058
  PE_kernel_QKT_1_1(v723, v724, v725, v726, v701, 1, 1);	// L1059
  l_data_drain_k27: for (int k27 = 0; k27 < 4; k27++) {	// L1060
    l_S_m_4_m9: for (int m9 = 0; m9 < 2; m9++) {	// L1061
      float v729 = A_fifo4[m9][2].read(); // A_fifo4[m9][2][k27];	// L1062
      A_drain4[m9] = v729;	// L1063
    }
    l_S_n_5_n9: for (int n9 = 0; n9 < 2; n9++) {	// L1065
      float v731 = B_fifo4[n9][2].read(); // B_fifo4[n9][2][k27];	// L1066
      B_drain4[n9] = v731;	// L1067
    }
  }
}

void systolic_QKT(
  float v732[64][4],
  float v733[4][64],
  float v734[64][64]
) {	// L1072
  float local_A4[2][4];	// L1073
  #pragma HLS array_partition variable=local_A4 complete dim=1

  float local_B4[4][2];	// L1074
  #pragma HLS array_partition variable=local_B4 complete dim=2

  float local_C4[2][2];	// L1075
  #pragma HLS array_partition variable=local_C4 complete dim=1
  #pragma HLS array_partition variable=local_C4 complete dim=2

  l_outer_tile_mi4: for (int mi4 = 0; mi4 < 32; mi4++) {	// L1076
    l_ni4: for (int ni4 = 0; ni4 < 32; ni4++) {	// L1077
    #pragma HLS dataflow
      l_load_A_tile_ak4: for (int ak4 = 0; ak4 < 4; ak4++) {	// L1078
        l_ai4: for (int ai4 = 0; ai4 < 2; ai4++) {	// L1079
        #pragma HLS pipeline II=1
          ap_int<33> v742 = ni4;	// L1080
          bool v743 = v742 == 0;	// L1083
          if (v743) {	// L1084
            float v744 = v732[((mi4 * 2) + ai4)][ak4];	// L1085
            local_A4[ai4][ak4] = v744;	// L1086
          }
        }
      }
      l_load_B_tile_bk4: for (int bk4 = 0; bk4 < 4; bk4++) {	// L1090
        l_bj4: for (int bj4 = 0; bj4 < 2; bj4++) {	// L1091
        #pragma HLS pipeline II=1
          float v747 = v733[bk4][((ni4 * 2) + bj4)];	// L1092
          local_B4[bk4][bj4] = v747;	// L1093
        }
      }
      systolic_tile_QKT(local_A4, local_B4, local_C4);	// L1096
      l_store_C_tile_sj4: for (int sj4 = 0; sj4 < 2; sj4++) {	// L1097
        l_si4: for (int si4 = 0; si4 < 2; si4++) {	// L1098
        #pragma HLS pipeline II=1
          float v750 = local_C4[si4][sj4];	// L1099
          v734[((mi4 * 2) + si4)][((ni4 * 2) + sj4)] = v750;	// L1100
        }
      }
    }
  }
}

void sft_head(
  float v751[64][64],
  float v752[64][64]
) {	// L1107
  float E[64][64];	// L1109
  float M[64];	// L1112
  for (int v755 = 0; v755 < 64; v755++) {	// L1113
    M[v755] = -100000000.000000;	// L1113
  }
  float S[64];	// L1114
  for (int v757 = 0; v757 < 64; v757++) {	// L1116
    S[v757] = 0.000000;	// L1116
  }
  l_row_max_i12: for (int i12 = 0; i12 < 64; i12++) {	// L1117
    l_j10: for (int j10 = 0; j10 < 64; j10++) {	// L1118
      float v760 = v751[i12][j10];	// L1119
      float v761 = M[i12];	// L1120
      bool v762 = v760 > v761;	// L1121
      if (v762) {	// L1122
        float v763 = v751[i12][j10];	// L1123
        M[i12] = v763;	// L1124
      }
    }
  }
  l_exp_sum_i13: for (int i13 = 0; i13 < 64; i13++) {	// L1128
    l_j11: for (int j11 = 0; j11 < 64; j11++) {	// L1129
      float v766 = v751[i13][j11];	// L1130
      float v767 = M[i13];	// L1131
      float v768 = v766 - v767;	// L1132
      float v769 = exp(v768);	// L1133
      E[i13][j11] = v769;	// L1134
      float v770 = E[i13][j11];	// L1135
      float v771 = S[i13];	// L1136
      float v772 = v771 + v770;	// L1137
      S[i13] = v772;	// L1138
    }
  }
  l_update_i14: for (int i14 = 0; i14 < 64; i14++) {	// L1141
    l_j12: for (int j12 = 0; j12 < 64; j12++) {	// L1142
      float v775 = E[i14][j12];	// L1143
      float v776 = S[i14];	// L1144
      float v777 = v775 / v776;	// L1145
      v752[i14][j12] = v777;	// L1146
    }
  }
}

void PE_kernel_YV_0_0(
  hls::stream< float > &v778 /* v778[64] */,
  hls::stream< float > &v779 /* v779[64] */,
  hls::stream< float > &v780 /* v780[64] */,
  hls::stream< float > &v781 /* v781[64] */,
  float v782[2][2],
  int v783,
  int v784
) {	// L1151
  #pragma HLS stream variable=v778 depth=3
  #pragma HLS stream variable=v779 depth=3
  #pragma HLS stream variable=v780 depth=3
  #pragma HLS stream variable=v781 depth=3
  #pragma HLS array_partition variable=v782 complete dim=1
  #pragma HLS array_partition variable=v782 complete dim=2

  float v18;	// L1154
  v18 = 0.000000;	// L1155
  l_S_k_0_k28: for (int k28 = 0; k28 < 64; k28++) {	// L1156
    float v787 = v778.read(); // v778[k28];	// L1157
    float a18;	// L1158
    a18 = v787;	// L1159
    float v789 = v779.read(); // v779[k28];	// L1160
    float b18;	// L1161
    b18 = v789;	// L1162
    float v791 = a18;	// L1163
    float v792 = b18;	// L1164
    float v793 = v791 * v792;	// L1165
    float v794 = v18;	// L1166
    float v795 = v794 + v793;	// L1167
    v18 = v795;	// L1168
    float v796 = a18;	// L1169
    v780.write(v796); // v780[k28] = v796;	// L1170
    float v797 = b18;	// L1171
    v781.write(v797); // v781[k28] = v797;	// L1172
  }
  float v798 = v18;	// L1174
  v782[v783][v784] = v798;	// L1175
}

void PE_kernel_YV_1_0(
  hls::stream< float > &v799 /* v799[64] */,
  hls::stream< float > &v800 /* v800[64] */,
  hls::stream< float > &v801 /* v801[64] */,
  hls::stream< float > &v802 /* v802[64] */,
  float v803[2][2],
  int v804,
  int v805
) {	// L1178
  #pragma HLS stream variable=v799 depth=3
  #pragma HLS stream variable=v800 depth=3
  #pragma HLS stream variable=v801 depth=3
  #pragma HLS stream variable=v802 depth=3
  #pragma HLS array_partition variable=v803 complete dim=1
  #pragma HLS array_partition variable=v803 complete dim=2

  float v19;	// L1181
  v19 = 0.000000;	// L1182
  l_S_k_0_k29: for (int k29 = 0; k29 < 64; k29++) {	// L1183
    float v808 = v799.read(); // v799[k29];	// L1184
    float a19;	// L1185
    a19 = v808;	// L1186
    float v810 = v800.read(); // v800[k29];	// L1187
    float b19;	// L1188
    b19 = v810;	// L1189
    float v812 = a19;	// L1190
    float v813 = b19;	// L1191
    float v814 = v812 * v813;	// L1192
    float v815 = v19;	// L1193
    float v816 = v815 + v814;	// L1194
    v19 = v816;	// L1195
    float v817 = a19;	// L1196
    v801.write(v817); // v801[k29] = v817;	// L1197
    float v818 = b19;	// L1198
    v802.write(v818); // v802[k29] = v818;	// L1199
  }
  float v819 = v19;	// L1201
  v803[v804][v805] = v819;	// L1202
}

void PE_kernel_YV_0_1(
  hls::stream< float > &v820 /* v820[64] */,
  hls::stream< float > &v821 /* v821[64] */,
  hls::stream< float > &v822 /* v822[64] */,
  hls::stream< float > &v823 /* v823[64] */,
  float v824[2][2],
  int v825,
  int v826
) {	// L1205
  #pragma HLS stream variable=v820 depth=3
  #pragma HLS stream variable=v821 depth=3
  #pragma HLS stream variable=v822 depth=3
  #pragma HLS stream variable=v823 depth=3
  #pragma HLS array_partition variable=v824 complete dim=1
  #pragma HLS array_partition variable=v824 complete dim=2

  float v20;	// L1208
  v20 = 0.000000;	// L1209
  l_S_k_0_k30: for (int k30 = 0; k30 < 64; k30++) {	// L1210
    float v829 = v820.read(); // v820[k30];	// L1211
    float a20;	// L1212
    a20 = v829;	// L1213
    float v831 = v821.read(); // v821[k30];	// L1214
    float b20;	// L1215
    b20 = v831;	// L1216
    float v833 = a20;	// L1217
    float v834 = b20;	// L1218
    float v835 = v833 * v834;	// L1219
    float v836 = v20;	// L1220
    float v837 = v836 + v835;	// L1221
    v20 = v837;	// L1222
    float v838 = a20;	// L1223
    v822.write(v838); // v822[k30] = v838;	// L1224
    float v839 = b20;	// L1225
    v823.write(v839); // v823[k30] = v839;	// L1226
  }
  float v840 = v20;	// L1228
  v824[v825][v826] = v840;	// L1229
}

void PE_kernel_YV_1_1(
  hls::stream< float > &v841 /* v841[64] */,
  hls::stream< float > &v842 /* v842[64] */,
  hls::stream< float > &v843 /* v843[64] */,
  hls::stream< float > &v844 /* v844[64] */,
  float v845[2][2],
  int v846,
  int v847
) {	// L1232
  #pragma HLS stream variable=v841 depth=3
  #pragma HLS stream variable=v842 depth=3
  #pragma HLS stream variable=v843 depth=3
  #pragma HLS stream variable=v844 depth=3
  #pragma HLS array_partition variable=v845 complete dim=1
  #pragma HLS array_partition variable=v845 complete dim=2

  float v21;	// L1235
  v21 = 0.000000;	// L1236
  l_S_k_0_k31: for (int k31 = 0; k31 < 64; k31++) {	// L1237
    float v850 = v841.read(); // v841[k31];	// L1238
    float a21;	// L1239
    a21 = v850;	// L1240
    float v852 = v842.read(); // v842[k31];	// L1241
    float b21;	// L1242
    b21 = v852;	// L1243
    float v854 = a21;	// L1244
    float v855 = b21;	// L1245
    float v856 = v854 * v855;	// L1246
    float v857 = v21;	// L1247
    float v858 = v857 + v856;	// L1248
    v21 = v858;	// L1249
    float v859 = a21;	// L1250
    v843.write(v859); // v843[k31] = v859;	// L1251
    float v860 = b21;	// L1252
    v844.write(v860); // v844[k31] = v860;	// L1253
  }
  float v861 = v21;	// L1255
  v845[v846][v847] = v861;	// L1256
}

void systolic_tile_YV(
  float v862[2][64],
  float v863[64][2],
  float v864[2][2]
) {	// L1259
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v862 complete dim=1

  #pragma HLS array_partition variable=v863 complete dim=2

  #pragma HLS array_partition variable=v864 complete dim=1
  #pragma HLS array_partition variable=v864 complete dim=2

  hls::stream< float > A_fifo5[2][3] /* A_fifo5[2][3][64] */;	// L1260
  #pragma HLS stream variable=A_fifo5 depth=3
  hls::stream< float > B_fifo5[2][3] /* B_fifo5[2][3][64] */;	// L1261
  #pragma HLS stream variable=B_fifo5 depth=3
  float A_drain5[2];	// L1262
  float B_drain5[2];	// L1263
  l_data_load_k32: for (int k32 = 0; k32 < 64; k32++) {	// L1264
    l_S_m_0_m10: for (int m10 = 0; m10 < 2; m10++) {	// L1265
      float v871 = v862[m10][k32];	// L1266
      A_fifo5[m10][0].write(v871); // A_fifo5[m10][0][k32] = v871;	// L1267
    }
    l_S_n_1_n10: for (int n10 = 0; n10 < 2; n10++) {	// L1269
      float v873 = v863[k32][n10];	// L1270
      B_fifo5[n10][0].write(v873); // B_fifo5[n10][0][k32] = v873;	// L1271
    }
  }
  hls::stream< float > &v874 /* v874[64] */ = A_fifo5[0][0];	// L1275
  hls::stream< float > &v875 /* v875[64] */ = B_fifo5[0][0];	// L1276
  hls::stream< float > &v876 /* v876[64] */ = A_fifo5[0][1];	// L1282
  hls::stream< float > &v877 /* v877[64] */ = B_fifo5[0][1];	// L1283
  PE_kernel_YV_0_0(v874, v875, v876, v877, v864, 0, 0);	// L1284
  hls::stream< float > &v878 /* v878[64] */ = A_fifo5[0][1];	// L1286
  hls::stream< float > &v879 /* v879[64] */ = B_fifo5[1][0];	// L1287
  hls::stream< float > &v880 /* v880[64] */ = A_fifo5[0][2];	// L1291
  hls::stream< float > &v881 /* v881[64] */ = B_fifo5[1][1];	// L1292
  PE_kernel_YV_1_0(v878, v879, v880, v881, v864, 0, 1);	// L1293
  hls::stream< float > &v882 /* v882[64] */ = A_fifo5[1][0];	// L1294
  hls::stream< float > &v883 /* v883[64] */ = B_fifo5[0][1];	// L1295
  hls::stream< float > &v884 /* v884[64] */ = A_fifo5[1][1];	// L1296
  hls::stream< float > &v885 /* v885[64] */ = B_fifo5[0][2];	// L1297
  PE_kernel_YV_0_1(v882, v883, v884, v885, v864, 1, 0);	// L1298
  hls::stream< float > &v886 /* v886[64] */ = A_fifo5[1][1];	// L1299
  hls::stream< float > &v887 /* v887[64] */ = B_fifo5[1][1];	// L1300
  hls::stream< float > &v888 /* v888[64] */ = A_fifo5[1][2];	// L1301
  hls::stream< float > &v889 /* v889[64] */ = B_fifo5[1][2];	// L1302
  PE_kernel_YV_1_1(v886, v887, v888, v889, v864, 1, 1);	// L1303
  l_data_drain_k33: for (int k33 = 0; k33 < 64; k33++) {	// L1304
    l_S_m_4_m11: for (int m11 = 0; m11 < 2; m11++) {	// L1305
      float v892 = A_fifo5[m11][2].read(); // A_fifo5[m11][2][k33];	// L1306
      A_drain5[m11] = v892;	// L1307
    }
    l_S_n_5_n11: for (int n11 = 0; n11 < 2; n11++) {	// L1309
      float v894 = B_fifo5[n11][2].read(); // B_fifo5[n11][2][k33];	// L1310
      B_drain5[n11] = v894;	// L1311
    }
  }
}

void systolic_YV(
  float v895[64][64],
  float v896[64][4],
  float v897[64][4]
) {	// L1316
  float local_A5[2][64];	// L1317
  #pragma HLS array_partition variable=local_A5 complete dim=1

  float local_B5[64][2];	// L1318
  #pragma HLS array_partition variable=local_B5 complete dim=2

  float local_C5[2][2];	// L1319
  #pragma HLS array_partition variable=local_C5 complete dim=1
  #pragma HLS array_partition variable=local_C5 complete dim=2

  l_outer_tile_mi5: for (int mi5 = 0; mi5 < 32; mi5++) {	// L1320
    l_ni5: for (int ni5 = 0; ni5 < 2; ni5++) {	// L1321
    #pragma HLS dataflow
      l_load_A_tile_ak5: for (int ak5 = 0; ak5 < 64; ak5++) {	// L1322
        l_ai5: for (int ai5 = 0; ai5 < 2; ai5++) {	// L1323
        #pragma HLS pipeline II=1
          ap_int<33> v905 = ni5;	// L1324
          bool v906 = v905 == 0;	// L1327
          if (v906) {	// L1328
            float v907 = v895[((mi5 * 2) + ai5)][ak5];	// L1329
            local_A5[ai5][ak5] = v907;	// L1330
          }
        }
      }
      l_load_B_tile_bk5: for (int bk5 = 0; bk5 < 64; bk5++) {	// L1334
        l_bj5: for (int bj5 = 0; bj5 < 2; bj5++) {	// L1335
        #pragma HLS pipeline II=1
          float v910 = v896[bk5][((ni5 * 2) + bj5)];	// L1336
          local_B5[bk5][bj5] = v910;	// L1337
        }
      }
      systolic_tile_YV(local_A5, local_B5, local_C5);	// L1340
      l_store_C_tile_sj5: for (int sj5 = 0; sj5 < 2; sj5++) {	// L1341
        l_si5: for (int si5 = 0; si5 < 2; si5++) {	// L1342
        #pragma HLS pipeline II=1
          float v913 = local_C5[si5][sj5];	// L1343
          v897[((mi5 * 2) + si5)][((ni5 * 2) + sj5)] = v913;	// L1344
        }
      }
    }
  }
}

void scaled_dot_product_attention(
  float v914[64][32],
  float v915[64][32],
  float v916[64][32],
  float v917[64][32]
) {	// L1351
  l_S_h_0_h1: for (int h1 = 0; h1 < 8; h1++) {	// L1353
    float Q_h[64][4];	// L1354
    float K_h[4][64];	// L1355
    float V_h[64][4];	// L1356
    l_mha_split_i15: for (int i15 = 0; i15 < 64; i15++) {	// L1357
      l_j13: for (int j13 = 0; j13 < 4; j13++) {	// L1358
        float v924 = v914[i15][((h1 * 4) + j13)];	// L1359
        Q_h[i15][j13] = v924;	// L1360
        float v925 = v915[i15][((h1 * 4) + j13)];	// L1361
        K_h[j13][i15] = v925;	// L1362
        float v926 = v916[i15][((h1 * 4) + j13)];	// L1363
        V_h[i15][j13] = v926;	// L1364
      }
    }
    float C_h[64][4];	// L1369
    for (int v928 = 0; v928 < 64; v928++) {	// L1370
      for (int v929 = 0; v929 < 4; v929++) {	// L1370
        C_h[v928][v929] = 0.000000;	// L1370
      }
    }
    float Y1[64][64];	// L1371
    for (int v931 = 0; v931 < 64; v931++) {	// L1372
      for (int v932 = 0; v932 < 64; v932++) {	// L1372
        Y1[v931][v932] = 0.000000;	// L1372
      }
    }
    systolic_QKT(Q_h, K_h, Y1);	// L1373
    float Y_t[64][64];	// L1374
    for (int v934 = 0; v934 < 64; v934++) {	// L1375
      for (int v935 = 0; v935 < 64; v935++) {	// L1375
        Y_t[v934][v935] = 0.000000;	// L1375
      }
    }
    l_mha_scale_i16: for (int i16 = 0; i16 < 64; i16++) {	// L1376
      l_j14: for (int j14 = 0; j14 < 64; j14++) {	// L1377
        float v938 = Y1[i16][j14];	// L1378
        float v939 = v938 / 2.000000;	// L1380
        Y_t[i16][j14] = v939;	// L1381
      }
    }
    float v940[64][64];
    sft_head(Y_t, v940);	// L1384
    systolic_YV(v940, V_h, C_h);	// L1385
    l_mha_merge_i17: for (int i17 = 0; i17 < 64; i17++) {	// L1386
      l_j15: for (int j15 = 0; j15 < 4; j15++) {	// L1387
        float v943 = C_h[i17][j15];	// L1388
        v917[i17][((h1 * 4) + j15)] = v943;	// L1389
      }
    }
  }
}

void PE_kernel_attn_out_0_0(
  hls::stream< float > &v944 /* v944[32] */,
  hls::stream< float > &v945 /* v945[32] */,
  hls::stream< float > &v946 /* v946[32] */,
  hls::stream< float > &v947 /* v947[32] */,
  float v948[2][2],
  int v949,
  int v950
) {	// L1395
  #pragma HLS stream variable=v944 depth=3
  #pragma HLS stream variable=v945 depth=3
  #pragma HLS stream variable=v946 depth=3
  #pragma HLS stream variable=v947 depth=3
  #pragma HLS array_partition variable=v948 complete dim=1
  #pragma HLS array_partition variable=v948 complete dim=2

  float v22;	// L1398
  v22 = 0.000000;	// L1399
  l_S_k_0_k34: for (int k34 = 0; k34 < 32; k34++) {	// L1400
    float v953 = v944.read(); // v944[k34];	// L1401
    float a22;	// L1402
    a22 = v953;	// L1403
    float v955 = v945.read(); // v945[k34];	// L1404
    float b22;	// L1405
    b22 = v955;	// L1406
    float v957 = a22;	// L1407
    float v958 = b22;	// L1408
    float v959 = v957 * v958;	// L1409
    float v960 = v22;	// L1410
    float v961 = v960 + v959;	// L1411
    v22 = v961;	// L1412
    float v962 = a22;	// L1413
    v946.write(v962); // v946[k34] = v962;	// L1414
    float v963 = b22;	// L1415
    v947.write(v963); // v947[k34] = v963;	// L1416
  }
  float v964 = v22;	// L1418
  v948[v949][v950] = v964;	// L1419
}

void PE_kernel_attn_out_1_0(
  hls::stream< float > &v965 /* v965[32] */,
  hls::stream< float > &v966 /* v966[32] */,
  hls::stream< float > &v967 /* v967[32] */,
  hls::stream< float > &v968 /* v968[32] */,
  float v969[2][2],
  int v970,
  int v971
) {	// L1422
  #pragma HLS stream variable=v965 depth=3
  #pragma HLS stream variable=v966 depth=3
  #pragma HLS stream variable=v967 depth=3
  #pragma HLS stream variable=v968 depth=3
  #pragma HLS array_partition variable=v969 complete dim=1
  #pragma HLS array_partition variable=v969 complete dim=2

  float v23;	// L1425
  v23 = 0.000000;	// L1426
  l_S_k_0_k35: for (int k35 = 0; k35 < 32; k35++) {	// L1427
    float v974 = v965.read(); // v965[k35];	// L1428
    float a23;	// L1429
    a23 = v974;	// L1430
    float v976 = v966.read(); // v966[k35];	// L1431
    float b23;	// L1432
    b23 = v976;	// L1433
    float v978 = a23;	// L1434
    float v979 = b23;	// L1435
    float v980 = v978 * v979;	// L1436
    float v981 = v23;	// L1437
    float v982 = v981 + v980;	// L1438
    v23 = v982;	// L1439
    float v983 = a23;	// L1440
    v967.write(v983); // v967[k35] = v983;	// L1441
    float v984 = b23;	// L1442
    v968.write(v984); // v968[k35] = v984;	// L1443
  }
  float v985 = v23;	// L1445
  v969[v970][v971] = v985;	// L1446
}

void PE_kernel_attn_out_0_1(
  hls::stream< float > &v986 /* v986[32] */,
  hls::stream< float > &v987 /* v987[32] */,
  hls::stream< float > &v988 /* v988[32] */,
  hls::stream< float > &v989 /* v989[32] */,
  float v990[2][2],
  int v991,
  int v992
) {	// L1449
  #pragma HLS stream variable=v986 depth=3
  #pragma HLS stream variable=v987 depth=3
  #pragma HLS stream variable=v988 depth=3
  #pragma HLS stream variable=v989 depth=3
  #pragma HLS array_partition variable=v990 complete dim=1
  #pragma HLS array_partition variable=v990 complete dim=2

  float v24;	// L1452
  v24 = 0.000000;	// L1453
  l_S_k_0_k36: for (int k36 = 0; k36 < 32; k36++) {	// L1454
    float v995 = v986.read(); // v986[k36];	// L1455
    float a24;	// L1456
    a24 = v995;	// L1457
    float v997 = v987.read(); // v987[k36];	// L1458
    float b24;	// L1459
    b24 = v997;	// L1460
    float v999 = a24;	// L1461
    float v1000 = b24;	// L1462
    float v1001 = v999 * v1000;	// L1463
    float v1002 = v24;	// L1464
    float v1003 = v1002 + v1001;	// L1465
    v24 = v1003;	// L1466
    float v1004 = a24;	// L1467
    v988.write(v1004); // v988[k36] = v1004;	// L1468
    float v1005 = b24;	// L1469
    v989.write(v1005); // v989[k36] = v1005;	// L1470
  }
  float v1006 = v24;	// L1472
  v990[v991][v992] = v1006;	// L1473
}

void PE_kernel_attn_out_1_1(
  hls::stream< float > &v1007 /* v1007[32] */,
  hls::stream< float > &v1008 /* v1008[32] */,
  hls::stream< float > &v1009 /* v1009[32] */,
  hls::stream< float > &v1010 /* v1010[32] */,
  float v1011[2][2],
  int v1012,
  int v1013
) {	// L1476
  #pragma HLS stream variable=v1007 depth=3
  #pragma HLS stream variable=v1008 depth=3
  #pragma HLS stream variable=v1009 depth=3
  #pragma HLS stream variable=v1010 depth=3
  #pragma HLS array_partition variable=v1011 complete dim=1
  #pragma HLS array_partition variable=v1011 complete dim=2

  float v25;	// L1479
  v25 = 0.000000;	// L1480
  l_S_k_0_k37: for (int k37 = 0; k37 < 32; k37++) {	// L1481
    float v1016 = v1007.read(); // v1007[k37];	// L1482
    float a25;	// L1483
    a25 = v1016;	// L1484
    float v1018 = v1008.read(); // v1008[k37];	// L1485
    float b25;	// L1486
    b25 = v1018;	// L1487
    float v1020 = a25;	// L1488
    float v1021 = b25;	// L1489
    float v1022 = v1020 * v1021;	// L1490
    float v1023 = v25;	// L1491
    float v1024 = v1023 + v1022;	// L1492
    v25 = v1024;	// L1493
    float v1025 = a25;	// L1494
    v1009.write(v1025); // v1009[k37] = v1025;	// L1495
    float v1026 = b25;	// L1496
    v1010.write(v1026); // v1010[k37] = v1026;	// L1497
  }
  float v1027 = v25;	// L1499
  v1011[v1012][v1013] = v1027;	// L1500
}

void systolic_tile_attn_out(
  float v1028[2][32],
  float v1029[32][2],
  float v1030[2][2]
) {	// L1503
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1028 complete dim=1

  #pragma HLS array_partition variable=v1029 complete dim=2

  #pragma HLS array_partition variable=v1030 complete dim=1
  #pragma HLS array_partition variable=v1030 complete dim=2

  hls::stream< float > A_fifo6[2][3] /* A_fifo6[2][3][32] */;	// L1504
  #pragma HLS stream variable=A_fifo6 depth=3
  hls::stream< float > B_fifo6[2][3] /* B_fifo6[2][3][32] */;	// L1505
  #pragma HLS stream variable=B_fifo6 depth=3
  float A_drain6[2];	// L1506
  float B_drain6[2];	// L1507
  l_data_load_k38: for (int k38 = 0; k38 < 32; k38++) {	// L1508
    l_S_m_0_m12: for (int m12 = 0; m12 < 2; m12++) {	// L1509
      float v1037 = v1028[m12][k38];	// L1510
      A_fifo6[m12][0].write(v1037); // A_fifo6[m12][0][k38] = v1037;	// L1511
    }
    l_S_n_1_n12: for (int n12 = 0; n12 < 2; n12++) {	// L1513
      float v1039 = v1029[k38][n12];	// L1514
      B_fifo6[n12][0].write(v1039); // B_fifo6[n12][0][k38] = v1039;	// L1515
    }
  }
  hls::stream< float > &v1040 /* v1040[32] */ = A_fifo6[0][0];	// L1519
  hls::stream< float > &v1041 /* v1041[32] */ = B_fifo6[0][0];	// L1520
  hls::stream< float > &v1042 /* v1042[32] */ = A_fifo6[0][1];	// L1526
  hls::stream< float > &v1043 /* v1043[32] */ = B_fifo6[0][1];	// L1527
  PE_kernel_attn_out_0_0(v1040, v1041, v1042, v1043, v1030, 0, 0);	// L1528
  hls::stream< float > &v1044 /* v1044[32] */ = A_fifo6[0][1];	// L1530
  hls::stream< float > &v1045 /* v1045[32] */ = B_fifo6[1][0];	// L1531
  hls::stream< float > &v1046 /* v1046[32] */ = A_fifo6[0][2];	// L1535
  hls::stream< float > &v1047 /* v1047[32] */ = B_fifo6[1][1];	// L1536
  PE_kernel_attn_out_1_0(v1044, v1045, v1046, v1047, v1030, 0, 1);	// L1537
  hls::stream< float > &v1048 /* v1048[32] */ = A_fifo6[1][0];	// L1538
  hls::stream< float > &v1049 /* v1049[32] */ = B_fifo6[0][1];	// L1539
  hls::stream< float > &v1050 /* v1050[32] */ = A_fifo6[1][1];	// L1540
  hls::stream< float > &v1051 /* v1051[32] */ = B_fifo6[0][2];	// L1541
  PE_kernel_attn_out_0_1(v1048, v1049, v1050, v1051, v1030, 1, 0);	// L1542
  hls::stream< float > &v1052 /* v1052[32] */ = A_fifo6[1][1];	// L1543
  hls::stream< float > &v1053 /* v1053[32] */ = B_fifo6[1][1];	// L1544
  hls::stream< float > &v1054 /* v1054[32] */ = A_fifo6[1][2];	// L1545
  hls::stream< float > &v1055 /* v1055[32] */ = B_fifo6[1][2];	// L1546
  PE_kernel_attn_out_1_1(v1052, v1053, v1054, v1055, v1030, 1, 1);	// L1547
  l_data_drain_k39: for (int k39 = 0; k39 < 32; k39++) {	// L1548
    l_S_m_4_m13: for (int m13 = 0; m13 < 2; m13++) {	// L1549
      float v1058 = A_fifo6[m13][2].read(); // A_fifo6[m13][2][k39];	// L1550
      A_drain6[m13] = v1058;	// L1551
    }
    l_S_n_5_n13: for (int n13 = 0; n13 < 2; n13++) {	// L1553
      float v1060 = B_fifo6[n13][2].read(); // B_fifo6[n13][2][k39];	// L1554
      B_drain6[n13] = v1060;	// L1555
    }
  }
}

void systolic_attn_out(
  float v1061[64][32],
  float v1062[32][32],
  float v1063[64][32]
) {	// L1560
  float local_A6[2][32];	// L1561
  #pragma HLS array_partition variable=local_A6 complete dim=1

  float local_B6[32][2];	// L1562
  #pragma HLS array_partition variable=local_B6 complete dim=2

  float local_C6[2][2];	// L1563
  #pragma HLS array_partition variable=local_C6 complete dim=1
  #pragma HLS array_partition variable=local_C6 complete dim=2

  l_outer_tile_mi6: for (int mi6 = 0; mi6 < 32; mi6++) {	// L1564
    l_ni6: for (int ni6 = 0; ni6 < 16; ni6++) {	// L1565
    #pragma HLS dataflow
      l_load_A_tile_ak6: for (int ak6 = 0; ak6 < 32; ak6++) {	// L1566
        l_ai6: for (int ai6 = 0; ai6 < 2; ai6++) {	// L1567
        #pragma HLS pipeline II=1
          ap_int<33> v1071 = ni6;	// L1568
          bool v1072 = v1071 == 0;	// L1571
          if (v1072) {	// L1572
            float v1073 = v1061[((mi6 * 2) + ai6)][ak6];	// L1573
            local_A6[ai6][ak6] = v1073;	// L1574
          }
        }
      }
      l_load_B_tile_bk6: for (int bk6 = 0; bk6 < 32; bk6++) {	// L1578
        l_bj6: for (int bj6 = 0; bj6 < 2; bj6++) {	// L1579
        #pragma HLS pipeline II=1
          float v1076 = v1062[bk6][((ni6 * 2) + bj6)];	// L1580
          local_B6[bk6][bj6] = v1076;	// L1581
        }
      }
      systolic_tile_attn_out(local_A6, local_B6, local_C6);	// L1584
      l_store_C_tile_sj6: for (int sj6 = 0; sj6 < 2; sj6++) {	// L1585
        l_si6: for (int si6 = 0; si6 < 2; si6++) {	// L1586
        #pragma HLS pipeline II=1
          float v1079 = local_C6[si6][sj6];	// L1587
          v1063[((mi6 * 2) + si6)][((ni6 * 2) + sj6)] = v1079;	// L1588
        }
      }
    }
  }
}

void bias_add_scale(
  float v1080[64][32],
  float v1081[32],
  float v1082[64][32],
  float v1083[64][32]
) {	// L1595
  float Y2[64][32];	// L1596
  l_scale_i18: for (int i18 = 0; i18 < 64; i18++) {	// L1597
    l_j16: for (int j16 = 0; j16 < 32; j16++) {	// L1598
      float v1087 = v1080[i18][j16];	// L1599
      float v1088 = v1081[j16];	// L1600
      float v1089 = v1087 * v1088;	// L1601
      Y2[i18][j16] = v1089;	// L1602
    }
  }
  l_res_add_i19: for (int i19 = 0; i19 < 64; i19++) {	// L1606
    l_j17: for (int j17 = 0; j17 < 32; j17++) {	// L1607
      float v1092 = Y2[i19][j17];	// L1608
      float v1093 = v1082[i19][j17];	// L1609
      float v1094 = v1092 + v1093;	// L1610
      v1083[i19][j17] = v1094;	// L1611
    }
  }
}

void PE_kernel_mlp1_0_0(
  hls::stream< float > &v1095 /* v1095[32] */,
  hls::stream< float > &v1096 /* v1096[32] */,
  hls::stream< float > &v1097 /* v1097[32] */,
  hls::stream< float > &v1098 /* v1098[32] */,
  float v1099[2][2],
  int v1100,
  int v1101
) {	// L1616
  #pragma HLS stream variable=v1095 depth=3
  #pragma HLS stream variable=v1096 depth=3
  #pragma HLS stream variable=v1097 depth=3
  #pragma HLS stream variable=v1098 depth=3
  #pragma HLS array_partition variable=v1099 complete dim=1
  #pragma HLS array_partition variable=v1099 complete dim=2

  float v26;	// L1619
  v26 = 0.000000;	// L1620
  l_S_k_0_k40: for (int k40 = 0; k40 < 32; k40++) {	// L1621
    float v1104 = v1095.read(); // v1095[k40];	// L1622
    float a26;	// L1623
    a26 = v1104;	// L1624
    float v1106 = v1096.read(); // v1096[k40];	// L1625
    float b26;	// L1626
    b26 = v1106;	// L1627
    float v1108 = a26;	// L1628
    float v1109 = b26;	// L1629
    float v1110 = v1108 * v1109;	// L1630
    float v1111 = v26;	// L1631
    float v1112 = v1111 + v1110;	// L1632
    v26 = v1112;	// L1633
    float v1113 = a26;	// L1634
    v1097.write(v1113); // v1097[k40] = v1113;	// L1635
    float v1114 = b26;	// L1636
    v1098.write(v1114); // v1098[k40] = v1114;	// L1637
  }
  float v1115 = v26;	// L1639
  v1099[v1100][v1101] = v1115;	// L1640
}

void PE_kernel_mlp1_1_0(
  hls::stream< float > &v1116 /* v1116[32] */,
  hls::stream< float > &v1117 /* v1117[32] */,
  hls::stream< float > &v1118 /* v1118[32] */,
  hls::stream< float > &v1119 /* v1119[32] */,
  float v1120[2][2],
  int v1121,
  int v1122
) {	// L1643
  #pragma HLS stream variable=v1116 depth=3
  #pragma HLS stream variable=v1117 depth=3
  #pragma HLS stream variable=v1118 depth=3
  #pragma HLS stream variable=v1119 depth=3
  #pragma HLS array_partition variable=v1120 complete dim=1
  #pragma HLS array_partition variable=v1120 complete dim=2

  float v27;	// L1646
  v27 = 0.000000;	// L1647
  l_S_k_0_k41: for (int k41 = 0; k41 < 32; k41++) {	// L1648
    float v1125 = v1116.read(); // v1116[k41];	// L1649
    float a27;	// L1650
    a27 = v1125;	// L1651
    float v1127 = v1117.read(); // v1117[k41];	// L1652
    float b27;	// L1653
    b27 = v1127;	// L1654
    float v1129 = a27;	// L1655
    float v1130 = b27;	// L1656
    float v1131 = v1129 * v1130;	// L1657
    float v1132 = v27;	// L1658
    float v1133 = v1132 + v1131;	// L1659
    v27 = v1133;	// L1660
    float v1134 = a27;	// L1661
    v1118.write(v1134); // v1118[k41] = v1134;	// L1662
    float v1135 = b27;	// L1663
    v1119.write(v1135); // v1119[k41] = v1135;	// L1664
  }
  float v1136 = v27;	// L1666
  v1120[v1121][v1122] = v1136;	// L1667
}

void PE_kernel_mlp1_0_1(
  hls::stream< float > &v1137 /* v1137[32] */,
  hls::stream< float > &v1138 /* v1138[32] */,
  hls::stream< float > &v1139 /* v1139[32] */,
  hls::stream< float > &v1140 /* v1140[32] */,
  float v1141[2][2],
  int v1142,
  int v1143
) {	// L1670
  #pragma HLS stream variable=v1137 depth=3
  #pragma HLS stream variable=v1138 depth=3
  #pragma HLS stream variable=v1139 depth=3
  #pragma HLS stream variable=v1140 depth=3
  #pragma HLS array_partition variable=v1141 complete dim=1
  #pragma HLS array_partition variable=v1141 complete dim=2

  float v28;	// L1673
  v28 = 0.000000;	// L1674
  l_S_k_0_k42: for (int k42 = 0; k42 < 32; k42++) {	// L1675
    float v1146 = v1137.read(); // v1137[k42];	// L1676
    float a28;	// L1677
    a28 = v1146;	// L1678
    float v1148 = v1138.read(); // v1138[k42];	// L1679
    float b28;	// L1680
    b28 = v1148;	// L1681
    float v1150 = a28;	// L1682
    float v1151 = b28;	// L1683
    float v1152 = v1150 * v1151;	// L1684
    float v1153 = v28;	// L1685
    float v1154 = v1153 + v1152;	// L1686
    v28 = v1154;	// L1687
    float v1155 = a28;	// L1688
    v1139.write(v1155); // v1139[k42] = v1155;	// L1689
    float v1156 = b28;	// L1690
    v1140.write(v1156); // v1140[k42] = v1156;	// L1691
  }
  float v1157 = v28;	// L1693
  v1141[v1142][v1143] = v1157;	// L1694
}

void PE_kernel_mlp1_1_1(
  hls::stream< float > &v1158 /* v1158[32] */,
  hls::stream< float > &v1159 /* v1159[32] */,
  hls::stream< float > &v1160 /* v1160[32] */,
  hls::stream< float > &v1161 /* v1161[32] */,
  float v1162[2][2],
  int v1163,
  int v1164
) {	// L1697
  #pragma HLS stream variable=v1158 depth=3
  #pragma HLS stream variable=v1159 depth=3
  #pragma HLS stream variable=v1160 depth=3
  #pragma HLS stream variable=v1161 depth=3
  #pragma HLS array_partition variable=v1162 complete dim=1
  #pragma HLS array_partition variable=v1162 complete dim=2

  float v29;	// L1700
  v29 = 0.000000;	// L1701
  l_S_k_0_k43: for (int k43 = 0; k43 < 32; k43++) {	// L1702
    float v1167 = v1158.read(); // v1158[k43];	// L1703
    float a29;	// L1704
    a29 = v1167;	// L1705
    float v1169 = v1159.read(); // v1159[k43];	// L1706
    float b29;	// L1707
    b29 = v1169;	// L1708
    float v1171 = a29;	// L1709
    float v1172 = b29;	// L1710
    float v1173 = v1171 * v1172;	// L1711
    float v1174 = v29;	// L1712
    float v1175 = v1174 + v1173;	// L1713
    v29 = v1175;	// L1714
    float v1176 = a29;	// L1715
    v1160.write(v1176); // v1160[k43] = v1176;	// L1716
    float v1177 = b29;	// L1717
    v1161.write(v1177); // v1161[k43] = v1177;	// L1718
  }
  float v1178 = v29;	// L1720
  v1162[v1163][v1164] = v1178;	// L1721
}

void systolic_tile_mlp1(
  float v1179[2][32],
  float v1180[32][2],
  float v1181[2][2]
) {	// L1724
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1179 complete dim=1

  #pragma HLS array_partition variable=v1180 complete dim=2

  #pragma HLS array_partition variable=v1181 complete dim=1
  #pragma HLS array_partition variable=v1181 complete dim=2

  hls::stream< float > A_fifo7[2][3] /* A_fifo7[2][3][32] */;	// L1725
  #pragma HLS stream variable=A_fifo7 depth=3
  hls::stream< float > B_fifo7[2][3] /* B_fifo7[2][3][32] */;	// L1726
  #pragma HLS stream variable=B_fifo7 depth=3
  float A_drain7[2];	// L1727
  float B_drain7[2];	// L1728
  l_data_load_k44: for (int k44 = 0; k44 < 32; k44++) {	// L1729
    l_S_m_0_m14: for (int m14 = 0; m14 < 2; m14++) {	// L1730
      float v1188 = v1179[m14][k44];	// L1731
      A_fifo7[m14][0].write(v1188); // A_fifo7[m14][0][k44] = v1188;	// L1732
    }
    l_S_n_1_n14: for (int n14 = 0; n14 < 2; n14++) {	// L1734
      float v1190 = v1180[k44][n14];	// L1735
      B_fifo7[n14][0].write(v1190); // B_fifo7[n14][0][k44] = v1190;	// L1736
    }
  }
  hls::stream< float > &v1191 /* v1191[32] */ = A_fifo7[0][0];	// L1740
  hls::stream< float > &v1192 /* v1192[32] */ = B_fifo7[0][0];	// L1741
  hls::stream< float > &v1193 /* v1193[32] */ = A_fifo7[0][1];	// L1747
  hls::stream< float > &v1194 /* v1194[32] */ = B_fifo7[0][1];	// L1748
  PE_kernel_mlp1_0_0(v1191, v1192, v1193, v1194, v1181, 0, 0);	// L1749
  hls::stream< float > &v1195 /* v1195[32] */ = A_fifo7[0][1];	// L1751
  hls::stream< float > &v1196 /* v1196[32] */ = B_fifo7[1][0];	// L1752
  hls::stream< float > &v1197 /* v1197[32] */ = A_fifo7[0][2];	// L1756
  hls::stream< float > &v1198 /* v1198[32] */ = B_fifo7[1][1];	// L1757
  PE_kernel_mlp1_1_0(v1195, v1196, v1197, v1198, v1181, 0, 1);	// L1758
  hls::stream< float > &v1199 /* v1199[32] */ = A_fifo7[1][0];	// L1759
  hls::stream< float > &v1200 /* v1200[32] */ = B_fifo7[0][1];	// L1760
  hls::stream< float > &v1201 /* v1201[32] */ = A_fifo7[1][1];	// L1761
  hls::stream< float > &v1202 /* v1202[32] */ = B_fifo7[0][2];	// L1762
  PE_kernel_mlp1_0_1(v1199, v1200, v1201, v1202, v1181, 1, 0);	// L1763
  hls::stream< float > &v1203 /* v1203[32] */ = A_fifo7[1][1];	// L1764
  hls::stream< float > &v1204 /* v1204[32] */ = B_fifo7[1][1];	// L1765
  hls::stream< float > &v1205 /* v1205[32] */ = A_fifo7[1][2];	// L1766
  hls::stream< float > &v1206 /* v1206[32] */ = B_fifo7[1][2];	// L1767
  PE_kernel_mlp1_1_1(v1203, v1204, v1205, v1206, v1181, 1, 1);	// L1768
  l_data_drain_k45: for (int k45 = 0; k45 < 32; k45++) {	// L1769
    l_S_m_4_m15: for (int m15 = 0; m15 < 2; m15++) {	// L1770
      float v1209 = A_fifo7[m15][2].read(); // A_fifo7[m15][2][k45];	// L1771
      A_drain7[m15] = v1209;	// L1772
    }
    l_S_n_5_n15: for (int n15 = 0; n15 < 2; n15++) {	// L1774
      float v1211 = B_fifo7[n15][2].read(); // B_fifo7[n15][2][k45];	// L1775
      B_drain7[n15] = v1211;	// L1776
    }
  }
}

void systolic_mlp1(
  float v1212[64][32],
  float v1213[32][32],
  float v1214[64][32]
) {	// L1781
  float local_A7[2][32];	// L1782
  #pragma HLS array_partition variable=local_A7 complete dim=1

  float local_B7[32][2];	// L1783
  #pragma HLS array_partition variable=local_B7 complete dim=2

  float local_C7[2][2];	// L1784
  #pragma HLS array_partition variable=local_C7 complete dim=1
  #pragma HLS array_partition variable=local_C7 complete dim=2

  l_outer_tile_mi7: for (int mi7 = 0; mi7 < 32; mi7++) {	// L1785
    l_ni7: for (int ni7 = 0; ni7 < 16; ni7++) {	// L1786
    #pragma HLS dataflow
      l_load_A_tile_ak7: for (int ak7 = 0; ak7 < 32; ak7++) {	// L1787
        l_ai7: for (int ai7 = 0; ai7 < 2; ai7++) {	// L1788
        #pragma HLS pipeline II=1
          ap_int<33> v1222 = ni7;	// L1789
          bool v1223 = v1222 == 0;	// L1792
          if (v1223) {	// L1793
            float v1224 = v1212[((mi7 * 2) + ai7)][ak7];	// L1794
            local_A7[ai7][ak7] = v1224;	// L1795
          }
        }
      }
      l_load_B_tile_bk7: for (int bk7 = 0; bk7 < 32; bk7++) {	// L1799
        l_bj7: for (int bj7 = 0; bj7 < 2; bj7++) {	// L1800
        #pragma HLS pipeline II=1
          float v1227 = v1213[bk7][((ni7 * 2) + bj7)];	// L1801
          local_B7[bk7][bj7] = v1227;	// L1802
        }
      }
      systolic_tile_mlp1(local_A7, local_B7, local_C7);	// L1805
      l_store_C_tile_sj7: for (int sj7 = 0; sj7 < 2; sj7++) {	// L1806
        l_si7: for (int si7 = 0; si7 < 2; si7++) {	// L1807
        #pragma HLS pipeline II=1
          float v1230 = local_C7[si7][sj7];	// L1808
          v1214[((mi7 * 2) + si7)][((ni7 * 2) + sj7)] = v1230;	// L1809
        }
      }
    }
  }
}

void bias_add(
  float v1231[64][32],
  float v1232[32],
  float v1233[64][32]
) {	// L1816
  l_S_i_j_0_i20: for (int i20 = 0; i20 < 64; i20++) {	// L1818
    l_j18: for (int j18 = 0; j18 < 32; j18++) {	// L1819
      float v1236 = v1231[i20][j18];	// L1820
      float v1237 = v1232[j18];	// L1821
      float v1238 = v1236 + v1237;	// L1822
      v1233[i20][j18] = v1238;	// L1823
    }
  }
}

void GeLU(
  float v1239[64][32],
  float v1240[64][32]
) {	// L1828
  l_gelu_i21: for (int i21 = 0; i21 < 64; i21++) {	// L1830
    l_j19: for (int j19 = 0; j19 < 32; j19++) {	// L1831
      float v1243 = v1239[i21][j19];	// L1832
      float v1244 = v1243 * 0.500000;	// L1834
      float v1245 = pow(v1243, 3.000000);	// L1836
      float v1246 = v1245 * 0.044715;	// L1838
      float v1247 = v1243 + v1246;	// L1839
      float v1248 = v1247 * 0.797885;	// L1841
      float v1249 = tanh(v1248);	// L1842
      float v1250 = v1249 + 1.000000;	// L1844
      float v1251 = v1244 * v1250;	// L1845
      v1240[i21][j19] = v1251;	// L1846
    }
  }
}

void PE_kernel_mlp2_0_0(
  hls::stream< float > &v1252 /* v1252[32] */,
  hls::stream< float > &v1253 /* v1253[32] */,
  hls::stream< float > &v1254 /* v1254[32] */,
  hls::stream< float > &v1255 /* v1255[32] */,
  float v1256[2][2],
  int v1257,
  int v1258
) {	// L1851
  #pragma HLS stream variable=v1252 depth=3
  #pragma HLS stream variable=v1253 depth=3
  #pragma HLS stream variable=v1254 depth=3
  #pragma HLS stream variable=v1255 depth=3
  #pragma HLS array_partition variable=v1256 complete dim=1
  #pragma HLS array_partition variable=v1256 complete dim=2

  float v30;	// L1854
  v30 = 0.000000;	// L1855
  l_S_k_0_k46: for (int k46 = 0; k46 < 32; k46++) {	// L1856
    float v1261 = v1252.read(); // v1252[k46];	// L1857
    float a30;	// L1858
    a30 = v1261;	// L1859
    float v1263 = v1253.read(); // v1253[k46];	// L1860
    float b30;	// L1861
    b30 = v1263;	// L1862
    float v1265 = a30;	// L1863
    float v1266 = b30;	// L1864
    float v1267 = v1265 * v1266;	// L1865
    float v1268 = v30;	// L1866
    float v1269 = v1268 + v1267;	// L1867
    v30 = v1269;	// L1868
    float v1270 = a30;	// L1869
    v1254.write(v1270); // v1254[k46] = v1270;	// L1870
    float v1271 = b30;	// L1871
    v1255.write(v1271); // v1255[k46] = v1271;	// L1872
  }
  float v1272 = v30;	// L1874
  v1256[v1257][v1258] = v1272;	// L1875
}

void PE_kernel_mlp2_1_0(
  hls::stream< float > &v1273 /* v1273[32] */,
  hls::stream< float > &v1274 /* v1274[32] */,
  hls::stream< float > &v1275 /* v1275[32] */,
  hls::stream< float > &v1276 /* v1276[32] */,
  float v1277[2][2],
  int v1278,
  int v1279
) {	// L1878
  #pragma HLS stream variable=v1273 depth=3
  #pragma HLS stream variable=v1274 depth=3
  #pragma HLS stream variable=v1275 depth=3
  #pragma HLS stream variable=v1276 depth=3
  #pragma HLS array_partition variable=v1277 complete dim=1
  #pragma HLS array_partition variable=v1277 complete dim=2

  float v31;	// L1881
  v31 = 0.000000;	// L1882
  l_S_k_0_k47: for (int k47 = 0; k47 < 32; k47++) {	// L1883
    float v1282 = v1273.read(); // v1273[k47];	// L1884
    float a31;	// L1885
    a31 = v1282;	// L1886
    float v1284 = v1274.read(); // v1274[k47];	// L1887
    float b31;	// L1888
    b31 = v1284;	// L1889
    float v1286 = a31;	// L1890
    float v1287 = b31;	// L1891
    float v1288 = v1286 * v1287;	// L1892
    float v1289 = v31;	// L1893
    float v1290 = v1289 + v1288;	// L1894
    v31 = v1290;	// L1895
    float v1291 = a31;	// L1896
    v1275.write(v1291); // v1275[k47] = v1291;	// L1897
    float v1292 = b31;	// L1898
    v1276.write(v1292); // v1276[k47] = v1292;	// L1899
  }
  float v1293 = v31;	// L1901
  v1277[v1278][v1279] = v1293;	// L1902
}

void PE_kernel_mlp2_0_1(
  hls::stream< float > &v1294 /* v1294[32] */,
  hls::stream< float > &v1295 /* v1295[32] */,
  hls::stream< float > &v1296 /* v1296[32] */,
  hls::stream< float > &v1297 /* v1297[32] */,
  float v1298[2][2],
  int v1299,
  int v1300
) {	// L1905
  #pragma HLS stream variable=v1294 depth=3
  #pragma HLS stream variable=v1295 depth=3
  #pragma HLS stream variable=v1296 depth=3
  #pragma HLS stream variable=v1297 depth=3
  #pragma HLS array_partition variable=v1298 complete dim=1
  #pragma HLS array_partition variable=v1298 complete dim=2

  float v32;	// L1908
  v32 = 0.000000;	// L1909
  l_S_k_0_k48: for (int k48 = 0; k48 < 32; k48++) {	// L1910
    float v1303 = v1294.read(); // v1294[k48];	// L1911
    float a32;	// L1912
    a32 = v1303;	// L1913
    float v1305 = v1295.read(); // v1295[k48];	// L1914
    float b32;	// L1915
    b32 = v1305;	// L1916
    float v1307 = a32;	// L1917
    float v1308 = b32;	// L1918
    float v1309 = v1307 * v1308;	// L1919
    float v1310 = v32;	// L1920
    float v1311 = v1310 + v1309;	// L1921
    v32 = v1311;	// L1922
    float v1312 = a32;	// L1923
    v1296.write(v1312); // v1296[k48] = v1312;	// L1924
    float v1313 = b32;	// L1925
    v1297.write(v1313); // v1297[k48] = v1313;	// L1926
  }
  float v1314 = v32;	// L1928
  v1298[v1299][v1300] = v1314;	// L1929
}

void PE_kernel_mlp2_1_1(
  hls::stream< float > &v1315 /* v1315[32] */,
  hls::stream< float > &v1316 /* v1316[32] */,
  hls::stream< float > &v1317 /* v1317[32] */,
  hls::stream< float > &v1318 /* v1318[32] */,
  float v1319[2][2],
  int v1320,
  int v1321
) {	// L1932
  #pragma HLS stream variable=v1315 depth=3
  #pragma HLS stream variable=v1316 depth=3
  #pragma HLS stream variable=v1317 depth=3
  #pragma HLS stream variable=v1318 depth=3
  #pragma HLS array_partition variable=v1319 complete dim=1
  #pragma HLS array_partition variable=v1319 complete dim=2

  float v33;	// L1935
  v33 = 0.000000;	// L1936
  l_S_k_0_k49: for (int k49 = 0; k49 < 32; k49++) {	// L1937
    float v1324 = v1315.read(); // v1315[k49];	// L1938
    float a33;	// L1939
    a33 = v1324;	// L1940
    float v1326 = v1316.read(); // v1316[k49];	// L1941
    float b33;	// L1942
    b33 = v1326;	// L1943
    float v1328 = a33;	// L1944
    float v1329 = b33;	// L1945
    float v1330 = v1328 * v1329;	// L1946
    float v1331 = v33;	// L1947
    float v1332 = v1331 + v1330;	// L1948
    v33 = v1332;	// L1949
    float v1333 = a33;	// L1950
    v1317.write(v1333); // v1317[k49] = v1333;	// L1951
    float v1334 = b33;	// L1952
    v1318.write(v1334); // v1318[k49] = v1334;	// L1953
  }
  float v1335 = v33;	// L1955
  v1319[v1320][v1321] = v1335;	// L1956
}

void systolic_tile_mlp2(
  float v1336[2][32],
  float v1337[32][2],
  float v1338[2][2]
) {	// L1959
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1336 complete dim=1

  #pragma HLS array_partition variable=v1337 complete dim=2

  #pragma HLS array_partition variable=v1338 complete dim=1
  #pragma HLS array_partition variable=v1338 complete dim=2

  hls::stream< float > A_fifo8[2][3] /* A_fifo8[2][3][32] */;	// L1960
  #pragma HLS stream variable=A_fifo8 depth=3
  hls::stream< float > B_fifo8[2][3] /* B_fifo8[2][3][32] */;	// L1961
  #pragma HLS stream variable=B_fifo8 depth=3
  float A_drain8[2];	// L1962
  float B_drain8[2];	// L1963
  l_data_load_k50: for (int k50 = 0; k50 < 32; k50++) {	// L1964
    l_S_m_0_m16: for (int m16 = 0; m16 < 2; m16++) {	// L1965
      float v1345 = v1336[m16][k50];	// L1966
      A_fifo8[m16][0].write(v1345); // A_fifo8[m16][0][k50] = v1345;	// L1967
    }
    l_S_n_1_n16: for (int n16 = 0; n16 < 2; n16++) {	// L1969
      float v1347 = v1337[k50][n16];	// L1970
      B_fifo8[n16][0].write(v1347); // B_fifo8[n16][0][k50] = v1347;	// L1971
    }
  }
  hls::stream< float > &v1348 /* v1348[32] */ = A_fifo8[0][0];	// L1975
  hls::stream< float > &v1349 /* v1349[32] */ = B_fifo8[0][0];	// L1976
  hls::stream< float > &v1350 /* v1350[32] */ = A_fifo8[0][1];	// L1982
  hls::stream< float > &v1351 /* v1351[32] */ = B_fifo8[0][1];	// L1983
  PE_kernel_mlp2_0_0(v1348, v1349, v1350, v1351, v1338, 0, 0);	// L1984
  hls::stream< float > &v1352 /* v1352[32] */ = A_fifo8[0][1];	// L1986
  hls::stream< float > &v1353 /* v1353[32] */ = B_fifo8[1][0];	// L1987
  hls::stream< float > &v1354 /* v1354[32] */ = A_fifo8[0][2];	// L1991
  hls::stream< float > &v1355 /* v1355[32] */ = B_fifo8[1][1];	// L1992
  PE_kernel_mlp2_1_0(v1352, v1353, v1354, v1355, v1338, 0, 1);	// L1993
  hls::stream< float > &v1356 /* v1356[32] */ = A_fifo8[1][0];	// L1994
  hls::stream< float > &v1357 /* v1357[32] */ = B_fifo8[0][1];	// L1995
  hls::stream< float > &v1358 /* v1358[32] */ = A_fifo8[1][1];	// L1996
  hls::stream< float > &v1359 /* v1359[32] */ = B_fifo8[0][2];	// L1997
  PE_kernel_mlp2_0_1(v1356, v1357, v1358, v1359, v1338, 1, 0);	// L1998
  hls::stream< float > &v1360 /* v1360[32] */ = A_fifo8[1][1];	// L1999
  hls::stream< float > &v1361 /* v1361[32] */ = B_fifo8[1][1];	// L2000
  hls::stream< float > &v1362 /* v1362[32] */ = A_fifo8[1][2];	// L2001
  hls::stream< float > &v1363 /* v1363[32] */ = B_fifo8[1][2];	// L2002
  PE_kernel_mlp2_1_1(v1360, v1361, v1362, v1363, v1338, 1, 1);	// L2003
  l_data_drain_k51: for (int k51 = 0; k51 < 32; k51++) {	// L2004
    l_S_m_4_m17: for (int m17 = 0; m17 < 2; m17++) {	// L2005
      float v1366 = A_fifo8[m17][2].read(); // A_fifo8[m17][2][k51];	// L2006
      A_drain8[m17] = v1366;	// L2007
    }
    l_S_n_5_n17: for (int n17 = 0; n17 < 2; n17++) {	// L2009
      float v1368 = B_fifo8[n17][2].read(); // B_fifo8[n17][2][k51];	// L2010
      B_drain8[n17] = v1368;	// L2011
    }
  }
}

void systolic_mlp2(
  float v1369[64][32],
  float v1370[32][32],
  float v1371[64][32]
) {	// L2016
  float local_A8[2][32];	// L2017
  #pragma HLS array_partition variable=local_A8 complete dim=1

  float local_B8[32][2];	// L2018
  #pragma HLS array_partition variable=local_B8 complete dim=2

  float local_C8[2][2];	// L2019
  #pragma HLS array_partition variable=local_C8 complete dim=1
  #pragma HLS array_partition variable=local_C8 complete dim=2

  l_outer_tile_mi8: for (int mi8 = 0; mi8 < 32; mi8++) {	// L2020
    l_ni8: for (int ni8 = 0; ni8 < 16; ni8++) {	// L2021
    #pragma HLS dataflow
      l_load_A_tile_ak8: for (int ak8 = 0; ak8 < 32; ak8++) {	// L2022
        l_ai8: for (int ai8 = 0; ai8 < 2; ai8++) {	// L2023
        #pragma HLS pipeline II=1
          ap_int<33> v1379 = ni8;	// L2024
          bool v1380 = v1379 == 0;	// L2027
          if (v1380) {	// L2028
            float v1381 = v1369[((mi8 * 2) + ai8)][ak8];	// L2029
            local_A8[ai8][ak8] = v1381;	// L2030
          }
        }
      }
      l_load_B_tile_bk8: for (int bk8 = 0; bk8 < 32; bk8++) {	// L2034
        l_bj8: for (int bj8 = 0; bj8 < 2; bj8++) {	// L2035
        #pragma HLS pipeline II=1
          float v1384 = v1370[bk8][((ni8 * 2) + bj8)];	// L2036
          local_B8[bk8][bj8] = v1384;	// L2037
        }
      }
      systolic_tile_mlp2(local_A8, local_B8, local_C8);	// L2040
      l_store_C_tile_sj8: for (int sj8 = 0; sj8 < 2; sj8++) {	// L2041
        l_si8: for (int si8 = 0; si8 < 2; si8++) {	// L2042
        #pragma HLS pipeline II=1
          float v1387 = local_C8[si8][sj8];	// L2043
          v1371[((mi8 * 2) + si8)][((ni8 * 2) + sj8)] = v1387;	// L2044
        }
      }
    }
  }
}

void allo_DDitBlock(
  float *v1388,
  float *v1389,
  float *v1390,
  float *v1391,
  float *v1392,
  float *v1393,
  float *v1394,
  float *v1395,
  float *v1396,
  float *v1397,
  float *v1398,
  float *v1399,
  float *v1400,
  float *v1401,
  float *v1402,
  float *v1403,
  float *v1404,
  float *v1405,
  float *v1406,
  float *v1407,
  float *v1408,
  float *v1409,
  float *v1410,
  float *v1411
) {	// L2051
  #pragma HLS interface m_axi port=v1388 offset=slave bundle=gmem0 depth=2048 
  #pragma HLS interface m_axi port=v1389 offset=slave bundle=gmem1 depth=32
  #pragma HLS interface m_axi port=v1390 offset=slave bundle=gmem2 depth=32 
  #pragma HLS interface m_axi port=v1391 offset=slave bundle=gmem3 depth=128 
  #pragma HLS interface m_axi port=v1392 offset=slave bundle=gmem4 depth=128 
  #pragma HLS interface m_axi port=v1393 offset=slave bundle=gmem5 depth=1024 
  #pragma HLS interface m_axi port=v1394 offset=slave bundle=gmem6 depth=1024 
  #pragma HLS interface m_axi port=v1395 offset=slave bundle=gmem7 depth=1024
  #pragma HLS interface m_axi port=v1396 offset=slave bundle=gmem8 depth=192 
  #pragma HLS interface m_axi port=v1397 offset=slave bundle=gmem9 depth=1536 
  #pragma HLS interface m_axi port=v1398 offset=slave bundle=gmem10 depth=192 
  #pragma HLS interface m_axi port=v1399 offset=slave bundle=gmem11 depth=32
  #pragma HLS interface m_axi port=v1400 offset=slave bundle=gmem12 depth=32 
  #pragma HLS interface m_axi port=v1401 offset=slave bundle=gmem13 depth=32 
  #pragma HLS interface m_axi port=v1402 offset=slave bundle=gmem14 depth=32 
  #pragma HLS interface m_axi port=v1403 offset=slave bundle=gmem15 depth=32 
  #pragma HLS interface m_axi port=v1404 offset=slave bundle=gmem16 depth=32 
  #pragma HLS interface m_axi port=v1405 offset=slave bundle=gmem17 depth=1024 
  #pragma HLS interface m_axi port=v1406 offset=slave bundle=gmem18 depth=2048
  #pragma HLS interface m_axi port=v1407 offset=slave bundle=gmem19 depth=1024 
  #pragma HLS interface m_axi port=v1408 offset=slave bundle=gmem20 depth=32 
  #pragma HLS interface m_axi port=v1409 offset=slave bundle=gmem21 depth=1024 
  #pragma HLS interface m_axi port=v1410 offset=slave bundle=gmem22 depth=32 
  #pragma HLS interface m_axi port=v1411 offset=slave bundle=gmem23 depth=2048 
  float buf0[64][32];	//
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 64; buf0_l_0++) {	//
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 32; buf0_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1415 = v1388[((buf0_l_0 * 32) + buf0_l_1)];	//
      buf0[buf0_l_0][buf0_l_1] = v1415;	//
    }
  }
  float buf1[32];	//
  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 32; buf1_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1418 = v1389[buf1_l_0];	//
    buf1[buf1_l_0] = v1418;	//
  }
  float buf2[32];	//
  l_S_buf2_buf2_l_0: for (int buf2_l_0 = 0; buf2_l_0 < 32; buf2_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1421 = v1390[buf2_l_0];	//
    buf2[buf2_l_0] = v1421;	//
  }
  float buf3[64][2];	//
  l_S_buf3_buf3_l_0: for (int buf3_l_0 = 0; buf3_l_0 < 64; buf3_l_0++) {	//
    l_buf3_l_1: for (int buf3_l_1 = 0; buf3_l_1 < 2; buf3_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1425 = v1391[((buf3_l_0 * 2) + buf3_l_1)];	//
      buf3[buf3_l_0][buf3_l_1] = v1425;	//
    }
  }
  float buf4[64][2];	//
  l_S_buf4_buf4_l_0: for (int buf4_l_0 = 0; buf4_l_0 < 64; buf4_l_0++) {	//
    l_buf4_l_1: for (int buf4_l_1 = 0; buf4_l_1 < 2; buf4_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1429 = v1392[((buf4_l_0 * 2) + buf4_l_1)];	//
      buf4[buf4_l_0][buf4_l_1] = v1429;	//
    }
  }
  float buf5[32][32];	//
  l_S_buf5_buf5_l_0: for (int buf5_l_0 = 0; buf5_l_0 < 32; buf5_l_0++) {	//
    l_buf5_l_1: for (int buf5_l_1 = 0; buf5_l_1 < 32; buf5_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1433 = v1393[((buf5_l_0 * 32) + buf5_l_1)];	//
      buf5[buf5_l_0][buf5_l_1] = v1433;	//
    }
  }
  float buf6[32][32];	//
  l_S_buf6_buf6_l_0: for (int buf6_l_0 = 0; buf6_l_0 < 32; buf6_l_0++) {	//
    l_buf6_l_1: for (int buf6_l_1 = 0; buf6_l_1 < 32; buf6_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1437 = v1394[((buf6_l_0 * 32) + buf6_l_1)];	//
      buf6[buf6_l_0][buf6_l_1] = v1437;	//
    }
  }
  float buf7[32][32];	//
  l_S_buf7_buf7_l_0: for (int buf7_l_0 = 0; buf7_l_0 < 32; buf7_l_0++) {	//
    l_buf7_l_1: for (int buf7_l_1 = 0; buf7_l_1 < 32; buf7_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1441 = v1395[((buf7_l_0 * 32) + buf7_l_1)];	//
      buf7[buf7_l_0][buf7_l_1] = v1441;	//
    }
  }
  float buf8[1][8];	//
  l_S_buf8_buf8_l_0: for (int buf8_l_0 = 0; buf8_l_0 < 1; buf8_l_0++) {	//
    l_buf8_l_1: for (int buf8_l_1 = 0; buf8_l_1 < 8; buf8_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1445 = v1396[((buf8_l_0 * 8) + buf8_l_1)];	//
      buf8[buf8_l_0][buf8_l_1] = v1445;	//
    }
  }
  float buf9[8][192];	//
  l_S_buf9_buf9_l_0: for (int buf9_l_0 = 0; buf9_l_0 < 8; buf9_l_0++) {	//
    l_buf9_l_1: for (int buf9_l_1 = 0; buf9_l_1 < 192; buf9_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1449 = v1397[((buf9_l_0 * 192) + buf9_l_1)];	//
      buf9[buf9_l_0][buf9_l_1] = v1449;	//
    }
  }
  float buf10[192];	//
  l_S_buf10_buf10_l_0: for (int buf10_l_0 = 0; buf10_l_0 < 192; buf10_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1452 = v1398[buf10_l_0];	//
    buf10[buf10_l_0] = v1452;	//
  }
  float buf11[32];	//
  l_S_buf11_buf11_l_0: for (int buf11_l_0 = 0; buf11_l_0 < 32; buf11_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1455 = v1399[buf11_l_0];	//
    buf11[buf11_l_0] = v1455;	//
  }
  float buf12[32];	//
  l_S_buf12_buf12_l_0: for (int buf12_l_0 = 0; buf12_l_0 < 32; buf12_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1458 = v1400[buf12_l_0];	//
    buf12[buf12_l_0] = v1458;	//
  }
  float buf13[32];	//
  l_S_buf13_buf13_l_0: for (int buf13_l_0 = 0; buf13_l_0 < 32; buf13_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1461 = v1401[buf13_l_0];	//
    buf13[buf13_l_0] = v1461;	//
  }
  float buf14[32];	//
  l_S_buf14_buf14_l_0: for (int buf14_l_0 = 0; buf14_l_0 < 32; buf14_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1464 = v1402[buf14_l_0];	//
    buf14[buf14_l_0] = v1464;	//
  }
  float buf15[32];	//
  l_S_buf15_buf15_l_0: for (int buf15_l_0 = 0; buf15_l_0 < 32; buf15_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1467 = v1403[buf15_l_0];	//
    buf15[buf15_l_0] = v1467;	//
  }
  float buf16[32];	//
  l_S_buf16_buf16_l_0: for (int buf16_l_0 = 0; buf16_l_0 < 32; buf16_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1470 = v1404[buf16_l_0];	//
    buf16[buf16_l_0] = v1470;	//
  }
  float buf17[32][32];	//
  l_S_buf17_buf17_l_0: for (int buf17_l_0 = 0; buf17_l_0 < 32; buf17_l_0++) {	//
    l_buf17_l_1: for (int buf17_l_1 = 0; buf17_l_1 < 32; buf17_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1474 = v1405[((buf17_l_0 * 32) + buf17_l_1)];	//
      buf17[buf17_l_0][buf17_l_1] = v1474;	//
    }
  }
  float buf18[64][32];	//
  l_S_buf18_buf18_l_0: for (int buf18_l_0 = 0; buf18_l_0 < 64; buf18_l_0++) {	//
    l_buf18_l_1: for (int buf18_l_1 = 0; buf18_l_1 < 32; buf18_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1478 = v1406[((buf18_l_0 * 32) + buf18_l_1)];	//
      buf18[buf18_l_0][buf18_l_1] = v1478;	//
    }
  }
  float buf19[32][32];	//
  l_S_buf19_buf19_l_0: for (int buf19_l_0 = 0; buf19_l_0 < 32; buf19_l_0++) {	//
    l_buf19_l_1: for (int buf19_l_1 = 0; buf19_l_1 < 32; buf19_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1482 = v1407[((buf19_l_0 * 32) + buf19_l_1)];	//
      buf19[buf19_l_0][buf19_l_1] = v1482;	//
    }
  }
  float buf20[32];	//
  l_S_buf20_buf20_l_0: for (int buf20_l_0 = 0; buf20_l_0 < 32; buf20_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1485 = v1408[buf20_l_0];	//
    buf20[buf20_l_0] = v1485;	//
  }
  float buf21[32][32];	//
  l_S_buf21_buf21_l_0: for (int buf21_l_0 = 0; buf21_l_0 < 32; buf21_l_0++) {	//
    l_buf21_l_1: for (int buf21_l_1 = 0; buf21_l_1 < 32; buf21_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1489 = v1409[((buf21_l_0 * 32) + buf21_l_1)];	//
      buf21[buf21_l_0][buf21_l_1] = v1489;	//
    }
  }
  float buf22[32];	//
  l_S_buf22_buf22_l_0: for (int buf22_l_0 = 0; buf22_l_0 < 32; buf22_l_0++) {	//
  #pragma HLS pipeline II=1 rewind
    float v1492 = v1410[buf22_l_0];	//
    buf22[buf22_l_0] = v1492;	//
  }
  adaLN_modulate(buf8, buf9, buf10, buf11, buf12, buf13, buf14, buf15, buf16);	// L2052
  float v1493[64][32];
  layer_norm(buf0, buf1, buf2, v1493);	// L2053
  float v1494[64][32];
  modulate_fused(v1493, buf12, buf11, v1494);	// L2054
  float Q[64][32];	// L2057
  for (int v1496 = 0; v1496 < 64; v1496++) {	// L2058
    for (int v1497 = 0; v1497 < 32; v1497++) {	// L2058
      Q[v1496][v1497] = 0.000000;	// L2058
    }
  }
  float K[64][32];	// L2059
  for (int v1499 = 0; v1499 < 64; v1499++) {	// L2060
    for (int v1500 = 0; v1500 < 32; v1500++) {	// L2060
      K[v1499][v1500] = 0.000000;	// L2060
    }
  }
  float V[64][32];	// L2061
  for (int v1502 = 0; v1502 < 64; v1502++) {	// L2062
    for (int v1503 = 0; v1503 < 32; v1503++) {	// L2062
      V[v1502][v1503] = 0.000000;	// L2062
    }
  }
  systolic_Q(v1494, buf5, Q);	// L2063
  systolic_K(v1494, buf6, K);	// L2064
  systolic_V(v1494, buf7, V);	// L2065
  float v1504[64][32];
  RoPE(Q, buf4, buf3, v1504);	// L2066
  float v1505[64][32];
  RoPE(K, buf4, buf3, v1505);	// L2067
  float v1506[64][32];
  scaled_dot_product_attention(v1504, v1505, V, v1506);	// L2068
  float attn_out[64][32];	// L2069
  for (int v1508 = 0; v1508 < 64; v1508++) {	// L2070
    for (int v1509 = 0; v1509 < 32; v1509++) {	// L2070
      attn_out[v1508][v1509] = 0.000000;	// L2070
    }
  }
  systolic_attn_out(v1506, buf17, attn_out);	// L2071
  float v1510[64][32];
  bias_add_scale(attn_out, buf13, buf18, v1510);	// L2072
  float v1511[64][32];
  layer_norm(v1510, buf1, buf2, v1511);	// L2073
  float v1512[64][32];
  layer_norm(v1511, buf1, buf2, v1512);	// L2074
  float v1513[64][32];
  modulate_fused(v1512, buf15, buf14, v1513);	// L2075
  float x_mlp1[64][32];	// L2076
  for (int v1515 = 0; v1515 < 64; v1515++) {	// L2077
    for (int v1516 = 0; v1516 < 32; v1516++) {	// L2077
      x_mlp1[v1515][v1516] = 0.000000;	// L2077
    }
  }
  systolic_mlp1(v1513, buf19, x_mlp1);	// L2078
  float v1517[64][32];
  bias_add(x_mlp1, buf20, v1517);	// L2079
  float v1518[64][32];
  GeLU(v1517, v1518);	// L2080
  float x_mlp2[64][32];	// L2081
  for (int v1520 = 0; v1520 < 64; v1520++) {	// L2082
    for (int v1521 = 0; v1521 < 32; v1521++) {	// L2082
      x_mlp2[v1520][v1521] = 0.000000;	// L2082
    }
  }
  systolic_mlp2(v1518, buf21, x_mlp2);	// L2083
  float v1522[64][32];
  bias_add(x_mlp2, buf22, v1522);	// L2084
  float v1523[64][32];
  bias_add_scale(v1522, buf16, v1510, v1523);	// L2085
  l_S_result23_result23_l_0: for (int result23_l_0 = 0; result23_l_0 < 64; result23_l_0++) {	//
    l_result23_l_1: for (int result23_l_1 = 0; result23_l_1 < 32; result23_l_1++) {	//
    #pragma HLS pipeline II=1 rewind
      float v1526 = v1523[result23_l_0][result23_l_1];	//
      v1411[((result23_l_0 * 32) + result23_l_1)] = v1526;	//
    }
  }
}


} // extern "C"
