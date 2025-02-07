/****************************************/
/*************PVP场景传送员**************/
/****************************************/

#include <npc.h>
#include <ansi.h>
#include <effect.h>


inherit OFFICER;

mapping Map=([
		"东武":({501, 256 ,159}),"小沛":({502, 257, 156}),"彭城":({503, 65, 108}),"雪峰山秘道":({530, 241, 83}),
		"武陵秘道":({529, 243, 86}),"衡山秘道":({528, 185, 47}),"阴山":({513, 154, 216}),"阴山草原":({512, 177, 213}),
		"祈连山":({511, 169, 222}),"祈连草原":({510, 167, 222}),"邙山秘道":({527, 37, 125}),"琅琊秘道":({526, 238, 81}),
		"中原秘道":({525, 107, 81}),"嵩山秘道":({524, 37, 125}),"孟津":({517, 254, 160}),"弘农":({516, 294, 124}),
		"易京":({515, 254, 157}),"壶关":({ 514, 231, 178}),"乌江":({505, 259, 154}),"广陵":({ 504, 262, 155}),
		"千乘":({509, 201, 205}),"高唐":({508, 260, 154}),"乐陵":({507, 55, 107}),"即墨":({506, 63, 103}),
		"汉中":({522, 260,91}),"子午谷":({520,171, 35}),"阳平关":({523, 220, 178}),"西城":({521, 278, 140}),
		"上党":({532,256,160}),"平阳":({ 531, 165, 215}),"武关":({519, 231, 179}),"潼关":({ 518, 84, 83}),
		]);

//获取NPC造型
int get_char_picid()
{
	return 5109;
}

void do_welcome(string arg);

//构造初始化
void create()
{
	set_name("PVP场景传送员");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

//对话处理
void do_look(object who)
{
	string result;
	object me=this_object();
	
	result=sprintf(me->get_name()+":\n    对挑战有兴趣的朋友，我可以提供部分特殊的练级场地给你，喜欢挑战的朋友选择一个适合你的练级场地尽情发挥你的本领吧~！\n");
	result+=sprintf(ESC "传送到45~50级PVP地图\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC "传送到55~60级PVP地图\ntalk %x# welcome.2\n",getoid(me));
	result+=sprintf(ESC "传送到65~70级PVP地图\ntalk %x# welcome.3\n",getoid(me));
	result+=sprintf(ESC "传送到75~80级PVP地图\ntalk %x# welcome.4\n",getoid(me));
	result+=sprintf(ESC "传送到85~90级PVP地图\ntalk %x# welcome.5\n",getoid(me));
	result+=sprintf(ESC "传送到95~100级PVP地图\ntalk %x# welcome.6\n",getoid(me));
	result+=sprintf(ESC "传送到105~110级PVP地图\ntalk %x# welcome.7\n",getoid(me));
	result+=sprintf(ESC "离开");
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me,string arg)
{
	int flag,z,x,y,level,*zxy;
	string *key,result,mapname;
	object who;
	
	who=this_player();
	who->set_time("talk",0);
	level=who->get_level();
	if(!arg) return; 
	key=explode(arg," ");
	flag=to_int(key[0]);
	switch(flag)
	{
		case 1:
			//if(!(level>44)&&!(level<51)) return;
			result=sprintf(me->get_name()+":\n    你要去45级以上50级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "东武\ntalk %x# welcome.10 东武\n",getoid(me));
			result+=sprintf(ESC "小沛\ntalk %x# welcome.10 小沛\n",getoid(me));
			result+=sprintf(ESC "彭城\ntalk %x# welcome.10 彭城\n",getoid(me));
			result+=sprintf(ESC "雪峰山秘道\ntalk %x# welcome.10 雪峰山秘道\n",getoid(me));
			result+=sprintf(ESC "武陵秘道\ntalk %x# welcome.10 武陵秘道\n",getoid(me));
			result+=sprintf(ESC "衡山秘道\ntalk %x# welcome.10 衡山秘道\n",getoid(me));
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 2:
			//if(!(level>54)&&!(level<61)) return;
			result=sprintf(me->get_name()+":\n    你要去55级以上60级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "阴山\ntalk %x# welcome.10 阴山\n",getoid(me));
			result+=sprintf(ESC "阴山草原\ntalk %x# welcome.10 阴山草原\n",getoid(me));
			result+=sprintf(ESC "祈连山\ntalk %x# welcome.10 祈连山\n",getoid(me));
			result+=sprintf(ESC "祈连草原\ntalk %x# welcome.10 祈连草原\n",getoid(me));
			
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 3:
			//if(!(level>64)&&!(level<71)) return;
			result=sprintf(me->get_name()+":\n    你要去65级以上70级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "邙山秘道\ntalk %x# welcome.10 邙山秘道\n",getoid(me));
			result+=sprintf(ESC "琅琊秘道\ntalk %x# welcome.10 琅琊秘道\n",getoid(me));
			result+=sprintf(ESC "中原秘道\ntalk %x# welcome.10 中原秘道\n",getoid(me));
			result+=sprintf(ESC "嵩山秘道\ntalk %x# welcome.10 嵩山秘道\n",getoid(me));
			result+=sprintf(ESC "孟津\ntalk %x# welcome.10 孟津\n",getoid(me));
			result+=sprintf(ESC "弘农\ntalk %x# welcome.10 弘农\n",getoid(me));
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 4:
			//if(!(level>74)&&!(level<81)) return;
			result=sprintf(me->get_name()+":\n    你要去75级以上80级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "易京\ntalk %x# welcome.10 易京\n",getoid(me));
			result+=sprintf(ESC "壶关\ntalk %x# welcome.10 壶关\n",getoid(me));
			result+=sprintf(ESC "乌江\ntalk %x# welcome.10 乌江\n",getoid(me));
			result+=sprintf(ESC "广陵\ntalk %x# welcome.10 广陵\n",getoid(me));
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 5:
			//if(!(level>84)&&!(level<91)) return;
			result=sprintf(me->get_name()+":\n    你要去85级以上90级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "千乘\ntalk %x# welcome.10 千乘\n",getoid(me));
			result+=sprintf(ESC "高唐\ntalk %x# welcome.10 高唐\n",getoid(me));
			result+=sprintf(ESC "乐陵\ntalk %x# welcome.10 乐陵\n",getoid(me));
			result+=sprintf(ESC "即墨\ntalk %x# welcome.10 即墨\n",getoid(me));
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 6:
			//if(!(level>94)&&!(level<101)) return;
			result=sprintf(me->get_name()+":\n    你要去95级以上100级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "汉中\ntalk %x# welcome.10 汉中\n",getoid(me));
			result+=sprintf(ESC "子午谷 \ntalk %x# welcome.10 子午谷\n",getoid(me));
			result+=sprintf(ESC "阳平关\ntalk %x# welcome.10 阳平关\n",getoid(me));
			result+=sprintf(ESC "西城\ntalk %x# welcome.10 西城\n",getoid(me));
			
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 7:
			//if(!(level>104)&&!(level<111)) return;
			result=sprintf(me->get_name()+":\n    你要去105级以上110级以下的练级地图吗？来，选择吧！按Alt+M可以查看这些地图具体的怪物种类哦。\n");
			result+=sprintf(ESC "上党\ntalk %x# welcome.10 上党\n",getoid(me));
			result+=sprintf(ESC "平阳\ntalk %x# welcome.10 平阳\n",getoid(me));
			result+=sprintf(ESC "武关\ntalk %x# welcome.10 武关\n",getoid(me));
			result+=sprintf(ESC "潼关\ntalk %x# welcome.10 潼关\n",getoid(me));
			
			result+=sprintf(ESC "离开");
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),result);
			break;
		case 10:
			if(!sscanf(arg,"%d %s",flag,mapname)==2) return;
			zxy=Map[mapname];
			if(!zxy) return;
			z=zxy[0];x=zxy[1];y=zxy[2];
			__FILE__->send_ok(who,z,x,y);
			break;
			
	}
}

//可以传送
void send_ok(object who,int z,int x,int y)
{
	int p;
	object me=this_object();
	p=x*1000+y;
	send_user(who, "%c%c%w%s", 0x5a, 0, 3, "传送中……");
        who->set_2("travel.z",z);
	who->set_2("travel.p",p);
	set_effect(who, EFFECT_TRAVEL, 3);
//	me->add_to_scene(z,x-2,y-2);
}