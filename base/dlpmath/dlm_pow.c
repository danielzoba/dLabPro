/* dLabPro mathematics library
 * - Some usefull y^x approximations
 *
 * AUTHOR : Guntram Strecha
 * PACKAGE: dLabPro/base
 * 
 * Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
 * - Chair of System Theory and Speech Technology, TU Dresden
 * - Chair of Communications Engineering, BTU Cottbus
 * 
 * This file is part of dLabPro.
 * 
 * dLabPro is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with dLabPro. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dlp_kernel.h"
#include "dlp_base.h"
#include "dlp_math.h"


/**
 * Fast pure integer dual logarithm.
 *
 * @param n
 *          <i>n</i>
 * @return log<sub>2</sub>(<i>n</i>)
 */
INT64 dlm_log2_i(UINT64 n)
{
  INT64 l;                                                                      /* The dual logarithm of m           */
  UINT64 m;                                                                     /* 2 to the power of l               */
  for (l=0,m=1; m<n; l++,m*=2) { }                                              /* Multiply m by 2 until m>n         */
  return m==n ? l : -1;                                                         /* Return dual log. or -1 on errors  */
}

/**
 * Fast pure integer power of 2.
 *
 * @param n
 *          <i>n</i>
 * @return 2<sup><i>n</i></sup>
 */
FLOAT64 dlm_pow2(INT64 n)
{
  UINT64 m = 1;
  UINT64 i = ABS(n);
  for (; i; i--) m*=2;
  return (n < 0) ? 1.0/(FLOAT64)m : m;
}

/* NO JAVADOC
 * <p>x^y for x and y of type <CODE>long int</CODE>.</p>
 *
 * @param x
 * @param y
 * @return the result of x^y
 */
FLOAT64 __dlm_pow_ii(INT64 x, INT64 y)
{
  UINT64 xy = x;
  INT64 i = ABS(y);

  if (y == 0) return 1.0;

  if (ABS(x) == 1)
  {
    if(x < 0)
      return (((y/2)*2) == y) ? 1 : -1;
    else
      return 1;
  }

  for(; i > 1; i--)
    xy *= x;

  if (y < 0) return 1.0 / (FLOAT64)xy;
  return (FLOAT64)xy;
}

/* NO JAVADOC
 * <p>x^y for x of type <CODE>double</CODE> and y of type <CODE>long int</CODE>.</p>
 *
 * @param x
 * @param y
 * @return the result of x^y
 */
FLOAT64 __dlm_pow_fi(FLOAT64 x, INT64 y) {
  FLOAT64 xy = x;
  INT64 i = ABS(y);

  if (y == 0) return 1.0;

  for (; i > 1; i--)
    xy *= x;

  if (y < 0) return 1.0 / xy;
  return xy;
}

/**
 * <p>x^y for x and y of type <CODE>double</CODE>. This is for performance reasons.
 * Test for integral type of <CODE>x</CODE> and <CODE>y</CODE> results in call to
 * <CODE>dlm_pow_ii</CODE> of <CODE>dlm_pow_fi</CODE>.</p>
 *
 * @param x
 * @param y
 * @return the result of x^y
 */
FLOAT64 dlm_pow(FLOAT64 x, FLOAT64 y)
{
  INT64 x_i;
  INT64 y_i;

  y_i = (INT64)(y + EPS);
  if (ABS(y - y_i) < (2 * EPS))
  {
    x_i = (INT64)(x + EPS);
    if (ABS(x - x_i) < (2 * EPS))
#ifdef __MAX_TYPE_32BIT
      return __dlm_pow_fi(x, y_i);
#else
      return __dlm_pow_ii(x_i, y_i);
#endif
    else
      return __dlm_pow_fi(x, y_i);
  }
  return pow(x, y);
}

/**
 * <p>x^y for x and y of type <CODE>complex</CODE>.</p>
 *
 * @param x
 * @param y
 * @return the result of x^y
 */
COMPLEX64 dlm_powC(COMPLEX64 z1, COMPLEX64 z2)
{
  FLOAT64 x1 = log(CMPLX_ABS(z1));
  FLOAT64 y1 = CMPLX_ANGLE(z1);
  FLOAT64 x2 = (x1*z2.x) - (y1*z2.y);
  FLOAT64 y2 = (x1*z2.y) + (y1*z2.x);
  FLOAT64 s = exp(x2);
  return CMPLXY(s*cos(y2), s*sin(y2));
}

/**
 * <p>Approximation of z=10^x</p>
 *
 * @param x
 *          Exponent.
 * @return z
 *          result of 10^x
 */
FLOAT64 dlm_pow10(FLOAT64 x) {
  FLOAT64 x_p = (x < 0) ? -x : x;
  INT32    x_d = (INT32)x_p;
  FLOAT64 x_r = x_p - x_d;
  INT32    i;
  FLOAT64 z;
  static FLOAT64 pow10_approx[1024] = { 1.00000000, 1.00112604, 1.00225335, 1.00338193, 1.00451178, 1.00564290, 1.00677530, 1.00790897, 1.00904392, 1.01018014, 1.01131765, 1.01245643, 1.01359650, 1.01473785, 1.01588049, 1.01702441, 1.01816963, 1.01931613, 1.02046392, 1.02161300, 1.02276338, 1.02391506, 1.02506803, 1.02622230, 1.02737787, 1.02853474, 1.02969291, 1.03085239, 1.03201317, 1.03317526, 1.03433866, 1.03550337, 1.03666939, 1.03783672, 1.03900537, 1.04017533, 1.04134661, 1.04251921, 1.04369313, 1.04486837, 1.04604494, 1.04722283, 1.04840204, 1.04958259, 1.05076446, 1.05194767, 1.05313220, 1.05431807, 1.05550528, 1.05669382, 1.05788371, 1.05907493, 1.06026749, 1.06146139, 1.06265664, 1.06385324, 1.06505118, 1.06625047, 1.06745112, 1.06865311, 1.06985646, 1.07106116, 1.07226722, 1.07347464, 1.07468342, 1.07589356, 1.07710506, 1.07831792, 1.07953215, 1.08074775, 1.08196472, 1.08318305, 1.08440276, 1.08562385, 1.08684630, 1.08807014, 1.08929535, 1.09052194, 1.09174992, 1.09297927, 1.09421001, 1.09544214, 1.09667565, 1.09791055, 1.09914685, 1.10038453, 1.10162361, 1.10286409, 1.10410596, 1.10534923, 1.10659389, 1.10783997, 1.10908744, 1.11033632, 1.11158660, 1.11283830, 1.11409140, 1.11534591, 1.11660184, 1.11785918, 1.11911793, 1.12037811, 1.12163970, 1.12290271, 1.12416715, 1.12543301, 1.12670029, 1.12796900, 1.12923914, 1.13051071, 1.13178372, 1.13305815, 1.13433402, 1.13561133, 1.13689007, 1.13817026, 1.13945189, 1.14073496, 1.14201947, 1.14330543, 1.14459284, 1.14588170, 1.14717201, 1.14846378, 1.14975700, 1.15105167, 1.15234780, 1.15364539, 1.15494445, 1.15624496, 1.15754694, 1.15885039, 1.16015530, 1.16146168, 1.16276954, 1.16407887, 1.16538967, 1.16670194, 1.16801570, 1.16933093, 1.17064765, 1.17196585, 1.17328553, 1.17460670, 1.17592935, 1.17725350, 1.17857914, 1.17990627, 1.18123489, 1.18256501, 1.18389663, 1.18522974, 1.18656436, 1.18790048, 1.18923811, 1.19057724, 1.19191788, 1.19326003, 1.19460369, 1.19594886, 1.19729555, 1.19864376, 1.19999348, 1.20134472, 1.20269748, 1.20405177, 1.20540758, 1.20676492, 1.20812379, 1.20948419, 1.21084612, 1.21220958, 1.21357458, 1.21494112, 1.21630919, 1.21767881, 1.21904996, 1.22042266, 1.22179691, 1.22317270, 1.22455005, 1.22592894, 1.22730939, 1.22869139, 1.23007495, 1.23146006, 1.23284674, 1.23423498, 1.23562478, 1.23701614, 1.23840907, 1.23980357, 1.24119964, 1.24259729, 1.24399650, 1.24539729, 1.24679966, 1.24820361, 1.24960914, 1.25101625, 1.25242495, 1.25383523, 1.25524710, 1.25666056, 1.25807562, 1.25949226, 1.26091050, 1.26233034, 1.26375178, 1.26517481, 1.26659945, 1.26802570, 1.26945355, 1.27088300, 1.27231407, 1.27374675, 1.27518104, 1.27661695, 1.27805447, 1.27949362, 1.28093438, 1.28237676, 1.28382077, 1.28526641, 1.28671367, 1.28816257, 1.28961309, 1.29106525, 1.29251904, 1.29397447, 1.29543154, 1.29689025, 1.29835060, 1.29981260, 1.30127624, 1.30274154, 1.30420848, 1.30567707, 1.30714732, 1.30861922, 1.31009278, 1.31156800, 1.31304488, 1.31452342, 1.31600363, 1.31748550, 1.31896905, 1.32045426, 1.32194115, 1.32342971, 1.32491995, 1.32641186, 1.32790546, 1.32940073, 1.33089769, 1.33239634, 1.33389667, 1.33539870, 1.33690241, 1.33840782, 1.33991492, 1.34142372, 1.34293422, 1.34444642, 1.34596032, 1.34747593, 1.34899325, 1.35051227, 1.35203300, 1.35355545, 1.35507961, 1.35660548, 1.35813308, 1.35966239, 1.36119343, 1.36272619, 1.36426067, 1.36579689, 1.36733483, 1.36887451, 1.37041592, 1.37195906, 1.37350395, 1.37505057, 1.37659893, 1.37814904, 1.37970090, 1.38125450, 1.38280985, 1.38436695, 1.38592580, 1.38748641, 1.38904878, 1.39061291, 1.39217880, 1.39374645, 1.39531586, 1.39688705, 1.39846000, 1.40003472, 1.40161122, 1.40318949, 1.40476954, 1.40635137, 1.40793498, 1.40952038, 1.41110756, 1.41269652, 1.41428728, 1.41587982, 1.41747416, 1.41907030, 1.42066823, 1.42226796, 1.42386949, 1.42547283, 1.42707797, 1.42868492, 1.43029368, 1.43190425, 1.43351664, 1.43513083, 1.43674685, 1.43836469, 1.43998435, 1.44160583, 1.44322914, 1.44485427, 1.44648124, 1.44811004, 1.44974067, 1.45137314, 1.45300745, 1.45464359, 1.45628158, 1.45792142, 1.45956310, 1.46120662, 1.46285200, 1.46449924, 1.46614832, 1.46779927, 1.46945207, 1.47110674, 1.47276326, 1.47442166, 1.47608192, 1.47774405, 1.47940805, 1.48107392, 1.48274167, 1.48441130, 1.48608281, 1.48775620, 1.48943148, 1.49110864, 1.49278769, 1.49446863, 1.49615146, 1.49783619, 1.49952282, 1.50121134, 1.50290177, 1.50459410, 1.50628834, 1.50798448, 1.50968253, 1.51138250, 1.51308438, 1.51478817, 1.51649389, 1.51820152, 1.51991108, 1.52162257, 1.52333598, 1.52505132, 1.52676859, 1.52848779, 1.53020893, 1.53193201, 1.53365703, 1.53538399, 1.53711290, 1.53884375, 1.54057656, 1.54231131, 1.54404802, 1.54578668, 1.54752730, 1.54926988, 1.55101442, 1.55276093, 1.55450940, 1.55625984, 1.55801226, 1.55976664, 1.56152301, 1.56328135, 1.56504167, 1.56680397, 1.56856825, 1.57033453, 1.57210279, 1.57387304, 1.57564529, 1.57741953, 1.57919577, 1.58097401, 1.58275426, 1.58453650, 1.58632076, 1.58810702, 1.58989529, 1.59168558, 1.59347789, 1.59527221, 1.59706855, 1.59886692, 1.60066731, 1.60246973, 1.60427417, 1.60608065, 1.60788917, 1.60969972, 1.61151231, 1.61332694, 1.61514361, 1.61696233, 1.61878310, 1.62060591, 1.62243078, 1.62425771, 1.62608669, 1.62791773, 1.62975083, 1.63158600, 1.63342324, 1.63526254, 1.63710391, 1.63894736, 1.64079288, 1.64264048, 1.64449017, 1.64634193, 1.64819578, 1.65005172, 1.65190974, 1.65376986, 1.65563208, 1.65749639, 1.65936280, 1.66123131, 1.66310192, 1.66497465, 1.66684948, 1.66872642, 1.67060547, 1.67248665, 1.67436994, 1.67625535, 1.67814288, 1.68003254, 1.68192432, 1.68381824, 1.68571429, 1.68761248, 1.68951280, 1.69141526, 1.69331986, 1.69522661, 1.69713551, 1.69904655, 1.70095975, 1.70287510, 1.70479261, 1.70671228, 1.70863411, 1.71055810, 1.71248426, 1.71441259, 1.71634309, 1.71827576, 1.72021061, 1.72214764, 1.72408685, 1.72602825, 1.72797182, 1.72991759, 1.73186555, 1.73381571, 1.73576805, 1.73772260, 1.73967935, 1.74163830, 1.74359946, 1.74556282, 1.74752840, 1.74949619, 1.75146620, 1.75343842, 1.75541286, 1.75738953, 1.75936843, 1.76134955, 1.76333290, 1.76531849, 1.76730631, 1.76929637, 1.77128867, 1.77328322, 1.77528001, 1.77727905, 1.77928034, 1.78128388, 1.78328968, 1.78529774, 1.78730806, 1.78932064, 1.79133549, 1.79335261, 1.79537200, 1.79739366, 1.79941760, 1.80144382, 1.80347232, 1.80550311, 1.80753618, 1.80957154, 1.81160919, 1.81364914, 1.81569139, 1.81773593, 1.81978278, 1.82183193, 1.82388339, 1.82593716, 1.82799324, 1.83005163, 1.83211235, 1.83417538, 1.83624074, 1.83830842, 1.84037844, 1.84245078, 1.84452545, 1.84660247, 1.84868182, 1.85076351, 1.85284755, 1.85493393, 1.85702266, 1.85911375, 1.86120719, 1.86330299, 1.86540114, 1.86750166, 1.86960455, 1.87170980, 1.87381742, 1.87592742, 1.87803979, 1.88015454, 1.88227168, 1.88439119, 1.88651309, 1.88863739, 1.89076407, 1.89289315, 1.89502463, 1.89715850, 1.89929478, 1.90143347, 1.90357456, 1.90571807, 1.90786398, 1.91001232, 1.91216307, 1.91431625, 1.91647185, 1.91862987, 1.92079033, 1.92295322, 1.92511855, 1.92728631, 1.92945651, 1.93162916, 1.93380426, 1.93598180, 1.93816180, 1.94034425, 1.94252916, 1.94471653, 1.94690636, 1.94909866, 1.95129342, 1.95349066, 1.95569037, 1.95789256, 1.96009723, 1.96230438, 1.96451402, 1.96672614, 1.96894076, 1.97115787, 1.97337747, 1.97559958, 1.97782419, 1.98005130, 1.98228092, 1.98451305, 1.98674769, 1.98898485, 1.99122453, 1.99346674, 1.99571146, 1.99795872, 2.00020850, 2.00246082, 2.00471567, 2.00697307, 2.00923300, 2.01149548, 2.01376051, 2.01602809, 2.01829822, 2.02057091, 2.02284616, 2.02512396, 2.02740434, 2.02968728, 2.03197279, 2.03426088, 2.03655154, 2.03884478, 2.04114061, 2.04343902, 2.04574001, 2.04804360, 2.05034978, 2.05265856, 2.05496994, 2.05728392, 2.05960051, 2.06191971, 2.06424152, 2.06656594, 2.06889298, 2.07122264, 2.07355492, 2.07588983, 2.07822737, 2.08056754, 2.08291034, 2.08525579, 2.08760387, 2.08995460, 2.09230798, 2.09466400, 2.09702268, 2.09938402, 2.10174801, 2.10411467, 2.10648399, 2.10885598, 2.11123064, 2.11360797, 2.11598798, 2.11837067, 2.12075604, 2.12314410, 2.12553485, 2.12792829, 2.13032443, 2.13272326, 2.13512480, 2.13752904, 2.13993599, 2.14234564, 2.14475801, 2.14717310, 2.14959091, 2.15201144, 2.15443469, 2.15686067, 2.15928939, 2.16172084, 2.16415503, 2.16659195, 2.16903163, 2.17147405, 2.17391922, 2.17636714, 2.17881782, 2.18127126, 2.18372746, 2.18618643, 2.18864817, 2.19111268, 2.19357996, 2.19605002, 2.19852287, 2.20099850, 2.20347691, 2.20595812, 2.20844212, 2.21092892, 2.21341852, 2.21591092, 2.21840613, 2.22090414, 2.22340497, 2.22590862, 2.22841509, 2.23092437, 2.23343649, 2.23595143, 2.23846921, 2.24098981, 2.24351326, 2.24603955, 2.24856869, 2.25110067, 2.25363550, 2.25617319, 2.25871373, 2.26125714, 2.26380341, 2.26635255, 2.26890455, 2.27145943, 2.27401719, 2.27657783, 2.27914135, 2.28170776, 2.28427706, 2.28684925, 2.28942434, 2.29200232, 2.29458321, 2.29716701, 2.29975372, 2.30234334, 2.30493587, 2.30753132, 2.31012970, 2.31273100, 2.31533523, 2.31794240, 2.32055250, 2.32316554, 2.32578152, 2.32840044, 2.33102232, 2.33364715, 2.33627493, 2.33890568, 2.34153938, 2.34417605, 2.34681569, 2.34945830, 2.35210389, 2.35475246, 2.35740401, 2.36005854, 2.36271607, 2.36537658, 2.36804010, 2.37070661, 2.37337612, 2.37604864, 2.37872417, 2.38140272, 2.38408427, 2.38676885, 2.38945645, 2.39214708, 2.39484074, 2.39753743, 2.40023716, 2.40293992, 2.40564573, 2.40835459, 2.41106650, 2.41378146, 2.41649948, 2.41922056, 2.42194470, 2.42467191, 2.42740219, 2.43013555, 2.43287198, 2.43561150, 2.43835410, 2.44109979, 2.44384857, 2.44660044, 2.44935542, 2.45211349, 2.45487467, 2.45763897, 2.46040637, 2.46317689, 2.46595053, 2.46872729, 2.47150718, 2.47429020, 2.47707636, 2.47986565, 2.48265808, 2.48545366, 2.48825238, 2.49105426, 2.49385929, 2.49666748, 2.49947883, 2.50229335, 2.50511103, 2.50793189, 2.51075593, 2.51358314, 2.51641354, 2.51924713, 2.52208391, 2.52492388, 2.52776705, 2.53061342, 2.53346299, 2.53631578, 2.53917178, 2.54203099, 2.54489342, 2.54775908, 2.55062796, 2.55350007, 2.55637542, 2.55925401, 2.56213583, 2.56502091, 2.56790923, 2.57080080, 2.57369563, 2.57659372, 2.57949507, 2.58239969, 2.58530758, 2.58821874, 2.59113318, 2.59405091, 2.59697192, 2.59989621, 2.60282381, 2.60575469, 2.60868888, 2.61162638, 2.61456718, 2.61751129, 2.62045871, 2.62340946, 2.62636353, 2.62932092, 2.63228165, 2.63524571, 2.63821310, 2.64118384, 2.64415792, 2.64713536, 2.65011614, 2.65310028, 2.65608778, 2.65907865, 2.66207288, 2.66507049, 2.66807147, 2.67107583, 2.67408357, 2.67709470, 2.68010922, 2.68312713, 2.68614845, 2.68917316, 2.69220128, 2.69523281, 2.69826776, 2.70130612, 2.70434790, 2.70739311, 2.71044175, 2.71349382, 2.71654933, 2.71960827, 2.72267067, 2.72573651, 2.72880580, 2.73187855, 2.73495476, 2.73803443, 2.74111757, 2.74420418, 2.74729427, 2.75038784, 2.75348489, 2.75658543, 2.75968946, 2.76279699, 2.76590801, 2.76902254, 2.77214057, 2.77526212, 2.77838718, 2.78151576, 2.78464786, 2.78778349, 2.79092265, 2.79406535, 2.79721158, 2.80036136, 2.80351468, 2.80667156, 2.80983199, 2.81299597, 2.81616352, 2.81933464, 2.82250933, 2.82568759, 2.82886943, 2.83205486, 2.83524387, 2.83843647, 2.84163267, 2.84483247, 2.84803587, 2.85124288, 2.85445349, 2.85766773, 2.86088558, 2.86410706, 2.86733216, 2.87056090, 2.87379327, 2.87702928, 2.88026893, 2.88351224, 2.88675919, 2.89000980, 2.89326407, 2.89652201, 2.89978361, 2.90304889, 2.90631784, 2.90959048, 2.91286680, 2.91614681, 2.91943051, 2.92271791, 2.92600901, 2.92930382, 2.93260234, 2.93590457, 2.93921052, 2.94252020, 2.94583360, 2.94915073, 2.95247160, 2.95579620, 2.95912455, 2.96245665, 2.96579250, 2.96913211, 2.97247547, 2.97582260, 2.97917350, 2.98252818, 2.98588663, 2.98924886, 2.99261488, 2.99598469, 2.99935829, 3.00273569, 3.00611690, 3.00950191, 3.01289074, 3.01628338, 3.01967984, 3.02308012, 3.02648424, 3.02989219, 3.03330397, 3.03671960, 3.04013907, 3.04356239, 3.04698957, 3.05042061, 3.05385551, 3.05729428, 3.06073692, 3.06418344, 3.06763383, 3.07108812, 3.07454629, 3.07800836, 3.08147432, 3.08494419, 3.08841797, 3.09189565, 3.09537726, 3.09886278, 3.10235223, 3.10584561, 3.10934292, 3.11284417, 3.11634936, 3.11985850, 3.12337159, 3.12688864, 3.13040965, 3.13393462, 3.13746356, 3.14099647, 3.14453337, 3.14807424, 3.15161910, 3.15516796, 3.15872081, 3.16227766 };

  if(x_r < 0.5) {
    z = dlm_pow(10, x_d);
    x_r = x_r * 1023.0 / 0.5;
    i = (x_r - (INT32)x_r) > 0.5 ? (INT32)x_r+1 : (INT32)x_r;
    z *= pow10_approx[i];
  } else {
    x_d++;
    x_r = 1.0 - x_r;

    z = dlm_pow(10, x_d);
    x_r = x_r * 1023.0 / 0.5;
    i = (x_r - (INT32)x_r) > 0.5 ? (INT32)x_r+1 : (INT32)x_r;
    z /= pow10_approx[i];
  }
  if(x < 0.0) z = 1.0 / z;

  return z;
}

/**
 * <p>Natural logarithm of complex number.</p>
 *
 * @param z
 *          Complex input number.
 * @return
 *          Result of log<sub>b</sub>(z).
 */
COMPLEX64 dlm_logC(COMPLEX64 z) {
  return CMPLXY(log(CMPLX_ABS(z)),CMPLX_ANGLE(z));
}

/**
 * <p>Logarithm of complex number to complex basis.</p>
 *
 * @param b
 *          Basis (may be complex).
 * @param z
 *          Complex input number.
 * @return
 *          Result of log<sub>b</sub>(z).
 */
COMPLEX64 dlm_log_bC(COMPLEX64 b, COMPLEX64 z) {
  return CMPLX_DIV(dlm_logC(z),dlm_logC(b));
}

/**
 * <p>Exponential of complex number.</p>
 *
 * @param z
 *          Complex input number.
 * @return
 *          Result of exp<sup>z</sup>.
 */
COMPLEX64 dlm_expC(COMPLEX64 z) {
  FLOAT64 tmp = exp(z.x);
  return CMPLXY(tmp*cos(z.y),tmp*sin(z.y));
}
