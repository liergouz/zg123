/*----------------------------------------------------------------------------------*\
	ս������Ŀ����ļ�������һЩͨ�ù��ܵĿ��ƴ���
	�� cjxx �� 2007-09-14 ����
\*----------------------------------------------------------------------------------*/
#include <ansi.h>

/*------------------------------------Ԥ�������---------------------------------------*/
#define PLAYER_GET_PRIZE	"can_get_prize"
#define PLAYER_BE_GALA		"can_be_gala"
#define ZGDICT_ITEM		"item/01/7600"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}
/*---------------------------------------���------------------------------------------*/

/*------------------------------------��˽�б���---------------------------------------*/
//	MAPPING �ṹ��1��->��ʼ�ȼ���2��->�����ȼ���3��->��Ӧ��Ϣ
private static mapping lv_user_info = ([
	0  : ([
		9  : ({
			"��    �����ִ塢�Ĺȡ���Ϫ��һЩʹ�������ʹ����Ʒ��ֻҪ���ʹ�������ʰȡʹ����Ʒȥ�����ӳ����ͻ�������Ľ���Ŷ��",
			"��    ������Щ����ͷ�ϵ��ʺ������Ǳ�ʾ������������Ҫ��������Ͽ��ȥ������̸̸�ɣ�",
			"��    �����ִ塢�Ĺȡ���Ϫ�Ͱ��������ʺ��������ĵط���",
			"��    Ұ��Ĺ����ǲ��Ǻܿɰ���ȥ�ӻ����򼸸�Ǭ������Ȼ��ʹ�á����ﲶ׽�����ܾ���һ�����ʽ������Ϊ����Ŷ��",}),
		29 : ({
			"��    �ҵ�ʦ�����������û���ҵ��͸Ͽ�ȥ��������ȥ����ɣ��Ҹ�ʦ��������Ϥս��������",}),
		50 : ({
			"��    ���ӳ�������ȱ������ά���ΰ�����ȥ����Э���ΰ����ܵõ����������Ŷ��",}),
		150: ({
			"��    ����үү��ÿ�ܸ�����ṩ��4��Сʱ��˫��ʱ���3��Сʱ�Ķ���˫��ʱ�䣬��Ȼ������������VIP�����и����˫������ʱ����ȡ���Ͽ�ȥ����үү����ȡ˫������ɣ�",}),	]),
	10 : ([
		10 : ({
			"��    ��û�м��������𣿸Ͽ�ȥ��������ļ�ɣ������ܰ���ֱ�Ӵ�������פ�أ��������ɺ����ѧ���������ļ���Ŷ��",}),
		14 : ({
			"��    �����������ʱ�����ȥ����תת������İ������ȴ�����İ����أ�",
			"��    ������1��������2��������3����ӹ�ء���ɽ���һ�Դ�������������ʺ��������ĵط���",}),
		20 : ({
			"��    ���ܹ��м��Ҳ���һЩ����ܵ�ʦ�������ȥ�����������������ܣ����⻹��һ�����ڻ��ĸ��������Ҫ���м�������������ſ���ѧ����",}),
		30 : ({
			"��    ��˵�ܹ����ŵ�����ͷ��ȱ�����֣����пյ�ʱ����ȥ������ɣ�",}),]),
	11 : ([
		150: ({
			"��    ʦ���ﾭ��ȱ�����ְ��£�ȥ��ʦ�����ʰɣ�ǰ20����������з������Ŷ��Ҳ���㻹���������������ء�",}),]),
	15 : ([
		19 : ({
			"��    ����ɽ���仪ɽ�ͺ��ȹ������ʺ���弶�ĵط���Ҫ�����͸Ͽ�ȥ��Щ�ط��ɣ�",}),
		24 : ({
			"��    �������ʱ���ȥһ�˺����ɣ�����İ��������׵ȴ�����ȥ���������ء�",	}),]),
	20 : ([
		24 : ({
			"��    �������ڵĵȼ���������ȥ���¼����ط��������޶���1���޶���2���޶����ϡ����ꡢ�����������ׯ�Լ���̤����",}),
		29 : ({
			"��    κ���кܶ���Ҳ����������ĵ��������Ҹ�ʱ��ȥ�����ɣ�",}),]),
	25 : ([
		30 : ({
			"��    ���ιء�ݽ�ء���¹����¹����ˮ�����ꡢ��Ұ��̫��ɽ��������ƽԭ�����Ź��Լ���ƽ�����ʺ����ڵȼ���������ͼ��",	}),]),
	30 : ([
		34 : ({
			"��    �����кܶ�������ȴ�����İ������Ҹ�ʱ��ȥ�����ɣ�",}),
		150: ({
			"��    �����ȱǮ������ȥ�ܹ��ھ���ξ������ͷ���������ڣ���������񱨳�ġ�",
			"��    ����һֱʹ��ҩƷ�ǲ��Ǿ�����Щ�����㣿û��ϵ��ÿ���12�㵽24�㵽���ܹ�����ĸ�������԰�Դ����ҵ������ũ�򣬽���ũ��Ʒ����������ʳ��ܻ���ġ�",}),]),
	31 : ([
		40 : ({
			"��    �����Ե������ش������ɽ�š����ɽ����ɽ��۶��������ڡ�̫����̩ɽɽ�š�̩ɽ��Щ�����ֽ׶������ĺõط���",}),]),
	35 : ([
		39 : ({
			"��    ����������������������أ��㻹���Ҹ�ʱ���ȥ�����ĺá�",}),
		150: ({
			"��    ֪����������������������ʿǰ��������������ħ��ֻҪ�����һ��15��������ϡװ�������Ϳ��Դ򿪷���ͨ����ֻҪ���������ħ����85�����Ͼ���һֻBOSS�������������ϡװ��Ŷ��",}),]),
	40 : ([
		45 : ({
			"��    ��������ʱ�䲻��ȥ���ع������ع��İ������ģ�������һ�������ջ�ġ�"}),
		50 : ({
			"��    ȥ�������ȥ������������İɣ����Ǻ����кܶ�����Ҫ����˵��"}),
		60 : ({
			"��    �������Ѿ����㹻��ʵ�������������ˣ�������봴�����ɣ��Ǿ͸Ͽ�ȥѡһ�����Ұɣ����ܹ��⣩���ҵ��ù��İ����ܹܣ��Ϳ�����ȡ���������ˣ����ǣ��һ�Ҫ����һ�㣬��������������֮�Žǡ���ʱ�����Ҫ����100���ҵ�Ŷ��",
			"��    �����ͨ���ع���Ӫ���潫������ɽþ�Ӫ��ֻҪ���BOSS����һ�����ʻ����ɫ��װ����������ҪС��Ŷ������Ĺ��������Ŷ��"}),]),
	41 : ([
		50 : ({
			"��    �������ڵ�ʵ�����Ѿ����ʸ������˵�ʦ���ˣ���ȥ���ִ���һ��30�����µ����˰ɣ����ȥ�����ӡ���ͽ�ܴ���ʦ���з��Ľ���Ŷ��",
			"��    ������塢������������1������2����������֣����1��֣����2��֣����3���������ڿ���ȥ�ĵط���",
			"��    ��˵ÿ�����죬�ڶ�������һ����Ȯ̫�ɵļһ���߮���ݶ�������˵�����Ȯ̫�ɷǳ���������Ҫʮ��С�İ���"}),]),
	50 : ([
		54 : ({
			"��    ����ɽ�������塢������ء����Ʒ塢�����ص�����ɽ�ص����׷�ɽ�ص����������ĺõط���",}),
		55 : ({
			"��    �Թ�һֱ�ڵֿ�����ū�Ľ�����ȥ�����Թ����հɣ�������һ���в����ջ�ġ�",}),
		70 : ({
			"��    ��������ȥ�仪ɽ��139,117���ҵ��������Ŀ��ۡ�������ɽ��Ĺ�������в��ٺö���������ҪС��Ŷ������Ĺ���ǳ�������һ�����Ҳ���������",}),]),
	55 : ([
		59 : ({
			"��    �೤��1���೤��2���೤��3����ɽ��ԭ����ɽ�����޵��������ں��ʵ������㡣"}),]),
	60 : ([
		64 : ({
			"��    �Գ���1���Գ���2���Գ���3������ɽ��ԭ������ɽ������ħ��1������Ŀǰ�����ĺ�ȥ����",}),]),
	65 : ([
		69 : ({
			"��    �س���1���س���2���س���3����ԭ�ص�����ɽ�ص��������ص�����ɽ�ص�������þ�1������Ŀǰ�����ĺ�ȥ����",}),]),
	70 : ([
		74 : ({
			"��    ���1�����2�����3����ũ���Ͻ򡢵���ħ��2������Ŀǰ�����ĺ�ȥ����",}),]),
	75 : ([
		79 : ({
			"��    ��ȶ�1�㡢��ȶ�2�㡢��ȶ�3�㡢���ء��׾�������þ�2������Ŀǰ�����ĺ�ȥ����",}),]),			
	80 : ([
		84 : ({
			"��    ���˿�1�㡢���˿�2�㡢���˿�3�㡢���˿�4�㡢���˿�5�㡢�ڽ������ꡢ����ħ��3������Ŀǰ�����ĺ�ȥ����",}),]),
	85 : ([
		89 : ({
			"��    ����Ĺ1�㡢����Ĺ2�㡢����Ĺ3�㡢����Ĺ4�㡢����Ĺ5�㡢ǧ�ˡ����ơ�����þ�3������Ŀǰ�����ĺ�ȥ����",}),]),
	90 : ([
		94 : ({
			"��    ��ħ����ħ��1�㡢��ħ��2�㡢��ħ��3�㡢���ꡢ��ī������ħ��4������Ŀǰ�����ĺ�ȥ����",}),]),
	95 : ([
		99 : ({
			"��    ���궴�����涴�����ƶ�������ȡ����С�����þ�4������Ŀǰ�����ĺ�ȥ����",}),]),			
	100: ([
		104: ({
			"��    ������1��������2��������3����ƽ�ء���������Ŀǰ�����ĺ�ȥ����",}),]),
	105: ([
		109: ({
			"��    ������1�㡢������2�㡢������3�㡢ƽ�����ϵ�����Ŀǰ�����ĺ�ȥ����",}),]),
	110: ([
		120: ({
			"��    ������1�㡢������2�㡢������3�㡢���ء��������Ŀǰ�����ĺ�ȥ����",}),]),
]);
//	MAPPING �ṹ��	1��->��ʼ�ȼ���2��->�����ȼ���3��->��Ʒ�ȼ���
//			4��->������Ϣ,������Щ�������������ʽ�Ĵ��� �����
//				1 ��Ǯ cash <��ֵ>
//				2 ��Ʒ <��Ʒλ��> <��Ʒ��ɫ> <��Ʒ����>
private static mapping lv_rock_item = ([
	0  : ([
		9  : ([
			0: ({
				"cash 10000",
				"/item/60/0010 2",
				"/item/65/0010 2",
				"/item/88/0010 2",
				"/item/87/1010 2",}),
			1: ({
				"cash 5000",
				"/item/product/64001",
				"/item/product/64002",
				"/item/product/62001",
				"/item/product/62002",
				"/item/product/66001",
				"/item/product/66002",
				"/item/product/63001",
				"/item/product/63002",
				"/item/product/65001",
				"/item/product/65002",}),
			2: ({
				"cash 1000",
				"/item/91/9100 0 10",
				"/item/91/9101 0 10",
				"/item/91/9110 0 10",
				"/item/91/9111 0 10",
				"/item/std/5210 0 10",
				"/item/31/3150 0 10",
				"/item/32/3282 0 10",
				"/item/final/33/1700 0 10",
				"/item/final/33/1701 0 10",
				"/item/final/33/1702 0 10",
				"/item/final/33/1703 0 10",
				"/item/final/33/1750 0 10",
				"/item/std/0401 0 30",
				"/item/49/4900 0 10",
				"/item/std/0407 0 10",
				"/item/std/0409 0 10",
				"/item/44/4403 0 10",}),]),]),
	10 : ([
		29 : ([
			0: ({
				"cash 30000",
				"/item/72/1020 2",
				"/item/74/1020 2",
				"/item/72/1030 2",
				"/item/74/1030 2",
				"/item/76/1020 2",
				"/item/76/1030 2",
				"/item/75/1020 2",
				"/item/75/1030 2",
				"/item/70/1020 2",
				"/item/70/1030 2",
				"/item/71/1020 2",
				"/item/71/1030 2",
				"/item/77/1020 2",
				"/item/77/1030 2",
				"/item/78/1020 2",
				"/item/78/1030 2",
				"/item/79/1020 2",
				"/item/79/1030 2",
				"/item/std/8000",}),
			1: ({
				"cash 20000",
				"/item/95/0211 1",
				"/item/95/0221 1",
				"/item/95/0231 1",
				"/item/95/0251 1",
				"/item/95/0261 1",
				"/item/95/0414 1",
				"/item/95/0423 1",
				"/item/95/0511 1",
				"/item/95/0109 1",
				"/item/95/0401 1",
				"/item/95/0404 1",
				"/item/95/0405 1",
				"/item/95/0111 1",
				"/item/95/0121 1",
				"/item/95/0131 1",
				"/item/95/0141 1",
				"/item/95/0151 1",
				"/item/95/0161 1",
				"/item/95/0202 1",
				"/item/60/1025 1",
				"/item/61/1025 1",
				"/item/60/2025 1",
				"/item/61/2025 1",
				"/item/60/3025 1",
				"/item/61/3025 1",
				"/item/60/4025 1",
				"/item/61/4025 1",
				"/item/60/6025 1",
				"/item/61/6025 1",
				"/item/60/5025 1",
				"/item/61/5025 1",
				"/item/60/7025 1",
				"/item/61/7025 1",}),
			2: ({
				"cash 10000",
				"/item/91/9102 0 20",
				"/item/91/9112 0 20",
				"/item/final/33/1772 0 20",
				"/item/final/33/1754 0 20",
				"/item/final/33/1756 0 20",
				"/item/final/33/1764 0 20",
				"/item/product/64025 0",
				"/item/product/64026 0",
				"/item/product/64027 0",
				"/item/product/64025 0",
				"/item/product/64029 0",
				"/item/product/64030 0",
				"/item/product/64031 0",
				"/item/product/64032 0",
				"/item/product/64033 0",
				"/item/49/4900 0 30",
				"/item/std/0409 0 30",
				"/item/std/0410 0 30",
				"/item/std/0401 0 90",
				"/item/44/4406 0 30",}),]),]),
	30 : ([
		59 : ([
			0: ({
				"cash 100000",
				"/item/93/9301 1",
				"/item/93/9302 1",
				"/item/93/9304 1",
				"/item/93/9309 1",
				"/item/93/9306 1",
				"/item/93/9305 1",
				"/item/93/9303 1",
				"/item/93/9307 1",
				"/item/93/9308 1",
				"/item/93/9310 1",
				"/item/std/8001 1",
				"/item/std/8002 1",
				"/item/std/8003 1",
				"/item/std/8004 1",}),
			1: ({
				"cash 50000",
				"/item/44/4488 1",
				"/item/44/4405 1 10",
				"/item/86/1050 1",
				"/item/86/2050 1",
				"/item/86/3050 1",
				"/item/86/4050 1",
				"/item/86/6050 1",
				"/item/86/5050 1",
				"/item/86/7050 1",}),
			2: ({
				"cash 20000",
				"/item/95/0317 1",
				"/item/95/0222 1",
				"/item/95/0349 1",
				"/item/95/0364 1",
				"/item/95/0271 1",
				"/item/95/0418 1",
				"/item/95/0425 1",
				"/item/95/0501 1",
				"/item/95/0111 1",
				"/item/95/0121 1",
				"/item/95/0131 1",
				"/item/95/0141 1",
				"/item/95/0151 1",
				"/item/95/0161 1",
				"/item/95/0202 1",
				"/item/95/0402 1",
				"/item/95/0403 1",
				"/item/std/8000 0 20",
				"/item/91/9112 0 20",
				"/item/91/9120 0 20",
				"/item/std/5216 0 20",
				"/item/31/3152 0 20",
				"/item/31/3151 0 20",
				"/item/32/3281 0 20",
				"/item/33/3320 0 20",
				"/item/std/0409 0 30",
				"/item/std/0413 0 30",
				"/item/std/0591 0 30",
				"/item/98/9871 0 30",}),]),]),
	60 : ([
		89 : ([
			0: ({
				"cash 150000",
				"/item/std/9511 2",
				"/item/std/9521 2",
				"/item/std/9541 2",
				"/item/std/9561 2",
				"/item/std/9571 2",
				"/item/std/9581 2",
				"/item/96/0211 2",
				"/item/96/0221 2",
				"/item/96/0231 2",
				"/item/96/0251 2",
				"/item/96/0241 2",
				"/item/96/0261 2",
				"/item/96/0414 2",
				"/item/96/0424 2",
				"/item/96/0511 2",
				"/item/96/0404 2",
				"/item/96/0405 2",}),
			1: ({
				"cash 80000",
				"/item/95/0610",
				"/item/95/0640",
				"/item/95/0660",
				"/item/95/0670",
				"/item/95/0630",
				"/item/95/0650",
				"/item/95/0620",
				"/item/95/0680",
				"/item/std/8000",
				"/item/product/62311.c 1",
				"/item/product/62311.c 1",
				"/item/product/62313.c 1",
				"/item/product/62314.c 1",
				"/item/product/62315.c 1",
				"/item/product/62316.c 1",
				"/item/product/62317.c 1",
				"/item/product/62318.c 1",
				"/item/product/62319.c 1",
				"/item/product/62320.c 1",
				"/item/product/62321.c 1",
				"/item/product/62322.c 1",
				"/item/product/62323.c 1",
				"/item/product/62324.c 1",
				"/item/product/62325.c 1",
				"/item/product/62326.c 1",
				"/item/product/62327.c 1",
				"/item/product/62328.c 1",
				"/item/product/62329.c 1",}),
			2: ({
				"cash 50000",
				"/item/stuff/0055",
				"/item/stuff/0056",
				"/item/stuff/0079",
				"/item/stuff/0057",
				"/item/stuff/0080",
				"/item/stuff/0062",
				"/item/stuff/0063",
				"/item/stuff/0064",
				"/item/stuff/0078",
				"/item/stuff/0079",
				"/item/stuff/0080",
				"/item/stuff/0081",
				"/item/stuff/0082",
				"/item/stuff/0083",
				"/item/stuff/0084",
				"/item/stuff/0085",
				"/item/stuff/0086",
				"/item/stuff/0087",
				"/item/44/4488",
				"/item/final/16/1600",
				"/item/final/16/1607",
				"/item/final/16/1612",
				"/item/final/16/1605",
				"/item/final/16/1626",
				"/item/final/16/1610",
				"/item/final/16/1614",
				"/item/final/16/1609",
				"/item/98/0245",
				"/item/final/16/1603",
				"/item/final/16/1604",
				"/item/final/16/1608",}),]),]),
	90 : ([
		119: ([
			0: ({
				"cash 300000",
				"/item/44/4489",
				"/item/std/9502",
				"/item/std/9512",
				"/item/std/9522",
				"/item/std/9542",
				"/item/std/9562",
				"/item/std/9572",}),
			1: ({
				"cash 150000",
				"/item/72/1090 2",
				"/item/72/1100 2",
				"/item/74/1090 2",
				"/item/74/1100 2",
				"/item/76/1090 2",
				"/item/76/1100 2",
				"/item/75/1090 2",
				"/item/75/1100 2",
				"/item/70/1090 2",
				"/item/70/1100 2",
				"/item/71/1090 2",
				"/item/71/1100 2",
				"/item/77/1090 2",
				"/item/76/1130 2",
				"/item/78/1090 2",
				"/item/78/1100 2",
				"/item/79/1090 2",
				"/item/79/1100 2",
				"/item/91/9125",
				"/item/91/9150",
				"/item/91/9160",
				"/item/91/9161",
				"/item/91/9162",
				"/item/91/9163",
				"/item/91/9164",
				"/item/91/9165",
				"/item/std/0088",
				"/item/93/9301",
				"/item/93/9302",
				"/item/93/9304",
				"/item/93/9309",
				"/item/93/9306",
				"/item/93/9305",
				"/item/93/9303",
				"/item/93/9307",
				"/item/93/9308",
				"/item/93/9310",}),
			2: ({
				"cash 100000",
				"/item/std/8000",
				"/item/38/3801",
				"/item/38/3802",
				"/item/38/3803",
				"/item/38/3804",
				"/item/38/3805",
				"/item/38/3806",
				"/item/38/3807",
				"/item/38/3808",
				"/item/38/3809",
				"/item/97/9715",
				"/item/97/9713",
				"/item/97/9717",
				"/item/97/9716",
				"/item/97/9714",
				"/item/97/9710",
				"/item/97/9711",
				"/item/97/9712",
				"/item/97/9720",
				"/item/97/9721",
				"/item/97/9722",
				"/item/97/9723",
				"/item/97/9724",
				"/item/97/9725",
				"/item/97/9726",
				"/item/97/9727",
				"/item/97/9728",
				"/item/97/9729",
				"/item/97/9731",
				"/item/97/9732",
				"/item/97/9733",
				"/item/97/9733",
				"/item/stuff/0055",
				"/item/stuff/0056",
				"/item/stuff/0079",
				"/item/stuff/0057",
				"/item/stuff/0080",
				"/item/stuff/0062",
				"/item/stuff/0063",
				"/item/stuff/0064",
				"/item/stuff/0078",
				"/item/stuff/0079",
				"/item/stuff/0080",
				"/item/stuff/0081",
				"/item/stuff/0082",
				"/item/stuff/0083",
				"/item/stuff/0084",
				"/item/stuff/0085",
				"/item/stuff/0086",
				"/item/stuff/0087",}),]),]),
	120: ([
		150: ([
			0: ({
				"cash 500000",
				"/item/72/1120 2",
				"/item/76/1120 2",
				"/item/74/1120 2",
				"/item/75/1120 2",
				"/item/70/1120 2",
				"/item/71/1120 2",
				"/item/77/1120 2",
				"/item/78/1120 2",
				"/item/79/1120 2",
				"/item/61/7120 2",
				"/item/60/7120 2",
				"/item/61/5120 2",
				"/item/60/5120 2",
				"/item/61/6120 2",
				"/item/60/6120 2",
				"/item/61/4120 2",
				"/item/60/4120 2",
				"/item/61/3120 2",
				"/item/60/3120 2",
				"/item/61/2120 2",
				"/item/60/2120 2",
				"/item/61/1120 2",
				"/item/60/1120 2",}),
			1: ({
				"cash 300000",
				"/item/61/7120 1",
				"/item/60/7120 1",
				"/item/61/5120 1",
				"/item/60/5120 1",
				"/item/61/6120 1",
				"/item/60/6120 1",
				"/item/61/4120 1",
				"/item/60/4120 1",
				"/item/61/3120 1",
				"/item/60/3120 1",
				"/item/61/2120 1",
				"/item/60/2120 1",
				"/item/61/1120 1",
				"/item/60/1120 1",
				"/item/86/7120 1",
				"/item/86/5120 1",
				"/item/86/6120 1",
				"/item/86/4120 1",
				"/item/86/3120 1",
				"/item/86/2120 1",
				"/item/86/1120 1",
				"/item/87/7120 1",
				"/item/87/5120 1",
				"/item/87/6120 1",
				"/item/87/4120 1",
				"/item/87/3120 1",
				"/item/87/2120 1",
				"/item/87/1120 1",
				"/item/66/7120 1",
				"/item/65/7120 1",
				"/item/66/5120 1",
				"/item/65/5120 1",
				"/item/66/6120 1",
				"/item/65/6120 1",
				"/item/66/4120 1",
				"/item/65/4120 1",
				"/item/66/3120 1",
				"/item/65/3120 1",
				"/item/66/2120 1",
				"/item/65/2120 1",
				"/item/66/1120 1",
				"/item/65/1120 1",}),
			2: ({
				"cash 150000",
				"/item/95/0610",
				"/item/95/0640",
				"/item/95/0660",
				"/item/95/0670",
				"/item/95/0630",
				"/item/95/0650",
				"/item/95/0620",
				"/item/95/0680",
				"/item/91/9125",
				"/item/91/9150",
				"/item/91/9160",
				"/item/91/9161",
				"/item/91/9162",
				"/item/91/9163",
				"/item/91/9164",
				"/item/91/9165",
				"/item/std/0088",
				"/item/std/8000",
				"/item/38/3801",
				"/item/38/3802",
				"/item/38/3803",
				"/item/38/3804",
				"/item/38/3805",
				"/item/38/3806",
				"/item/38/3807",
				"/item/38/3808",
				"/item/38/3809",
				"/item/97/9715",
				"/item/97/9713",
				"/item/97/9717",
				"/item/97/9716",
				"/item/97/9714",
				"/item/97/9710",
				"/item/97/9711",
				"/item/97/9712",
				"/item/97/9720",
				"/item/97/9721",
				"/item/97/9722",
				"/item/97/9723",
				"/item/97/9724",
				"/item/97/9725",
				"/item/97/9726",
				"/item/97/9727",
				"/item/97/9728",
				"/item/97/9729",
				"/item/97/9731",
				"/item/97/9732",
				"/item/97/9733",
				"/item/97/9733",}),]),]),
]);
//	MAPPING �ṹ���շѵ��ߵĽ����б�
private static string *lv_sell_item = ({
	//	0-9
	"","","","","","","","","","",
	//	10-19
	"/item/bind/54/0951",
	"/item/bind/54/0952",
	"/item/bind/54/0953",
	"/item/bind/54/1100",
	"/item/bind/54/4143",
	"/item/bind/54/1050",
	"/item/bind/54/1102",
	"/item/bind/54/1051",
	"/item/bind/54/1052",
	"/item/bind/54/4145",
	//	20-29
	"/item/bind/08/0003",
	"/item/bind/08/0004",
	"/item/bind/08/0003",
	"/item/bind/08/0004",
	"/item/bind/08/0003",
	"/item/bind/08/0004",
	"/item/bind/08/0003",
	"/item/bind/08/0004",
	"/item/bind/08/0003",
	"/item/bind/08/0004",
	//	30-39
	"/item/bind/08/0001",
	"/item/bind/sell/0041",
	"/item/bind/08/0001",
	"/item/bind/sell/0041",
	"/item/bind/08/0001",
	"/item/bind/sell/0041",
	"/item/bind/08/0001",
	"/item/bind/sell/0041",
	"/item/bind/08/0001",
	"/item/bind/sell/0041",
	//	40-49
	"/item/bind/sell/0044",
	"/item/bind/01/0006",
	"/item/bind/sell/0044",
	"/item/bind/01/0006",
	"/item/bind/sell/0044",
	"/item/bind/01/0006",
	"/item/bind/sell/0044",
	"/item/bind/01/0006",
	"/item/bind/sell/0044",
	"/item/bind/01/0006",
	//	50-59
	"/item/bind/std/6002",
	"/item/bind/sell/0045",
	"/item/bind/sell/0050",
	"/item/bind/sell/0031",
	"/item/bind/sell/0012",
	"/item/bind/sell/0045",
	"/item/bind/sell/0040",
	"/item/bind/sell/0032",
	"/item/bind/sell/0032",
	"/item/bind/sell/0032",
	//	60-69
	"/item/bind/08/0002",
	"/item/bind/sell/0006",
	"/item/bind/08/0003 0 2",
	"/item/bind/08/0002",
	"/item/bind/sell/0006",
	"/item/bind/08/0003  0 2",
	"/item/bind/08/0002",
	"/item/bind/sell/0006",
	"/item/bind/08/0003 0 2",
	"/item/bind/08/0002",
	//	70-79
	"/item/bind/sell/0006",
	"/item/bind/08/0003 0 2",
	"/item/bind/sell/0007",
	"/item/bind/sell/0201",
	"/item/bind/sell/0009",
	"/item/bind/sell/0201",
	"/item/bind/sell/0007",
	"/item/bind/91/9166",
	"/item/bind/sell/0200",
	"/item/bind/sell/0009",
	//	80-89
	"/item/bind/sell/0200",
	"/item/bind/08/0002",
	"/item/bind/08/0004 0 2",
	"/item/bind/08/0002",
	"/item/bind/08/0004 0 2",
	"/item/bind/08/0002",
	"/item/bind/08/0004 0 2",
	"/item/bind/08/0002",
	"/item/bind/08/0004 0 2",
	"/item/bind/08/0002",
	//	90-99
	"/item/bind/sell/0002",
	"/item/bind/sell/0060",
	"/item/bind/sell/0002",
	"/item/bind/sell/0060",
	"/item/bind/sell/0002",
	"/item/bind/sell/0060",
	"/item/bind/sell/0002",
	"/item/bind/sell/0060",
	"/item/bind/sell/0002",
	"/item/bind/sell/0060",
	//	100-109
	"/item/bind/sell/0030",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0030",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0030",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0030",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0030",
	"/item/bind/sell/0041 0 2",
	//	110-119
	"/item/bind/01/0006 0 2",
	"/item/bind/sell/0045 0 2",
	"/item/bind/01/0006 0 2",
	"/item/bind/sell/0045 0 2",
	"/item/bind/01/0006 0 2",
	"/item/bind/sell/0045 0 2",
	"/item/bind/sell/0032 0 2",
	"/item/bind/08/0002",
	"/item/bind/sell/0008",
	"/item/bind/sell/0032 0 2",
	//	120-129
	"/item/bind/08/0002",
	"/item/bind/sell/0008",
	"/item/bind/sell/0032 0 2",
	"/item/bind/08/0002",
	"/item/bind/sell/0008",
	"/item/bind/sell/0010",
	"/item/bind/08/0002",
	"/item/bind/sell/0008",
	"/item/bind/sell/0010",
	"/item/bind/08/0002",
	//	130-139
	"/item/bind/sell/0041",
	"/item/bind/sell/0010",
	"/item/bind/08/0002",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0010",
	"/item/bind/sell/0030 0 2",
	"/item/bind/sell/0041 0 2",
	"/item/bind/08/0002 0 2",
	"/item/bind/sell/0060 0 2",
	"/item/bind/sell/0002 0 2",
	//	140-149
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0002 0 2",
	"/item/bind/sell/0060 0 2",
	"/item/bind/sell/0002 0 2",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0002 0 2",
	"/item/bind/sell/0060 0 2",
	"/item/bind/sell/0002 0 2",
	"/item/bind/sell/0041 0 2",
	"/item/bind/sell/0060 0 2",
	//	150
	"/item/bind/sell/0002 0 2",
});
/*---------------------------------------���------------------------------------------*/

/*-----------------------------------���к����ӿ�--------------------------------------*/
int if_allow_prize(object player);					//	�鿴��ǰ����Ƿ����ҡ��
void player_can_get_prize(object player,int if_can);			//	���õ�ǰ����Ƿ����ҡ��
void player_can_be_gala(object player,int if_can);			//	���õ�ǰ����ڵõ���ʾ��ͬʱ���ֹ�ϲ��Ϣ
void search_in_user(object player);					//	��ѯ��ǰ�����Ӧ����ʾ�ı�����Ϣ
void search_in_level(object player,int level);				//	��ʾ��ǰ���ĳһ�ȼ�����Ϣ
object *get_rock_item(object player);					//	��ȡ�û����ڵȼ�����Ӧ��ҡ����Ʒ�б�
string get_sell_item(object player);					//	��ȡ�շѵ��ߵĽ���
object *deal_with_item_info(string item_info);				//	����һ����Ʒ��Ϣ����������һ��ʵ����Ʒ
object want_an_zgdict(object npc,object player);			//	�������ս������ĺ���
/*---------------------------------------���------------------------------------------*/

/*------------------------------------���ʼ����---------------------------------------*/
/*---------------------------------------���------------------------------------------*/

/*------------------------------------��˽�к���---------------------------------------*/
//	����һ����Χ���ظ��������������-- ����ٶ�����������һ�����������Ҽ��Ϊ1
private int *make_only_number(int from,int to,int len) {
	int *original_dict=({});
	int *result_dict=({});
	int tmp,i,size;
	if(from > to) {
		tmp = to;
		to  = from;
		from= tmp;
	}
	if(len <= 0) {
		len = from+to;
	}
	for(i=0,size=(to-from);i<size;i++) {
		original_dict += ({from+i});
	}
	for(i=0;i<len;i++) {
		tmp = random(size-i);
		result_dict   += ({original_dict[tmp]});
		original_dict -= ({original_dict[tmp]});
	}
	return result_dict;
}
//	ͨ���ȼ�ȷ��������Ϣ�ĺ���
private string get_info_from_level(int user_level) {
	int lv_from,lv_to,i,size;
	mixed *lv_from_keys,*lv_to_keys;
	string user_get_info = "";
	user_level = range_value(user_level,0,151);
	lv_from_keys = keys(lv_user_info);
	if(!lv_from_keys) {
		return user_get_info;
	}
	foreach(lv_from in lv_from_keys) {
		if(user_level >= lv_from) {
			lv_to_keys = keys(lv_user_info[lv_from]);
			if(lv_to_keys) {
				foreach(lv_to in lv_to_keys) {
					if(user_level <= lv_to) {
						for(i=0,size=sizeof(lv_user_info[lv_from][lv_to]);i<size;i++) {
							user_get_info += lv_user_info[lv_from][lv_to][i]+"\n\n";
						}						
					}
				}
			}
		}
	}
	return user_get_info;
}
//	���Ϳ�������ʾ��Ϣ��Э����û�
private void send_info_to_user(object player,int level,string user_get_info) {
	_DEBUG(user_get_info);
	_DEBUG(sprintf("��ϲ��־-ҡ����־-�ȼ� %d-%d-%d",player->get(PLAYER_BE_GALA),player->get_save(PLAYER_GET_PRIZE),level));
	send_user(player,"%c%c%c%c%c%s",0xa6,1,player->get_save(PLAYER_GET_PRIZE),player->get(PLAYER_BE_GALA),level,user_get_info);
	player_can_be_gala(player,0);
}
//	���ֲ�ƥ������¸������Ĭ����Ʒ
private object get_default_item() {
	object item;
	item = new("/item/std/0001");
	item->set_value(1);
	return item;
}
/*---------------------------------------���------------------------------------------*/

/*------------------------------------�๫�к���---------------------------------------*/
//	�鿴��ǰ����Ƿ����ҡ��
int if_allow_prize(object player) {
	return player->get_save(PLAYER_GET_PRIZE);
}
//	���õ�ǰ����Ƿ����ҡ��
void player_can_get_prize(object player,int if_can) {
	if(if_can) {
		player->set_save(PLAYER_GET_PRIZE,1);
	} else if(player->get_save(PLAYER_GET_PRIZE"2")) {
		player->set_save(PLAYER_GET_PRIZE,1);
		player->delete_save(PLAYER_GET_PRIZE"2");
	} else {
		player->set_save(PLAYER_GET_PRIZE,0);
	}
}
//	���õ�ǰ����ڵõ���ʾ��ͬʱ���ֹ�ϲ��Ϣ
void player_can_be_gala(object player,int if_can) {	
	player->set(PLAYER_BE_GALA,if_can?1:0);	
	if(if_can) {
		player_can_get_prize(player,1);
		if(objectp(present("ս������", player, 1, MAX_CARRY*4))) {
			send_user(player,"%c%c%d%d%s",0xa6,6,1017,9008,"zgdict open");
			if(player->get_2("zgdict.status") == 1) {
				player->set_save(PLAYER_GET_PRIZE"2",1);
			}
		}
	}
}
//	��ѯ��ǰ�����Ӧ����ʾ�ı�����Ϣ
void search_in_user(object player) {
	send_info_to_user(player,player->get_level(),get_info_from_level(player->get_level()));
}
//	��ʾ��ǰ���ĳһ�ȼ�����Ϣ
void search_in_level(object player,int level) {
	send_info_to_user(player,level,get_info_from_level(level));
}
//	��ȡ�û����ڵȼ�����Ӧ��ҡ����Ʒ�б�
object *get_rock_item(object player) {
	int user_level,lv_from,lv_to,i,j,size,size1,size2,size3,*only_random;
	mixed *lv_from_keys,*lv_to_keys,*item_lv_keys,user_item_arr;
	string item_info;
	object *items,*allitem=({});
	user_level = player->get_level();
	lv_from_keys = keys(lv_rock_item);
	if(!lv_from_keys) {
		return allitem;
	}
	foreach(lv_from in lv_from_keys) {
		if(user_level >= lv_from) {
			lv_to_keys = keys(lv_rock_item[lv_from]);
			if(lv_to_keys) {
				user_item_arr = lv_rock_item[lv_from][lv_to_keys[0]];
				item_lv_keys = keys(user_item_arr);
				if(member_array(0,item_lv_keys) ==-1 || member_array(1,item_lv_keys) ==-1 || member_array(2,item_lv_keys) ==-1) {
					return allitem;
				}
				size1 = sizeof(user_item_arr[0]);
				if(size1 < 1) {
					return allitem;
				}
				size2 = sizeof(user_item_arr[1]);
				if(size2 < 2) {
					return allitem;
				}
				size3 = sizeof(user_item_arr[2]);
				if(size3 < 5) {
					return allitem;
				}
				only_random = make_only_number(0,size1,1);
				//	ȡһ��0����Ʒ����
				item_info = user_item_arr[0][only_random[0]];
				items = deal_with_item_info(item_info);
				allitem += ({items[0]});
				for(j=1,size=sizeof(items);j<size;j++) {
					destruct(items[j]);
				}
				only_random = make_only_number(0,size2,2);
				for(i=0;i<2;i++) {
					//	ȡһ��1����Ʒ����
					item_info = user_item_arr[1][only_random[i]];
					items = deal_with_item_info(item_info);
					allitem += ({items[0]});
					for(j=1,size=sizeof(items);j<size;j++) {
						destruct(items[j]);
					}
				}
				only_random = make_only_number(0,size3,5);
				for(i=0;i<5;i++) {
					//	ȡһ��2����Ʒ����
					item_info = user_item_arr[2][only_random[i]];
					items = deal_with_item_info(item_info);
					allitem += ({items[0]});
					for(j=1,size=sizeof(items);j<size;j++) {
						destruct(items[j]);
					}
				}
			}
			return allitem;
		}
	}
	return allitem;
}
//	��ȡ�շѵ��ߵĽ���
string get_sell_item(object player) {
	int user_level;
	string item_info;
	user_level= player->get_level();
	item_info = lv_sell_item[range_value(user_level,0,150)];
	return item_info;
}
//	����һ����Ʒ��Ϣ����������һ��ʵ����Ʒ ������Ʒ�ĸ�ʽ:<��Ʒλ��/cash> <��ɫ/��Ǯ����> <��Ʒ����>
object *deal_with_item_info(string item_info) {
	int size_desc,color,num,i;
	string *item_seg_desc;
	object item,*allitem=({});
	if(!item_info || item_info=="") {
		_DEBUG(sprintf("û���ҵ� %s",item_info));
		return ({get_default_item()});
	}
	item_seg_desc = explode(item_info," ");
	size_desc = sizeof(item_seg_desc);
	if(size_desc == 2 && item_seg_desc[0]=="cash" && to_int(item_seg_desc[1])>0) {		
		item = new("/item/std/0001");		
		item->set_value(to_int(item_seg_desc[1]));
		return ({item});
	} else {
		item = new(item_seg_desc[0]);
		if(!objectp(item)) {
			_DEBUG(sprintf("û���ҵ� %s",item_seg_desc[0]));
			destruct(item);
			return ({get_default_item()});
		}
		if(size_desc >=2) {
			color = to_int(item_seg_desc[1]);
			if(color>0) {
				switch(color) {
					case 1:
						ITEM_EQUIP_D->init_equip_prop_1(item);
						break;
					case 2:
						ITEM_EQUIP_D->init_equip_prop_3(item);
						break;
				}
			}
			if(size_desc >=3) {
				num = to_int(item_seg_desc[2]);
				if(num>0) {
					if(item->is_combined()) {
						if(num>item->get_max_combined()) {
							item->set_amount(item->get_max_combined());
							allitem += ({item});
							num = num - item->get_max_combined();
							while(num>0) {
								item = new(item_seg_desc[0]);
								if(color>0) {
									switch(color) {
										case 1:
											ITEM_EQUIP_D->init_equip_prop_1(item);
											break;
										case 2:
											ITEM_EQUIP_D->init_equip_prop_3(item);
											break;
									}									
								}
								if(num>item->get_max_combined()) {
									item->set_amount(item->get_max_combined());
									allitem += ({item});
									num = num - item->get_max_combined();
								} else {
									item->set_amount(num);
									allitem += ({item});
									num=0;
								}								
							}
						} else {
							item->set_amount(num);
							allitem += ({item});
						}
					} else {
						allitem += ({item});
						for(i=0;i<num-1;i++) {
							item = new(item_seg_desc[0]);
							if(color>0) {
								switch(color) {
									case 1:
										ITEM_EQUIP_D->init_equip_prop_1(item);
										break;
									case 2:
										ITEM_EQUIP_D->init_equip_prop_3(item);
										break;
								}
							}
							allitem += ({item});
						}
					}
				} else {
					allitem += ({item});
				}
			} else {
				allitem += ({item});
			}
			return allitem;
		} else {			
			return ({item});
		}		
	}
	return ({get_default_item()});
}
//	�������ս������ĺ���
object want_an_zgdict(object npc,object player) {
	if ( USER_INVENTORY_D->count_empty_carry(player) < 1 ) {
		send_user(player, "%c%s", '!', "�ռ䲻����������һ��������ȡ");
		return 0;
	}
	if( objectp(present("ս������", player, 1, MAX_CARRY*4)) ) {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf(
			"%s: \n    ��������һ����ս�����䡷�������ٴ���ȡ��\n"
			ESC"�뿪",npc->get_name()
		));		
		return 0;
	}
	return new(ZGDICT_ITEM);
}
/*---------------------------------------���------------------------------------------*/