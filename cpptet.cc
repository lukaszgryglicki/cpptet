#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define DB long double
#define DO(x,y) for(x=0;x<y;x++)
#include <complex.h>
#define z_type std::complex<long double>
#define Re(x) x.real()
#define Im(x) x.imag()
#define I z_type(0.,1.)

z_type L=z_type(0.3181315052047641353,1.337235701430689409);
z_type Zo=z_type(.31813150520476413, 1.3372357014306895);
z_type Zc=z_type(.31813150520476413,-1.3372357014306895);

DB DE[128]={
    1.4192252155045112363
	,-0.05213258059503801667
	, 0.00693219127232187586
	,-0.00015617045803377859
	,-0.00100912103192385785
	, 0.00082172671942507903
	,-0.00035776641706493177
	,-0.00000931803078422933
	, 0.00016678111348857047
	,-0.00014181446429806932
	, 0.00003186488716454018
	, 0.00006022937595596333
	,-0.00007769822429012910
	, 0.00002881816919640196
	, 0.00003346765914794806
	,-0.00005635940084759932
	, 0.00002613708927959275
	, 0.00002533341053138444
	,-0.00005010441151688034
	, 0.00002593810263640952
	, 0.00002404611936084357
	,-0.00005163238246428602
	, 0.00002794638872473000
	, 0.00002700739592764804
	,-0.00005939035114511979
	, 0.00003210955504312860
	, 0.00003438232223525011
	,-0.00007428278434380886
	, 0.00003866302665809861
	, 0.00004803799918127077
	,-0.00009914141292927652
	, 0.00004800025436154043
	, 0.00007191960183392704
	,-0.00013922522917537457
	, 0.00006043126908005670
	, 0.00011338211995240744
	,-0.00020351111316586852
	, 0.00007562971718596908
	, 0.00018585637209671475
	,-0.00030700846364341576
	, 0.00009132512919756623
	, 0.00031386108850653502
	,-0.00047464470561729965
	, 0.00010030770871287629
	, 0.00054232170050706079
	,-0.00074759603610534669
	, 0.00008375204845585605
	, 0.00095389423083896800
	,-0.00119336225449479362
	,-0.00000327383738614825
	, 0.00170107934819055851
	,-0.00192109516273315209
	,-0.00026290310001950487
	, 0.00306590657916818192
	,-0.00310372506294090238
	,-0.00091982425407694250
	, 0.00556979490215834833
	,-0.00500546835451257978
	,-0.00245869651201214212
	, 0.01017705593773498771
	,-0.00800820238034244403
	,-0.00590649361431362999
	, 0.01866321477729812259
	,-0.01260156096677063874
	,-0.01341963601206602220
	, 0.03429254345271898208
	,-0.01926894593144593687
	,-0.02946277663641767158
	, 0.06300065960337521143
	,-0.02800532706641396460
	,-0.06325609033757989552
	, 0.11556117355587923468
	,-0.03708367328869965895
	,-0.13352664223772733876
	, 0.21104853030721187901
	,-0.03941069742436464907
	,-0.27853504829255953945
	, 0.38331715278474703945
	,-0.01491397058539710788
	,-0.57446133459038406510
	, 0.68905734940479856920
	, 0.09065013779953061401
	,-1.17542205931169707611
	, 1.22536662105515059551
	, 0.40500835675024698945
	,-2.37977019901803332758
	, 2.13411821810153146117
	, 1.24184396615612624437
	,-4.78947531960227212977
	, 3.64093109251482172084
	, 3.27095016057312193425
	,-9.53051815711462246838
	, 5.92750355113636295812
	, 8.12068845726284394004
	,-18.89123486907114468636
	, 9.07245090167984002960
	,18.99435214920948311601
	,-36.62201395750987842348
	,12.69160696640316032813
	,43.73569046442687380249
	,-71.43155879446639744401
	,14.83661067193675719977
	,95.94011857707508283966
	,-135.28537549407113260713
	, 4.55415019762845751927
	,212.46383399209483400227
	,-258.45286561264816782568
	,-34.35533596837944259050
	,440.37608695652170354151
	,-466.49328063241102881875
	,-184.78893280632408391284
	,969.10988142292478642048
	,-888.80079051383393107244
	,-485.21897233201576682404
	,1912.15652173913008482486
	,-1381.80553359683767666866
	,-1490.15335968379417863616
	,4216.82213438735107047250
	,-2565.99525691699591334327
	,-3155.47826086956501967506
	,7689.57470355731129529886
	,-3206.47588932806274897303
	,-8547.41501976284416741692
	,17971.70592885375299374573
	,-7203.41501976284507691162
	,-16388.65454545454485923983
	,28589.12885375493715400808
	,-2355.80711462450562976301
};

z_type slo(z_type z1)
{ 
    int K=128,k;
    z_type z=z1-(DB)1.;  z/=(DB)2.;
    z_type s=0.; //z_type t=1; 
    for(k=K-1;k>0;k--){ s+=DE[k]; s*=z; }
    s+=DE[0];
    s+=log(z1-Zo)/Zo+log(z1-Zc)/Zc;
    return s;
}

z_type FSLOG(z_type z1)
{ 
    DB x=Re(z1),  y=Im(z1);
    if(fabs(y)>fabs(Im(Zo)) ) return FSLOG(log(z1))+(DB)1.;
    if(x	  <     Re(Zo)  ) return FSLOG(exp(z1))-(DB)1.;
    if(x>2) return FSLOG(log(z1))+(DB)1.;
    z_type z=z1-(DB)1.;
    z_type LZ=log(z1); if( abs(LZ-(DB)1.)<   abs(z) ) return FSLOG(LZ)+(DB)1.;
    //z_type EZ=exp(z1); if( abs(EZ-1.)<.1*abs(z) ) return FSLOG(EZ)-1.;
    return slo(z1);    
}

z_type fima(z_type z)
{ 
    z_type c,e;
    z_type Zo=z_type(.31813150520476413, 1.3372357014306895);
    z_type Zc=z_type(.31813150520476413,-1.3372357014306895);
    z_type R=z_type(1.0779614375280 , -.9465409639480); 
    z_type a2=(DB).5/(Zo-(DB)1.);
    z_type a3=(a2+(DB)1./(DB)6.)/(Zo*Zo-(DB)1.);
    z_type a4=(a2/(DB)2.+a2*a2/(DB)2.+a3+(DB)1./(DB)24.)/(Zo*Zo*Zo-(DB)1.);
    z_type a5=((DB).5*a2*a2+a2/(DB)6.+a2*a3+a3/(DB)2.+a4+(DB)1./(DB)120.)/(Zo*Zo*Zo*Zo-(DB)1.);
    z_type Li=(DB)2.*M_PI*I;
    z_type b0=z_type(0.1223,       -0.02370);
    //printf("b0=%11.5Lf %11.5Lf\n", Re(b0),Im(b0 )) ;
    e=exp(Zo*z+R); 
    c= Zo + e*( (DB)1. + e*(a2+e*(a3+e*(a4+e*a5))) + b0*exp(Li*z) );
    return c;
}

z_type tai3(z_type z)
{ 
    int K=50,k;
    z_type DER3[51]={
     z_type( 0.37090658903228507226, 1.33682167078891400713)
     ,z_type( 0.03660096537598455518, 0.13922215389950498565)
     ,z_type(-0.16888431840641535131, 0.09718533619629270148)
     ,z_type(-0.12681315048680869007,-0.11831628767028627702)
     ,z_type( 0.04235809310323926380,-0.10520930088320722129)
     ,z_type( 0.05848306393563178218,-0.00810224524496080435)
     ,z_type( 0.02340031665294847393, 0.01807777011820375229)
     ,z_type( 0.00344260984701375092, 0.01815103755635914459)
     ,z_type(-0.00803695814441672193, 0.00917428467034995393)
     ,z_type(-0.00704695528168774229,-0.00093958506727472686)
     ,z_type(-0.00184617963095305509,-0.00322342583181676459)
     ,z_type( 0.00054064885443097391,-0.00189672061015605498)
     ,z_type( 0.00102243648088806748,-0.00055968657179243165)
     ,z_type( 0.00064714396398048754, 0.00025980661935827123)
     ,z_type( 0.00010444455593372213, 0.00037199472598828116)
     ,z_type(-0.00011178535404343476, 0.00016786687552190863)
     ,z_type(-0.00010630158710808594, 0.00002072200033125881)
     ,z_type(-0.00005078098819110608,-0.00003575913005741248)
     ,z_type(-0.00000314742998690270,-0.00003523185937587781)
     ,z_type( 0.00001347661344130504,-0.00001333034137448205)
     ,z_type( 0.00000980239082395275, 0.00000047607184151673)
     ,z_type( 0.00000355493475454698, 0.00000389816212201278)
     ,z_type(-0.00000021552652645735, 0.00000296273413237997)
     ,z_type(-0.00000131673903627820, 0.00000097381354534333)
     ,z_type(-0.00000083401960806066,-0.00000018663858711081)
     ,z_type(-0.00000022869610981361,-0.00000037497716770031)
     ,z_type( 0.00000005372584613379,-0.00000023060136585176)
     ,z_type( 0.00000011406656653786,-0.00000006569510293486)
     ,z_type( 0.00000006663595460757, 0.00000002326630571343)
     ,z_type( 0.00000001396786846375, 0.00000003315118300198)
     ,z_type(-0.00000000684890556421, 0.00000001713041981611)
     ,z_type(-0.00000000916619598268, 0.00000000403886083652)
     ,z_type(-0.00000000502933384276,-0.00000000222121299478)
     ,z_type(-0.00000000084484352792,-0.00000000273668661113)
     ,z_type( 0.00000000070086729861,-0.00000000124687683156)
     ,z_type( 0.00000000070558101710,-0.00000000021962577544)
     ,z_type( 0.00000000035900951951, 0.00000000018774741308)
     ,z_type( 0.00000000005248658571, 0.00000000021201177126)
     ,z_type(-0.00000000006264758835, 0.00000000009059171879)
     ,z_type(-0.00000000005333473585, 0.00000000001006078866)
     ,z_type(-0.00000000002432138144,-0.00000000001506937008)
     ,z_type(-0.00000000000331880379,-0.00000000001544700067)
     ,z_type( 0.00000000000501652570,-0.00000000000658967459)
     ,z_type( 0.00000000000401214135,-0.00000000000036708383)
     ,z_type( 0.00000000000158629111, 0.00000000000119885992)
     ,z_type( 0.00000000000019668766, 0.00000000000106532662)
     ,z_type(-0.00000000000036355730, 0.00000000000047229527)
     ,z_type(-0.00000000000029920206, 0.00000000000001251827)
     ,z_type(-0.00000000000010305550,-0.00000000000009571381)
     ,z_type(-0.00000000000000910369,-0.00000000000007087680)
     ,z_type( 0.00000000000002418310,-0.00000000000003240337)
     };

    z_type s=0.,t=1.;
    z-=z_type(0.,3.); z/=2.; 
    for(k=0;k<K;k++) { s+=DER3[k]*t; t*=z; }
    return s;
}

z_type maclo(z_type z) 
{  
    int K=100,k;
    DB d[110]={
      0.30685281944005469058 
      , 1.18353470251664338875
      , 1.58593285160678321155
      , 1.36629265207672068172
      , 1.36264601823980036066
      , 1.21734246689515424045
      , 1.10981816083559525765
      , 0.96674692974769849130
      , 0.84089872598668435888
      , 0.71353210966804747617
      , 0.60168548504001373445
      , 0.49928574281440518678
      , 0.41140086629121763728
      , 0.33506195665178500898
      , 0.27104779243942234146
      , 0.21728554054610033086
      , 0.17311050207880035456
      , 0.13690016038526570119
      , 0.10765949732729711286
      , 0.08413804539743192923
      , 0.06542450487497340761
      , 0.05060001212013485322
      , 0.03895655493977817629
      , 0.02985084640296329153
      , 0.02277908979501017117
      , 0.01730960309240666892
      , 0.01310389615589767874
      , 0.00988251130733762764
      , 0.00742735935367278347
      , 0.00556296426263720549
      , 0.00415334478103463346
      , 0.00309116153137843543
      , 0.00229387529664008653
      , 0.00169729976398295653
      , 0.00125245885041635465
      , 0.00092172809095368547
      , 0.00067661152429638357
      , 0.00049544127485341987
      , 0.00036192128589181518
      , 0.00026376927786672476
      , 0.00019180840045267570
      , 0.00013917553105723647
      , 0.00010077412023867018
      , 0.00007281884753121133
      , 0.00005251474516228446
      , 0.00003779882770351268
      , 0.00002715594536867241
      , 0.00001947408515177282
      , 0.00001394059355016322
      , 0.00000996213949015693
      , 0.00000710713872292710
      , 0.00000506199803708578
      , 0.00000359960968975399
      , 0.00000255569149787694
      , 0.00000181175810338313
      , 0.00000128245831538430
      , 0.00000090647322737496
      , 0.00000063980422418981
      , 0.00000045095738191441
      , 0.00000031741772125007
      , 0.00000022312521183625
      , 0.00000015663840476155
      , 0.00000010982301013230
      , 0.00000007690305934973
      , 0.00000005378502675604
      , 0.00000003757126131521
      , 0.00000002621429405247
      , 0.00000001826909956818
      , 0.00000001271754463425
      , 0.00000000884310192977
      , 0.00000000614230041407
      , 0.00000000426177146865
      , 0.00000000295386817285
      , 0.00000000204522503591
      , 0.00000000141464900426
      , 0.00000000097750884878
      , 0.00000000067478454029
      , 0.00000000046535930671
      , 0.00000000032062550784
      , 0.00000000022069891976
      , 0.00000000015177557961
      , 0.00000000010428189463
      , 0.00000000007158597119
      , 0.00000000004909806710
      , 0.00000000003364531769
      , 0.00000000002303635851
      , 0.00000000001575933679
      , 0.00000000001077213757
      , 0.00000000000735717912
      , 0.00000000000502077719
      , 0.00000000000342362421
      , 0.00000000000233271256
      , 0.00000000000158818623
      , 0.00000000000108046566
      , 0.00000000000073450488
      , 0.00000000000049894945
      , 0.00000000000033868911
      , 0.00000000000022973789
      , 0.00000000000015572383
      , 0.00000000000010548054
      , 0.00000000000007139840
      , 0.00000000000004829557
      , 0.00000000000003264619
      , 0.00000000000002205299
      , 0.00000000000001488731
      , 0.00000000000001004347
      , 0.00000000000000677124
      , 0.00000000000000456225
      , 0.00000000000000307196
      , 0.00000000000000206720
      };

      z_type s=0.;
      z_type z2=z/(DB)2.;
      z_type t=1.; 
      for(k=0;k<=K;k++) { s+=d[k]*t; t*=z2; }
      return s+log(z+(DB)2.);
}

z_type FIMA(z_type z)
{        
    DB x=Re(z);
    DB y=Im(z);
    if(y < 0.2379*x) return exp(FIMA(z-(DB)1.));
    return fima(z); 
}

z_type TAI3(z_type z)
{ 
    DB x=Re(z);
    if(x > 0.5) return exp(TAI3(z-(DB)1.));
    if(x < -.5) return log(TAI3(z+(DB)1.));
    return tai3(z); 
}
    
z_type MACLO(z_type z)
{        
    DB x=Re(z); 
    z_type c;
    if(x > 0.5)
    {       
	c=z-(DB)1.;
	c=MACLO(c);
	c=exp(c);
	//printf("about to return (%9.3Lf, %9.3Lfi)\n",Re(c),Im(c));
	//getchar();
	return c;
    }
          
    if(x < -.5) return log(MACLO(z+(DB)1.));
    return maclo(z); 
}
                                 
z_type FSEXP(z_type z)
{
    DB y=Im(z);
    if(y> 4.5) return FIMA(z);
    if(y> 1.5) return TAI3(z);
    if(y>-1.5) return MACLO(z);
    if(y>-4.5) return conj(TAI3(conj(z)));
    return conj(FIMA(conj(z)));                        
}

int main(int lb, char** par)
{
    z_type z, f, h;
    char op;
    DB hr, hi;
    if (lb == 1) printf("%s [e|l|h] [Re=1 [Im=0 [iterRe=0.5 [iterIm=0]]]]\ne: sexp\nl: slog\nh: hexp\n", par[0]);

    op = (lb > 1) ? par[1][0] : ' ';

    z = z_type( (lb > 2) ? atof(par[2]) : 1., 
	        (lb > 3) ? atof(par[3]) : 0.);
    if (op == 'e') 
    {
	f = FSEXP(z);
	printf("sexp((%13.5Lf, %13.5Lfi)) = (%13.5Lf, %13.5Lfi)\n", Re(z), Im(z), Re(f), Im(f));
    }
    
    if (op == 'l') 
    {
	f = FSLOG(z);
	printf("slog((%13.5Lf, %13.5Lfi)) = (%13.5Lf, %13.5Lfi)\n", Re(z), Im(z), Re(f), Im(f));
    }

    if (op == 'h') 
    {
	hr = (lb > 4) ? atof(par[4]) : 0.5;
	hi = (lb > 5) ? atof(par[5]) : 0.;
	h = z_type(hr, hi);
	f = FSEXP( h + FSLOG(z) );
	printf("partial (%13.5Lf, %13.5Lfi) iterate of exp:\n", Re(h), Im(h));
	printf("hexp((%13.5Lf, %13.5Lfi)) = (%13.5Lf, %13.5Lfi)\n", Re(z), Im(z), Re(f), Im(f));
    }

    return 0;
}

