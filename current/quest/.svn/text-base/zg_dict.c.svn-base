/*----------------------------------------------------------------------------------*\
	战国宝典的控制文件，包含一些通用功能的控制处理
	由 cjxx 于 2007-09-14 创建
\*----------------------------------------------------------------------------------*/
#include <ansi.h>

/*------------------------------------预定义变量---------------------------------------*/
#define PLAYER_GET_PRIZE	"can_get_prize"
#define PLAYER_BE_GALA		"can_be_gala"
#define ZGDICT_ITEM		"item/01/7600"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}
/*---------------------------------------完毕------------------------------------------*/

/*------------------------------------类私有变量---------------------------------------*/
//	MAPPING 结构：1层->起始等级，2层->结束等级，3层->对应信息
private static mapping lv_user_info = ([
	0  : ([
		9  : ({
			"◇    在新手村、幽谷、清溪有一些使命人物和使命物品，只要打败使命人物或拾取使命物品去找卫队长，就会获得意外的奖励哦！",
			"◇    看到那些百姓头上的问号了吗？那表示村民有事情需要你帮助，赶快过去找他们谈谈吧！",
			"◇    在新手村、幽谷、清溪和巴丘正是适合你练级的地方。",
			"◇    野外的怪物是不是很可爱！去杂货店买几个乾坤绳，然后使用“宠物捕捉”技能就有一定几率将怪物变为宠物哦！",}),
		29 : ({
			"◇    找到师父了吗？如果还没有找到就赶快去孟子那里去申请吧！找个师父帮你熟悉战国环境。",}),
		50 : ({
			"◇    卫队长那里正缺少人手维护治安，你去帮他协助治安，能得到不错的收益哦！",}),
		150: ({
			"◇    神仙爷爷处每周给玩家提供了4个小时的双倍时间和3个小时的额外双倍时间，当然，如果你加入了VIP，还有更多的双倍经验时间领取，赶快去神仙爷爷处领取双倍经验吧！",}),	]),
	10 : ([
		10 : ({
			"◇    还没有加入门派吗？赶快去找门派招募吧！他们能把你直接传到门派驻地，加入门派后就能学到很厉害的技能哦！",}),
		14 : ({
			"◇    如果你现在有时间可以去楚国转转，那里的百姓正等待着你的帮助呢！",
			"◇    楚方城1、楚方城2、楚方城3、上庸关、华山、桃花源、朝阳峰正是适合你练级的地方。",}),
		20 : ({
			"◇    在周国市集右侧有一些生活技能导师，你可以去那里向他们请教生活技能，另外还有一个大众化的副生活技能需要在市集左侧的御厨那里才可以学到。",}),
		30 : ({
			"◇    听说周国衙门的王捕头正缺少人手，你有空的时候不如去帮帮他吧！",}),]),
	11 : ([
		150: ({
			"◇    师门里经常缺少人手办事，去找师父问问吧！前20个任务可是有丰厚奖励的哦！也许你还能遇上隐藏任务呢。",}),]),
	15 : ([
		19 : ({
			"◇    首阳山、翠华山和函谷关正是适合你冲级的地方，要练级就赶快去这些地方吧！",}),
		24 : ({
			"◇    如果你有时间就去一趟韩国吧！那里的百姓正翘首等待着你去帮助他们呢。",	}),]),
	20 : ([
		24 : ({
			"◇    以你现在的等级，建议你去以下几个地方练级：无定河1、无定河2、无定河畔、襄陵、马陵道、白马庄以及马踏湖。",}),
		29 : ({
			"◇    魏国有很多人也在期盼着你的到来，你找个时间去看看吧！",}),]),
	25 : ([
		30 : ({
			"◇    虎牢关、萁关、巨鹿、涿鹿、易水、桂陵、牧野、太行山、晋阳、平原、雁门关以及长平都是适合现在等级的练级地图。",	}),]),
	30 : ([
		34 : ({
			"◇    楚国有很多百姓正等待着你的帮助，找个时间去看看吧！",}),
		150: ({
			"◇    如果你缺钱，可以去周国镖局找尉迟老镖头，帮他运镖，他会给你丰厚报酬的。",
			"◇    练级一直使用药品是不是觉得有些不划算？没关系，每天的12点到24点到除周国以外的各国城外园圃处，找到那里的农夫，进行农产品生产，做成食物很划算的。",}),]),
	31 : ([
		40 : ({
			"◇    沼泽边缘、沼泽地带、大别山脚、大别山、巫山、鄱阳湖、赤壁、太湖、泰山山脚、泰山这些都是现阶段练级的好地方。",}),]),
	35 : ([
		39 : ({
			"◇    齐国百姓正对你翘首以盼呢！你还是找个时间过去看看的好。",}),
		150: ({
			"◇    知道左秋明吗？他正在征召勇士前往封妖镜歼灭妖魔，只要你给他一件15级以上珍稀装备，他就可以打开封妖通道。只要将里面的妖魔歼灭85％以上就有一只BOSS出来，会掉落珍稀装备哦！",}),]),
	40 : ([
		45 : ({
			"◇    你现在有时间不妨去趟秦国，找秦国的百姓聊聊，相信你一定会有收获的。"}),
		50 : ({
			"◇    去过燕国吗？去找燕国百姓聊聊吧，他们好像有很多事情要和你说。"}),
		60 : ({
			"◇    现在你已经有足够的实力来创建帮派了，如果你想创建帮派，那就赶快去选一个国家吧（除周国外），找到该国的帮派总管，就可以领取建邦任务了，但是，我还要补充一点，就是在制作“王之号角”的时候可是要花费100万金币的哦！",
			"◇    你可以通过秦国军营讨逆将军进入成矫军营，只要打败BOSS就有一定几率获得紫色套装部件，但是要小心哦！里面的怪物很厉害哦！"}),]),
	41 : ([
		50 : ({
			"◇    以你现在的实力，已经有资格做新人的师父了，快去新手村找一个30级以下的新人吧，组队去找孟子。把徒弟带出师后有丰厚的奖励哦！",
			"◇    东海渔村、东海岸、海滨1、海滨2、东海岛、郑国渠1、郑国渠2、郑国渠3都是你现在可以去的地方。",
			"◇    据说每个两天，在东海都有一个叫犬太郎的家伙游弋。据东海渔民说，这个犬太郎非常厉害，你要十分小心啊！"}),]),
	50 : ([
		54 : ({
			"◇    长白山、天柱峰、长白天池、白云峰、武陵秘道、衡山秘道、雷锋山秘道都是练级的好地方。",}),
		55 : ({
			"◇    赵国一直在抵抗着匈奴的进攻，去看看赵国百姓吧！相信你一定有不少收获的。",}),
		70 : ({
			"◇    你可以组队去翠华山（139,117）找到“逃亡的苦役”进入骊山陵墓，里面有不少好东西，但是要小心哦！里面的怪物非常厉害，一般人我不告诉他。",}),]),
	55 : ([
		59 : ({
			"◇    燕长城1、燕长城2、燕长城3和阴山草原、阴山、巨兽岛正是现在合适的练级点。"}),]),
	60 : ([
		64 : ({
			"◇    赵长城1、赵长城2、赵长城3、祁连山草原、祁连山、地狱魔窟1层正是目前练级的好去处。",}),]),
	65 : ([
		69 : ({
			"◇    秦长城1、秦长城2、秦长城3、中原秘道、嵩山秘道、琅琊秘道、邙山秘道、天外幻境1层正是目前练级的好去处。",}),]),
	70 : ([
		74 : ({
			"◇    弯道1、弯道2、弯道3、弘农、孟津、地狱魔窟2层正是目前练级的好去处。",}),]),
	75 : ([
		79 : ({
			"◇    灵谷洞1层、灵谷洞2层、灵谷洞3层、壶关、易京、天外幻境2层正是目前练级的好去处。",}),]),			
	80 : ([
		84 : ({
			"◇    万人坑1层、万人坑2层、万人坑3层、万人坑4层、万人坑5层、乌江、广陵、地狱魔窟3层正是目前练级的好去处。",}),]),
	85 : ([
		89 : ({
			"◇    将军墓1层、将军墓2层、将军墓3层、将军墓4层、将军墓5层、千乘、高唐、天外幻境3层正是目前练级的好去处。",}),]),
	90 : ([
		94 : ({
			"◇    困魔阵、困魔阵1层、困魔阵2层、困魔阵3层、乐陵、即墨、地狱魔窟4层正是目前练级的好去处。",}),]),
	95 : ([
		99 : ({
			"◇    虚陵洞、玄真洞、紫云洞、子午谷、汉中、天外幻境4层正是目前练级的好去处。",}),]),			
	100: ([
		104: ({
			"◇    九曲桥1、九曲桥2、九曲桥3、阳平关、西城正是目前练级的好去处。",}),]),
	105: ([
		109: ({
			"◇    天门阵1层、天门阵2层、天门阵3层、平阳、上党正是目前练级的好去处。",}),]),
	110: ([
		120: ({
			"◇    诛仙阵1层、诛仙阵2层、诛仙阵3层、潼关、武关正是目前练级的好去处。",}),]),
]);
//	MAPPING 结构：	1层->起始等级，2层->结束等级，3层->奖品等级，
//			4层->道具信息,这里有些道具做了特殊格式的处理 如果是
//				1 金钱 cash <价值>
//				2 物品 <物品位置> <物品颜色> <物品个数>
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
//	MAPPING 结构：收费道具的奖励列表
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
/*---------------------------------------完毕------------------------------------------*/

/*-----------------------------------公有函数接口--------------------------------------*/
int if_allow_prize(object player);					//	查看当前玩家是否可以摇奖
void player_can_get_prize(object player,int if_can);			//	设置当前玩家是否可以摇奖
void player_can_be_gala(object player,int if_can);			//	设置当前玩家在得到提示的同时出现恭喜信息
void search_in_user(object player);					//	查询当前玩家所应该提示的宝典信息
void search_in_level(object player,int level);				//	提示当前玩家某一等级的信息
object *get_rock_item(object player);					//	获取用户所在等级所对应的摇奖奖品列表
string get_sell_item(object player);					//	获取收费道具的奖励
object *deal_with_item_info(string item_info);				//	处理一个物品信息的描述返回一个实际物品
object want_an_zgdict(object npc,object player);			//	给予玩家战国宝典的函数
/*---------------------------------------完毕------------------------------------------*/

/*------------------------------------类初始函数---------------------------------------*/
/*---------------------------------------完毕------------------------------------------*/

/*------------------------------------类私有函数---------------------------------------*/
//	返回一个范围不重复乱序的整数数组-- 这里假定乱序数字是一个连续整体且间隔为1
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
//	通过等级确定返回信息的函数
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
//	发送开启并显示信息的协议给用户
private void send_info_to_user(object player,int level,string user_get_info) {
	_DEBUG(user_get_info);
	_DEBUG(sprintf("恭喜标志-摇奖标志-等级 %d-%d-%d",player->get(PLAYER_BE_GALA),player->get_save(PLAYER_GET_PRIZE),level));
	send_user(player,"%c%c%c%c%c%s",0xa6,1,player->get_save(PLAYER_GET_PRIZE),player->get(PLAYER_BE_GALA),level,user_get_info);
	player_can_be_gala(player,0);
}
//	出现不匹配情况下给予玩家默认物品
private object get_default_item() {
	object item;
	item = new("/item/std/0001");
	item->set_value(1);
	return item;
}
/*---------------------------------------完毕------------------------------------------*/

/*------------------------------------类公有函数---------------------------------------*/
//	查看当前玩家是否可以摇奖
int if_allow_prize(object player) {
	return player->get_save(PLAYER_GET_PRIZE);
}
//	设置当前玩家是否可以摇奖
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
//	设置当前玩家在得到提示的同时出现恭喜信息
void player_can_be_gala(object player,int if_can) {	
	player->set(PLAYER_BE_GALA,if_can?1:0);	
	if(if_can) {
		player_can_get_prize(player,1);
		if(objectp(present("战国宝典", player, 1, MAX_CARRY*4))) {
			send_user(player,"%c%c%d%d%s",0xa6,6,1017,9008,"zgdict open");
			if(player->get_2("zgdict.status") == 1) {
				player->set_save(PLAYER_GET_PRIZE"2",1);
			}
		}
	}
}
//	查询当前玩家所应该提示的宝典信息
void search_in_user(object player) {
	send_info_to_user(player,player->get_level(),get_info_from_level(player->get_level()));
}
//	提示当前玩家某一等级的信息
void search_in_level(object player,int level) {
	send_info_to_user(player,level,get_info_from_level(level));
}
//	获取用户所在等级所对应的摇奖奖品列表
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
				//	取一个0级物品描述
				item_info = user_item_arr[0][only_random[0]];
				items = deal_with_item_info(item_info);
				allitem += ({items[0]});
				for(j=1,size=sizeof(items);j<size;j++) {
					destruct(items[j]);
				}
				only_random = make_only_number(0,size2,2);
				for(i=0;i<2;i++) {
					//	取一个1级物品描述
					item_info = user_item_arr[1][only_random[i]];
					items = deal_with_item_info(item_info);
					allitem += ({items[0]});
					for(j=1,size=sizeof(items);j<size;j++) {
						destruct(items[j]);
					}
				}
				only_random = make_only_number(0,size3,5);
				for(i=0;i<5;i++) {
					//	取一个2级物品描述
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
//	获取收费道具的奖励
string get_sell_item(object player) {
	int user_level;
	string item_info;
	user_level= player->get_level();
	item_info = lv_sell_item[range_value(user_level,0,150)];
	return item_info;
}
//	处理一个物品信息的描述返回一个实际物品 处理物品的格式:<物品位置/cash> <颜色/金钱数量> <物品数量>
object *deal_with_item_info(string item_info) {
	int size_desc,color,num,i;
	string *item_seg_desc;
	object item,*allitem=({});
	if(!item_info || item_info=="") {
		_DEBUG(sprintf("没有找到 %s",item_info));
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
			_DEBUG(sprintf("没有找到 %s",item_seg_desc[0]));
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
//	给予玩家战国宝典的函数
object want_an_zgdict(object npc,object player) {
	if ( USER_INVENTORY_D->count_empty_carry(player) < 1 ) {
		send_user(player, "%c%s", '!', "空间不够，请整理一下再来领取");
		return 0;
	}
	if( objectp(present("战国宝典", player, 1, MAX_CARRY*4)) ) {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf(
			"%s: \n    你身上有一本《战国宝典》，不用再次领取。\n"
			ESC"离开",npc->get_name()
		));		
		return 0;
	}
	return new(ZGDICT_ITEM);
}
/*---------------------------------------完毕------------------------------------------*/