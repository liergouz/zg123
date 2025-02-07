
#include <ansi.h>
#include <equip.h>
#include <city.h>
#include <map.h>
#include <task.h>

//	任务列表  1~6 天枢院任务	10 储备任务	20 经商任务

string * task1 = ({ "破损的头盔", "破损的盔甲", "铜棒", "铜套", "铜环", "铜丝", "铜片", "麻布", "小铜片", "铜管", "麻线", "烤地瓜", "地瓜解暑汤", "橙玉石", "橙宝石", "蛇之冠", "甲虫翅膀", "黄蜂刺", "鱼骨", "猴子尾巴", "螳螂臂", "烟白玉石", "烟白宝石", "螳螂之翼", "狗尾巴", "火种", "珠串", "奶嘴", "灰玉石", "飞行扇", "腰牌", "发束", "锡棒", "锡套", "锡环", "锡丝", "锡片", "丝绸", "丝线", "油炸地瓜片", "小米粥", "小青铜片", "青铜管", "灰宝石", "狗皮药膏", "破旧的头盔", "破旧的盔甲", "朱红玉石", "骸骨碎片", "蝎尾", "蜘蛛丝", "剧毒刺", "朱红宝石", "银杏子", "黑玉断续膏", "玉米棒", "青铜管", "牛筋", "鼻环", "水贼头巾", "蛙蹼", "闪光的石头", "蜥蜴尾巴", "绿色小石头", "白玉石", "白宝石", "银棒", "银套", "银环", "银丝", "银片", "铁棒", "铁套", "铁环", "铁丝", "板蓝根粉", "金银花露", "御米壳", "田七粉", "野菊花粉", "黄芪粉", "铁片", "绫", "绫线", "舍利子", "仙山灵芝", "小铁片", "铁管", "大钳子", "破布衣", "玉白玉石", "玉白宝石", "蛛网", "红色小石头", "碧绿玉石", "碧绿宝石", "死者遗物", "帽缨", "破旧的头盔", "破旧的盔甲", "刀柄", "剑鞘", "箭筒", "墨玉玉石", "墨玉宝石", "金棒", "金套", "金环", "金丝", "金片", "皮带", "纱", "纱线", "紫箐丹", "气脉丹", "鸡蛋汤", "水煮大南瓜", "小银片", "银管", "枪头", "熟地", "干红枣", "干陈皮", "洋金花丝", "黄连粉", "穿心莲粉", "鱼叉", "铜罐", "黄色小石头", "腐骨", "铜骸", "青玉石", "精铁棒", "精铁套", "精铁环", "精铁丝", "精铁片", "玄铁棒", "玄铁套", "玄铁环", "逍遥散", "清心丹", "水煮大南瓜", "南瓜饼", "玄铁丝", "玄铁片", "青宝石", "七色串珠", "铁骸", "骨盾", "骷髅头", "桃木钉", "僵尸冠", "绿玉石", "绿宝石", "碎玉", "陶俑之首", "陶俑之臂", "锁魔链", "甲胄", "小太极", "玉盖", "龟壳", "长寿石", "玉束髻", "火凤之翼", "拂尘", "天青玉石", "天青宝石", "红玉石", "红宝石", "黑玉石", "甘草片", "白芪粉", "当归片", "川贝粉", "虫草", "藏红花", });
int * count1 = ({ 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, });
string * unit1 = ({ "颗", "颗", "颗", "个", "个", "个", "朵", "条", "片", "扎", "块", "块", "块", "个", "个", "颗", "条", "把", "个", "个", "个", "个", "颗", "个", "个", "个", "个", "个", "个", "个", "根", "根", "扎", "个", "个", "根", "朵", "块", "块", "块", "块", "个", "块", "件", "件", "块", "包", "个", "个", "个", "个", "块", "块", "条", "条", "条", "块", "个", "个", "根", "个", "块", "块", "个", "块", "张", "张", "个", "块", "条", "朵", "颗", "朵", "只", "个", "把", "把", "个", "个", "个", "个", "个", "块", "根", "根", "条", "块", "个", "块", "个", "朵", "块", "个", "朵", "颗", "根", "块", "块", "顶", "条", "个", "个", "个", "个", "根", "块", "个", "粒", "颗", "个", "个", "个", "个", "个", "块", "条", "个", "块", "个", "个", "个", "个", });
string * task2 = ({ "程林开", "周童", "李三婶", "许氏", "刘德", "孟求", "朱狂", "魏管家", "李屠", "李浪", "王凯", "孔小飞", "崔玉", "齐管家", "老王婶", "马大汉", "赵木", "林为", "游子", "钱老八", "韩管家", "刘头", "钱老九", "孙陆", "王满", "楚管家", "王铁匠", "脚夫", "李防", "白易", "赵管家", "彭尖豪", "马显", "夏侯党", "秦管家", "曹清", "丁鹤年", "程风", "燕管家", });
//string * food = ({ "水稻", "麦子", "玉米", "小米", "高粱", "冬瓜", "南瓜", "黄瓜", "萝卜", "白菜", "青菜", "地瓜", "山药", });
string * food = ({ "烤地瓜", "地瓜解暑汤", "油炸地瓜片", "小米粥", "玉米棒", "玉米羹", });
// 内测期间生活技能封闭时暂时用的物品
string * task3 = ({ "破损的头盔", "破损的盔甲", "蛇之冠", "甲虫翅膀", "黄蜂刺", "鱼骨", "猴子尾巴", "螳螂臂", "螳螂之翼", "狗尾巴", "火种", "珠串", "奶嘴", "飞行扇", "腰牌", "发束", "狗皮药膏", "破旧的头盔", "破旧的盔甲", "骸骨碎片", "蝎尾", "蜘蛛丝", "剧毒刺", "牛筋", "鼻环", "水贼头巾", "蛙蹼", "闪光的石头", "蜥蜴尾巴", "绿色小石头", "大钳子", "破布衣", "蛛网", "红色小石头", "死者遗物", "帽缨", "破旧的头盔", "破旧的盔甲", "刀柄", "剑鞘", "箭筒", "枪头", "鱼叉", "铜罐", "黄色小石头", "腐骨", "铜骸", "七色串珠", "铁骸", "骨盾", "骷髅头", "桃木钉", "僵尸冠", "碎玉", "陶俑之首", "陶俑之臂", "锁魔链", "甲胄", "小太极", "玉盖", "龟壳", "长寿石", "玉束髻", "火凤之翼", "拂尘",});

// 函数：生成二进制码
void SAVE_BINARY() { }

void init_org_place(int z, string name, object orgnpc);

// 国家的帮派总管
void do_look_1(object me, object who )
{
	string result;
	int position;
	"/quest/help"->send_help_tips(me, 26);
	result = sprintf("%s：\n    我是负责%s帮派事务的总管，您有什么事需要我帮忙的吗？\n", who->get_name(), who->get_city_name());
	position = me->get_org_position();
	if (position>0 && me->get_city_name()==who->get_city_name()&&me->get_org_name()!="")
		result += sprintf(ESC"回帮派院落\ntalk %x# back\n", getoid(who));
	else
	if (position==0 && me->get_city_name()==who->get_city_name() && me->get_org_name()!="" )
		result += sprintf(ESC"放弃申请\ntalk %x# info.10\n", getoid(who));
	else
	{
		if (me->get_org_name()=="")
		{
			result += sprintf(ESC"申请入帮\ntalk %x# info.20\n", getoid(who));
			result += sprintf(ESC"申请建帮\ntalk %x# info.30\n", getoid(who));
		}
	}
	result += sprintf(ESC"参观其他帮派\ntalk %x# travel\n", getoid(who));
	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 回帮派
void do_back(object me, object who, string arg )
{
	string result, name;
	int position;
	object map, orgnpc, npc;
	int i, size, z, p, x, y, x0, y0;
	position = me->get_org_position();
	name = me->get_org_name();
	if (name=="") return;
	if (position>0 && me->get_city_name()==who->get_city_name())
	{
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
		if (!objectp(orgnpc)) return;
		map = orgnpc->get("map");
		if (map==0)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
				p = 886;
				init_virtual_map(z, p);    // 生成虚拟地图
				map = new( "/inh/std/org" );
				map->set_client_id(p);
				set_map_object( map, map->set_id(z) );
				orgnpc->set("map", map);
				orgnpc->set("z", z);
				map->set_name(name);
				init_org_place(z, name, orgnpc);
			}
			else
				return ;
		}
		else
		{
			z = orgnpc->get("z");
		}
		me->set_2("jiguan.z", get_z(me));
		me->set_2("jiguan.x", get_x(me));
		me->set_2("jiguan.y", get_y(me));
		if (random(2)) p = get_jumpin(z, 11);
		else p = get_jumpin(z, 12);
		if( p )
		{
			me->add_to_scene(z, p / 1000, p % 1000, 3);
		}
	}
}

// 国家总管的相关函数
void do_info(object me, object who, string arg )
{
	int position, flag, number, i, size;
	string result, name;
	object orgnpc, city, *char, item;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (flag>=10&&flag<20)
	{
		if (name=="") return;
		if (position>0)
		{
			result = sprintf("%s：\n    您已经身处帮派中。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
		if (flag==10)
		{
			result = sprintf("%s：\n    您真的放弃加入%s吗？\n", who->get_name(), name);
			result += sprintf(ESC"确定\ntalk %x# info.11\n", getoid(who));
			result += ESC"取消\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
		number = me->get_number();
		if (objectp(orgnpc))
		{
	                if( orgnpc->get_join_id(number) )
	                {
	                        orgnpc->delete_join_info(number);
				orgnpc->save();
	                }
		}
		me->set_org_name("");
		result = sprintf("%s：\n    我已经取消了您加入%s的申请，有什么需要帮忙的再来找我吧。\n", who->get_name(), name);
		result += ESC"离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	if (name!="") return;
	if (flag>=20&&flag<30)
	{
		switch (flag)
		{
		case 20:
			result = sprintf("%s：\n    您希望申请加入本国的帮派吗？如果要申请加入本国的帮派，您必须先加入本国国籍或者本身无国籍。如果您希望创建一个属于自己的帮会，除了必须成为本国臣民外，还必须得到一个名为“王之号角”的信物。\n", who->get_name());
			result += sprintf(ESC"确定\ntalk %x# info.21\n", getoid(who));
			result += sprintf(ESC"返回\ntalk %x# info.29\n", getoid(who));
			break;
		case 21:
			if (me->get_city_name()!=who->get_city_name()&& me->get_city_name()!="" && me->get_city_name()!=0 )
			{
				result = sprintf("%s：\n    您已有别国的国籍，我无法接受您的入帮申请。\n", who->get_name());
			}
			else
			{
				if( !( city = CITY_D->get_city_object(who) ) ) return ;
				char = city->get("manager");
				send_user(me, "%c%c%c%d", 0x95, 53, 1, getoid(who));
				size = sizeof(char);
				for (i=0;i<size;i++) if (objectp(char[i]))
				{
					result = sprintf("%-4s%-12s%s", who->get_city_name(), char[i]->get_org_name(), char[i]->get_master_name() );
					send_user(me, "%c%c%c%d%c%w%w%s", 0x95, 53, 2, char[i]->get_power(), char[i]->get_grade(), char[i]->sizeof_member_dbase(), char[i]->get_max_number(), result);
				}
				return ;
			}
			break;
		case 29:
			do_look_1(me, who);
			return;

		}
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (me->get_city_name()!=who->get_city_name())
	{
		result = sprintf("%s：\n    您还不是本国的公民，我无法接受您的建帮申请。\n", who->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	if (me->get_level()<40)
	{
		result = sprintf("%s：\n    您的等级还不满40级，无法承担责任啊。\n", who->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	switch(flag)
	{
	case 30:
		result = sprintf("%s：\n    年轻人还真是满怀大志啊～不过建立帮派可不是一件容易的事情，您必须先交给我一个名为“王之号角”的信物以证明自己的能力，这样我才能通过您创建帮派的申请。\n", who->get_name());
		result += sprintf(ESC"交出“王之号角”\ntalk %x# info.31\n", getoid(who));
		result += ESC"离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	case 31:
		if( objectp( item = present("王之号角", me, 1, MAX_CARRY*4) ) )
		{
		        result = sprintf("%s：\n    没错！果然是真正的“王之号角”！看来在寻找这个号角您也费了不少的功夫。好！老夫就满足您的愿望，助您创建帮派吧！\n", who->get_name());
			result += sprintf(ESC"创建帮派\ntalk %x# info.32\n", getoid(who));
			result += ESC"我还是再考虑考虑……\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		result = sprintf("%s：\n    “王之号角”还没找来吗？周国的神仙爷爷应该知道关于有关这个号角的一些线索，您大可以去询问一下他关于“王之号角”的事情。神仙爷爷就在周国天坛的中心，我相信他会给予您帮助的。\n", who->get_name());
		result += ESC"离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	case 32:
		if( objectp( item = present("王之号角", me, 1, MAX_CARRY*4) ) )
		{
		        name = me->get("org");
		        if( !stringp(name) || name == "" )
		                send_user( me, "%c%c%d%s", '?', 16, 11, "您想在此创立帮派，请输入帮派名称(１～５个中文)：\n" ESC "org @ %s\n" );
		        else    "cmd/user/org"->main(me, "@ " + name);
		        return ;
		}
		break;
	}
}

// 参观其他帮派
void do_travel(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc, city, *char;
	int i, size, z, p, x, y, x0, y0;
	if (arg==""||arg==0)
	{
		if( !( city = CITY_D->get_city_object(who) ) ) return ;
		char = city->get("manager");
		send_user(me, "%c%c%c%d", 0x95, 54, 1, getoid(who));
		size = sizeof(char);
		for (i=0;i<size;i++) if (objectp(char[i]))
		{
			result = sprintf("%-4s%-12s%s", who->get_city_name(), char[i]->get_org_name(), char[i]->get_master_name() );
			send_user(me, "%c%c%c%d%c%w%w%s", 0x95, 54, 2, char[i]->get_power(), char[i]->get_grade(), char[i]->sizeof_member_dbase(), char[i]->get_max_number(), result);
		}
		return;
	}
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	result = sprintf("%s：\n    您希望参观一下%s吗？很容易，您只要交付2000金，我便可以安排您进入。\n", who->get_name(), name);
	result += sprintf(ESC"确定\ntalk %x# travel2.%s\n", getoid(who), name);
	result += ESC"离开\nCLOSE\n";
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
	send_user(me, "%c%c", 0x95, 255);
}

// 进入其他帮派
void do_travel2(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc, npc;
	int i, size, z, p, x, y, x0, y0;
	if (arg=="") return;
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (me->get_cash()<2000)
	{
		result = sprintf("%s：\n    没钱！？开什么玩笑！等凑足2000金之后再来吧！\n", who->get_name());
		result += ESC"离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return ;
	}
	me->add_cash(-2000);
	"/sys/sys/count"->add_use("visit", 2000);
	me->log_money("参观", -2000);
	orgnpc->add_gold(1000);
	map = orgnpc->get("map");
	if (map==0)
	{
		if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
		{
			p = 886;
			init_virtual_map(z, p);    // 生成虚拟地图
			map = new( "/inh/std/org" );
			map->set_client_id(p);
			set_map_object( map, map->set_id(z) );
			orgnpc->set("map", map);
			orgnpc->set("z", z);
			map->set_name(name);
			init_org_place(z, name, orgnpc);
		}
		else
			return ;
	}
	else
	{
		z = orgnpc->get("z");
	}
	me->set_2("jiguan.z", get_z(me));
	me->set_2("jiguan.x", get_x(me));
	me->set_2("jiguan.y", get_y(me));
	if( p = get_jumpin(z, 10) )
	{
		me->add_to_scene(z, p / 1000, p % 1000, 3);
	}
}

// 申请加入帮派
void do_join(object me, object who, string arg )
{
	string name, result;
	object map, orgnpc;
	int i, size, z, p, x, y, x0, y0;
	if (me->get_city_name()!="" && me->get_city_name()!=who->get_city_name()) return;
	if (me->get_org_name()!="") return;
	name = arg;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if ("/sys/city/manager2"->do_join( me, orgnpc, "" )==1)
	{
//		me->set_org_name(name);
		result = sprintf("%s：\n    您的申请书我刚才已经委托部下转交给%s的%s大人了，您就静候福音吧。\n", who->get_name(), name, orgnpc->get_master_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		send_user(me, "%c%c", 0x95, 255);
	}
}

// 帮派里的总管
void do_look_2(object me, object who )
{
	string result, name;
	object orgnpc;
	int position, id;
	name = who->get_org_name();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	result = sprintf("%s：\n    我便是%s的总管，负责统筹管理%s帮的一切日常事务。您找我有何要事？\n", who->get_name(), name, name);
	position = me->get_org_position();
	if ((me->get_org_name()==name) && (position>0))
	{
		id = getoid(who);
		result += sprintf(ESC"查看帮派成员名单\ntalk %x# info\n", id);
		result += sprintf(ESC"帮派公告与大事记\ntalk %x# note\n", id);
		result += sprintf(ESC"帮派战争\ntalk %x# war\n", id);
		result += sprintf(ESC"帮派状况\ntalk %x# org\n", id);
		if (position==9 && orgnpc->get_demisstime()>time())
			result += sprintf(ESC"取消禅让\ntalk %x# quest.30\n", id);
		if (me->get_save_2("orgtask2.type")==0)
			result += sprintf(ESC"领取天枢院任务\ntalk %x# quest.10\n", id);
		else
			result += sprintf(ESC"完成天枢院任务\ntalk %x# quest.20\n", id);
	}
	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 帮派的武教头
void do_look_3(object me, object who )
{
	string result, name;
	int position, count, i;
	object orgnpc;
	result = sprintf("%s：\n    本人专门负责帮派的训练和战斗人员的招募。\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==who->get_org_name())
	{
		count = 0;
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i)) count ++;
		result += sprintf("目前本帮的训练度为%d，开启了%d项强化训练，需要做些什么？\n", orgnpc->get_train(), count );
		if (position>=8)
			result += sprintf(ESC"开启强化技\ntalk %x# info.10\n", getoid(who));
		if (count>0) result += sprintf(ESC"学习强化技\ntalk %x# info.20\n", getoid(who));
		if (position>=8)
		{
			result += sprintf(ESC"提升训练度\ntalk %x# info.50\n", getoid(who));
//???			result += sprintf(ESC"聘请帮派守护者\ntalk %x# info.40\n", getoid(who));
		}
	}
	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 武教头的相关函数
void do_info_3(object me, object who, string arg )
{
	int position, flag, number, i, size, level, time, cash,level1;
	string result, name, list, desc;
	object orgnpc, city, *char, item, file;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	switch(flag)
	{
	case 10:
		if (position<8) return;
		list = "";
		size = orgnpc->get_strongcount();
		if (size>0)
		{
			for (i=0;i<=8;i++) if (orgnpc->get_strong(i))
			{
				file = load_object(sprintf("/skill/04/%04d", 430+i));
				if (file)
				{
					if (list=="") list = file->get_name();
					else list = list + "、" + file->get_name();
				}
			}
			if (size>=orgnpc->get_grade()*2)
			{
				result = sprintf("%s：\n    目前帮派已经开启了%d项强化（%s），已经达到可开启上限。请升级帮派规模后再来查看。\n", who->get_name(), size, list);
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			result = sprintf("%s：\n    目前帮派中已经开启了%d项强化（%s），还没达到可开启上限，请选择需开启的强化。（每开启一项强化消耗帮派资金500万，储备200）\n", who->get_name(), size, list);
		}
		else
			result = sprintf("%s：\n    请选择需开启的强化。（每开启一项强化消耗帮派资金500万，储备200）\n", who->get_name());
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i)==0)
		{
			file = load_object(sprintf("/skill/04/%04d", 430+i));
			if (file)
			{
				result += sprintf(ESC"%s\ntalk %x# info.%d\n", file->get_name(), getoid(who), 11+i);
			}
		}
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 41:
	case 42:
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
		if (position<8) return;
		i = (flag-1)%10;
		if (orgnpc->get_strong(i)) return;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
		size = orgnpc->get_strongcount();
		if (size>=orgnpc->get_grade()*2)
		{
			result = sprintf("%s：\n    目前帮派已经开启了%d项强化，已经达到可开启上限。请升级帮派规模后再来查看。\n", who->get_name(), size);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_train()<(size+1)*10+5)
		{
			result = sprintf("%s：\n    目前帮派的训练度不足%d。请提升帮派训练度后再来强化技能。\n", who->get_name(), (size+1)*10+5);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_gold()<5000000)
		{
			result = sprintf("%s：\n    目前帮派的资金不足500万。请增加资金后再来强化技能。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_store()<200)
		{
			result = sprintf("%s：\n    目前帮派的储备不足200。请增加储备后再来强化技能。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (flag<30)
		{
			desc = file->get_desc();
			result = sprintf("%s：\n    %s%s你确定要开启该项强化技能吗？\n", who->get_name(), file->get_name(), desc[25..<2], );
			result += sprintf(ESC"确定\ntalk %x# info.%d\n", getoid(who), 41+i);
			result += sprintf(ESC"取消\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc->add_gold(-5000000);
		orgnpc->set_store(orgnpc->get_store()-200);
		orgnpc->set_strong(i);
		orgnpc->save();
		result = sprintf("%s：\n    您开启了%s，消耗帮派资金500万，储备200。\n", who->get_name(), file->get_name());
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		FAMILY_D->org_channel( name, 0, sprintf( HIR "本帮派已经开启了新的强化特殊技“%s”。",
			file->get_name() ) );
		break;
	case 20:
		result = sprintf("%s：\n    帮中成员可以在我这进行强化训练，训练的代价是每进行一次强化，需要金钱20000，帮派贡献度5，潜能50，强化技能的不同，花费的金钱也不同。另外，你的帮派总贡献也必须达到3000点才可修炼。请选择您希望强化的项目：\n", who->get_name());
		for (i=0;i<=8;i++) if (orgnpc->get_strong(i))
		{
			file = load_object(sprintf("/skill/04/%04d", 430+i));
			if (file)
			{
				result += sprintf(ESC"%s\ntalk %x# info.%d\n", file->get_name(), getoid(who), 21+i);
			}
		}
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
	case 27:
	case 28:
	case 29:
		i = (flag-1)%10;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
		cash = file->get_learn_money();
		if (cash==0) cash = 30000;
		result = sprintf("%s：\n    强化%s一次，只能提升该技能5点熟练度，且每次需要耗费金钱%d，帮派贡献度5点，50点潜能值，你确定要强化吗？\n", who->get_name(), file->get_name(), cash );
		result += sprintf(ESC"确定\ntalk %x# info.%d\n", getoid(who), 31+i);
		result += sprintf(ESC"取消\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 31:
	case 32:
	case 33:
	case 34:
	case 35:
	case 36:
	case 37:
	case 38:
	case 39:
		i = (flag-1)%10;
		if (orgnpc->get_strong(i)==0) return;
		file = load_object(sprintf("/skill/04/%04d", 430+i));
		if (!file) return;
//		if ( (i==6)&&me->get_skill(430+i)>=5)
//		{
//			result = sprintf("%s：\n    您的%s已达上限。\n", who->get_name(), file->get_name());
//			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
//			return;
//		}
		if ( i == 6 )
			level1 = 5;
		else if ( i == 0 || i == 1 || i == 2 || i == 3 || i == 7 || i == 8 )
			level1 = 20;
		else
			level1 = 10;
		if(me->get_skill(430+i)>=level1)
		{
			result = sprintf("%s：\n    您的%s已达上限。\n", who->get_name(), file->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
//		if(me->get_skill(430+i)>=me->get_level()/10-2)
//		{
//			result = sprintf("%s：\n    您只有升至%d级才能继续提升%s。\n", who->get_name(), (me->get_level()/10+1)*10, file->get_name());
//			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
//			return;
//		}
		cash = file->get_learn_money();
		if (cash==0) cash = 30000;
		if (me->get_cash()<cash)
		{
			result = sprintf("%s：\n    您的金钱不足%d，不能进行强化训练。\n", who->get_name(), cash);
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		number = me->get_number();
		if (orgnpc->get_member_all_contribute(number)<3000)
		{
			result = sprintf("%s：\n    您的帮派总贡献度不足3000，不能进行强化训练。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_member_contribute(number)<5)
		{
			result = sprintf("%s：\n    您的帮派贡献度不足以进行强化训练。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (me->get_potential()<50)
		{
			result = sprintf("%s：\n    您的潜能不足以进行强化训练。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		me->add_cash(-cash);
		"/sys/sys/count"->add_use("org-strong", cash);
		me->log_money("强化技能", -cash);
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)-50);
		me->set_potential(me->get_potential()-50);
		me->improve_skill(430+i, 50);
		level = me->get_skill(430+i);
		result = sprintf("%s：\n    您强化%s提升熟练度5，目前等级%d级，熟练度 %d / %d 。\n", who->get_name(), file->get_name(), level, me->get_skill_degree(430+i),(level+1)*(level+1)*5);
		result += sprintf(ESC"继续学习\ntalk %x# info.%d\n", getoid(who), 31+i);
		result += sprintf(ESC"取消\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 50:
	case 51:
		time = orgnpc->get_traintime();
		if (time>0)
		{
			if (time()>time)
			{
				orgnpc->set_traintime(0);
				orgnpc->set_train(orgnpc->get_train()+1);
			}
			else
			{
				result = sprintf("%s：\n    帮派训练度提升还剩余%d分钟。\n", who->get_name(), (time-time())/60 );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}
		if (orgnpc->get_train()>=20*orgnpc->get_grade())
		{
			result = sprintf("%s：\n    帮派训练度已达上限。\n", who->get_name() );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_gold()<2000000)
		{
			result = sprintf("%s：\n    帮派资金不足200万，无法提升训练度。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (orgnpc->get_store()<60)
		{
			result = sprintf("%s：\n    帮派储备不足60，无法提升训练度。\n", who->get_name());
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (flag==30)
		{
			result = sprintf("%s：\n    目前本帮派的训练度为%d，提升1点训练度需要消耗帮派资金200万以及储备60，且必须耗时十秒，你确定要提升帮派的训练度吗？\n", who->get_name(), orgnpc->get_train() );
			result += sprintf(ESC"确定\ntalk %x# info.51\n", getoid(who));
			result += sprintf(ESC"取消\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		orgnpc->add_gold(-2000000);
		orgnpc->set_store(orgnpc->get_store()-60);
		orgnpc->set_traintime(time()+1*10);
		orgnpc->save();
		FAMILY_D->org_channel( name, 0, sprintf( HIR "本帮派已经开始提升训练度，需时为十秒。",
			orgnpc->get_sciencetime() ) );
		break;
	}
}

// 帮派的帐房先生
void do_look_4(object me, object who )
{
	string result, name, *trader;
	int position, store;
	object orgnpc;
	result = sprintf("%s：\n    做为本帮派的仓管，务必尽心尽力，精打细算。\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==name)
	{
		store = orgnpc->get_store();
		result += sprintf("本帮目前拥有资金%d，储备%d。你来找我有什么事情吗？\n", orgnpc->get_gold(), store );
		if (store<orgnpc->get_grade()*500&&(me->get_save_2("orgtask.type")!=1)) result += sprintf(ESC"领取储备任务\ntalk %x# info.10\n", getoid(who));
		if (me->get_save_2("orgtask.type")==1) result += sprintf(ESC"完成储备任务\ntalk %x# info.20\n", getoid(who));
		trader = orgnpc->get_trader();
		if (arrayp(trader) && member_array(me->get_id(), trader)!=-1||me->get_number()==orgnpc->get_master())
		{
			if (me->get_save_2("orgtask3.type")==0)
				result += sprintf(ESC"领取经商任务\ntalk %x# info.30\n", getoid(who));
		}
		if (me->get_save_2("orgtask3.type")==1)
			result += sprintf(ESC"完成经商任务\ntalk %x# info.40\n", getoid(who));
		result += sprintf(ESC"捐款\ntalk %x# savings\n", getoid(who));
	}
	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 帐房先生的相关函数
void do_info_4(object me, object who, string arg )
{
	int position, flag, number, i, size, level, count, gold, p, exp, contrib, base, rand, order;
	string result, name, list;
	object orgnpc, city, *char, item, file;
	object *inv;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	switch(flag)
	{
	case 10:		// 储备任务
		if (me->get_save_2("orgtask.type")!=0)
		{
			result = sprintf("%s：\n    你的帮派任务还没有完成，不能领取新任务\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask.time")<0 ) me->set_save_2("orgtask.time", 0);
		if (time()-me->get_save_2("orgtask.time")<180)
		{
			result = sprintf("%s：\n    领取新任务需要间隔三分钟。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		level = orgnpc->get_grade();
//		if (MAIN_D->get_host_type()!=4 && MAIN_D->get_host_type()!=0)
		if (1)
		{
			switch(level)
			{
			case 1:
				size = 64;
				rand = 100 - 64;
				break;
			case 2:
				size = 100;
				rand = 130-100;
				break;
			case 3:
				size = 130;
				rand = 161 - 130;
				break;
			case 4:
				size = 161;
				rand =  sizeof(task1);
				break;
			default:
				size = sizeof(task1);
				rand= 1;
				break;
			}
			base = size;
			i = random(size);
			me->set_save_2("orgtask.double", 0);
			if (level<5)
			{
				if (random(100)<5)
				{
					i = base + random(rand);
					if (i>=sizeof(task1)) i = base;
					me->set_save_2("orgtask.double", 1);
				}
			}
			me->set_save_2("orgtask.status", 1);
			me->set_save_2("orgtask.name", task1[i]);
			me->set_save_2("orgtask.count", count1[i]);
			me->set_save_2("orgtask.unit", "个");
			me->set_save_2("orgtask.time", time());
		}
		else
		{
			switch(level)
			{
			case 1:
				size = 30;
				rand = 38 - 30;
				break;
			case 2:
				size = 38;
				rand = 46-38;
				break;
			case 3:
				size = 46;
				rand = 59 - 46;
				break;
			case 4:
				size = 59;
				rand =  sizeof(task3);
				break;
			default:
				size = sizeof(task3);
				rand= 1;
				break;
			}
			base = size;
			i = random(size);
			me->set_save_2("orgtask.double", 0);
			if (level<5)
			{
				if (random(100)<5)
				{
					i = base + random(rand);
					if (i>=sizeof(task3)) i = base;
					me->set_save_2("orgtask.double", 1);
				}
			}
			me->set_save_2("orgtask.status", 1);
			me->set_save_2("orgtask.name", task3[i]);
			me->set_save_2("orgtask.count", 10);
			me->set_save_2("orgtask.unit", "个");
			me->set_save_2("orgtask.time", time());
		}
		result = sprintf("%s：\n    近期帮派由于发展、研究、维护的关系，需要储备大量的材料以备不时之需。目前帮派还缺乏不少物资，你帮忙去找回来吧。\n", who->get_name() );
		result += sprintf(ESC"接受任务\ntalk %x# info.11\n", getoid(who));
		result += sprintf(ESC"离开\ntalk %x# info.12\n", getoid(who));
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
		if (me->get_save_2("orgtask.status")==1) me->set_save_2("orgtask.type", 1);
		if ( me->get("tasklist") != 0 )
		{
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"帮派任务" );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10, "储备任务" );
		}
		break;
	case 12:
		me->set_save_2("orgtask.status", 0);
		break;
	case 20:
	case 21:
		if (me->get_save_2("orgtask.type")!=1)
		{
			result = sprintf("%s：\n    你没有领取储备任务。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		name = 	me->get_save_2("orgtask.name");
		number = me->get_save_2("orgtask.count");
		list = me->get_save_2("orgtask.unit");
		inv = all_inventory(me, 1, MAX_CARRY*4);
		inv -= ({ 0});
		count = 0;
		for( i = 0, size = sizeof(inv); i < size; i ++ )
		{
			if ( (inv[i]->get_name()==name) && (inv[i]->is_legend_item()==0) )
			{
				if (inv[i]->get_max_combined()<=1) count ++;
				else count += inv[i]->get_amount();
			}
		}
		if (count<number)
		{
			if( !objectp( item = present("储备箱", me, 1, MAX_CARRY*4) ) )
			{
				result = sprintf("%s：\n    需要你收购的%d%s%s都齐备了吗？做事情要有始有终，决不能半途而废！如果你实在是找不到我要的材料，你可以去找功德老人帮帮忙。\n", who->get_name(), number, list, name);
				result += sprintf(ESC"离开\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}

		if (flag==20)
		{
			if (item)
			{
				result = sprintf("%s：\n    你希望消耗一个储备箱来完成这次的储备任务吗？\n", who->get_name() );
				result += sprintf(ESC"确定\ntalk %x# info.21\n", getoid(who));
				result += sprintf(ESC"取消\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				break;
			}
			result = sprintf("%s：\n    表现得相当不错！这么快就把东西收集全了！本帮要是多几个像你这样精明的人，以后定能雄霸各帮之首！我马上向帮主禀明你的功劳，让他重重的奖赏你。\n", who->get_name() );
			result += sprintf(ESC"完成任务\ntalk %x# info.21\n", getoid(who));
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
		if (item)
		{
			send_user( me, "%c%d", 0x2d, getoid(item) );
                        destruct(item);
		}
		else
		for( i = 0, size = sizeof(inv); i < size; i ++ )
		{
			if ( (inv[i]->get_name()==name) && (inv[i]->is_legend_item()==0) )
			{
				if (inv[i]->get_max_combined()<=1)
				{
					number --;
					send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
                                	destruct(inv[i]);
				}
				else
				{
					if (number > inv[i]->get_amount())
					{
						number -= inv[i]->get_amount();
						send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
                                		destruct(inv[i]);
					}
					else
					{
						inv[i]->add_amount( -number );
						number = 0;
					}
				}
				if (number<=0) break;
			}
		}
		me->add_exp(2000*me->get_online_rate()/100);
		number = me->get_number();
		order = me->get_save_2("orgtask.order");
		order++;
		order = order * me->get_online_rate()/100;
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+order);
		orgnpc->set_store(orgnpc->get_store()+1);
		result = sprintf("你完成了储备任务，经验上升%d，帮派贡献度上升%d。\n", 2000 * me->get_online_rate()/100, order* me->get_online_rate()/100);
		if (me->get_save_2("orgtask.double"))
		{
			me->add_cash(2000* me->get_online_rate()/100);
			me->log_money("帮派任务", 2000* me->get_online_rate()/100);
			"/sys/sys/count"->add_income("org", 2000 * me->get_online_rate()/100);
			orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+3* me->get_online_rate()/100);
			result += sprintf("额外得到%d点帮派贡献点和%d金的奖励。\n", 3* me->get_online_rate()/100, 2000* me->get_online_rate()/100);
		}
		if (order==10 && random100()<me->get_online_rate())
		{
			if ( me->get_level()>=40 && random100()==0)
			{
				item = new ("/item/01/0007");
			}
			else
				item = new( "sys/item/product"->get_random_mid_product() );
			if (item)
			{
	                        if( USER_INVENTORY_D->can_carry(me, item)  >=1 )
	                        {
	                                p =item->move(me, -1);
	                                item->add_to_user(p);
			                send_user( me, "%c%s", '!', "您意外获得"+item->get_name() );
	                        }
	                        else
	                        	destruct(item);
			}
			if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);

		}
		me->delete_save_2("orgtask");
		if (order>=10) order = 0;
		me->set_save_2("orgtask.order", order);
		send_user( me, "%c%s", ';', result );
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10,"" );
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
		break;
	case 30:
	case 31:
		char = orgnpc->get_trader();
		if ( (!arrayp(char) || member_array(me->get_id(), char)==-1) && me->get_number()!= orgnpc->get_master() )
		{
			result = sprintf("%s：\n    你不是商人，无法领取钱票。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
                if( present("钱票", me, 1, MAX_CARRY*4) )
                {
                        send_user(me, "%c%s", '!', "您已经领了钱票了。");
                        return;
                }
                if( sizeof_inventory(me, 1, MAX_CARRY) >= MAX_CARRY )
                {
                        send_user(me, "%c%s", '!', "您携带的东西太多了。");
                        return;
                }
                level = me->get_level();
                gold = 50000;
                if (orgnpc->get_gold()<gold)
                {
                        send_user(me, "%c%s", '!', "帮派资金不足，无法经商。");
                        return;
                }
                if (flag==30)
                {
			result = sprintf("%s：\n    帮中所有的大小事务都离不开金钱的开销。因此商人的存在是必不可少的。拿着，这是%d金的商票。运用一下你商人的头脑，替本帮赚%d金钱回来吧！\n", who->get_name(), gold, gold/2);
			result += sprintf(ESC"接受任务\ntalk %x# info.31\n", getoid(who));
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
                orgnpc->add_gold(-gold);
                item = new("/item/std/0002");
                item->set_orgin_money(gold);
                item->set_money(gold);
                if( p = item->move(me, -1) ) item->add_to_user(p);
                else destruct(item);
                me->set_save_2("orgtask3.type", 1);
                me->set_save_2("orgtask3.money", gold);
		if ( me->get("tasklist") != 0 )
		{
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"帮派任务" );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20, "商人任务" );
		}
                break;
	case 40:
	case 41:
		item = present("钱票", me, 1, MAX_CARRY*4);
		if (!objectp(item)||item->get_money()<item->get_orgin_money()*3/2)
		{
			result = sprintf("%s：\n    如何经商？这就要动动脑筋了。每个国家都有一个专门批发商品的的特产品商人，你大可以去找他，还要比较一下各国之间特产品的物价差异，低买高卖，这是最简单的生意经了。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
                if (flag==40)
                {
			result = sprintf("%s：\n    哈哈，我果然没看错人。你的确是个经商的天才～本帮有一个像你这样的精明商人必定会越来越强盛！\n", who->get_name() );
			result += sprintf(ESC"完成任务\ntalk %x# info.41\n", getoid(who));
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			break;
		}
		orgnpc->add_gold(item->get_money());
		FAMILY_D->org_channel( name, 0, sprintf( HIR "本帮商人%s为帮派赚取了%d金。",
                	me->get_name(), item->get_money()- item->get_orgin_money() ) );
		gold = me->get_level()*100;
		gold = gold * me->get_online_rate()/100;
		contrib = me->get_level()/4;
		contrib = contrib * me->get_online_rate()/100;
		exp = NPC_ENERGY_D->get_exp_bonus(me->get_level())*32;
		exp = exp * me->get_online_rate()/100;
		result = "你完成了帮派经商任务，";
		if (random(100)<10* me->get_online_rate()/100)
		{
			switch(random(3))
			{
			case 0: gold *= 2; result += HIR"获得意外的奖励，金钱加倍，"BLK;break;
			case 1: contrib *= 2; result += HIR"获得意外的奖励，帮贡加倍，"BLK;break;
			case 2: exp *= 2; result += HIR"获得意外的奖励，经验加倍，"BLK;break;
			}

		}
		me->add_exp(exp);
		me->add_cash(gold);
		me->log_money("经商任务", gold);
		"/sys/sys/count"->add_income("orgtrader", gold);
		number = me->get_number();
		orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+contrib);
		result += sprintf("经验上升%d，帮派贡献度上升%d，获得金钱%d。\n", exp, contrib, gold);
		send_user( me, "%c%s", ';', result );
		send_user( me, "%c%d", 0x2d, getoid(item) );
                destruct(item);
                me->delete_save_2("orgtask3");
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20,"" );
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );

		break;
	}
}

// 帮派的天机院主
void do_look_5(object me, object who )
{
	string result, name;
	int position, store;
	object orgnpc;
	result = sprintf("%s：\n    我是负责管理本帮帮派技能开发的天机院院主，不知阁下找我何要事？\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (position>0 && me->get_org_name()==name)
	{
		result += sprintf(ESC"学习技能\ntalk %x# skill\n", getoid(who));
		if (position>=8)
		{
			result += sprintf(ESC"研究管理\ntalk %x# info.10\n", getoid(who));
		}
		result += sprintf(ESC"了解当前帮派技能情况\ntalk %x# info.20\n", getoid(who));
	}
	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 天机院主的相关函数
void do_info_5(object me, object who, string arg )
{
	int position, flag, number, i, size, level, time, degree, speed, len, *search;
	string result, name, list, *key;
	object orgnpc, city, *char, item, file;
	mapping skls;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	skls = orgnpc->get_skill_dbase();
	size = 0;
	number = sizeof(skls);
	key = keys(skls);
	for (i=0;i<number;i++)
	{
		if (orgnpc->get_skill(to_int(key[i]))>1) size++;
	}
	switch(flag)
	{
	case 10:
	case 11:
		if (position<8) return;
		if (orgnpc->get_science()>=orgnpc->get_grade()*4)
		{
			result = sprintf("%s：\n    现在本帮的研究力已经达到了%d点的上限，无法再提升了。大人还是多多关注一下帮派的其他事务吧。\n", who->get_name(), orgnpc->get_grade()*4);
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		time = orgnpc->get_sciencetime();
		if (time>0)
		{
			if (time()>time)
			{
				orgnpc->add_science(1);
				orgnpc->set_sciencetime(0);
				char = orgnpc->get("comrade");
				if (char && sizeof(char)>0)
				{
					for (i=0;i<sizeof(char);i++)
						char[i]->set_level(orgnpc->get_science());
				}
				orgnpc->save();
				FAMILY_D->org_channel( name, 0, sprintf( HIR "经过天机院的不懈努力，帮派研究力顺利提升了1点，现帮派的研究力为%d。",
                                         orgnpc->get_science() ) );
			}
			else
			{
				result = sprintf("%s：\n    现在全天机院上下一众正抓紧对帮派科技的研究开发，大人只需再等待%d分钟就一定可以看到研究的成果了。\n", who->get_name(), (time - time())/60);
				result += sprintf(ESC"离开\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
		}
		if (flag==10)
		{
			result = sprintf("%s：\n    提升1点研究力需要消耗300万帮派资金和100点储备，必须耗时十秒。是否提升研究力？\n", who->get_name() );
			result += sprintf(ESC"确定\ntalk %x# info.11\n", getoid(who));
			result += sprintf(ESC"取消\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		}
		else
		{
			if (orgnpc->get_gold()<3000000 || orgnpc->get_store()<100)
			{
				result = sprintf("%s：\n    现在帮中的资金和储备十分不足，难以满足帮派技能的研究开发。还望大人多多理善帮中的财政。\n", who->get_name() );
				result += sprintf(ESC"离开\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			}
			else
			{
				orgnpc->add_gold(-3000000);
				orgnpc->set_store(orgnpc->get_store()-100);
				orgnpc->set_sciencetime(time()+1*10);
				orgnpc->save();
				result = sprintf("%s：\n    现在全天机院上下一众正抓紧对帮派科技的研究开发，大人只需再等待十秒就一定可以看到研究的成果了。\n", who->get_name() );
				result += sprintf(ESC"离开\nCLOSE\n");
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			}
		}
		break;
	case 20:
		result = sprintf("%s：\n    当前帮派的研究力为%d，已经研究的技能为%d个，最大可同时研究的技能数量上限为%d个。\n", who->get_name(), orgnpc->get_science(), size, 1 + orgnpc->get_science()/5 );
		len = strlen(result);
		i = orgnpc->get_research();
		if (i>0 && objectp(file = load_object(sprintf("/skill/%02d/%04d", i/100, i))))
		{
			result += sprintf("当前研究技能是%s，", file->get_name());
			switch(orgnpc->get_research_level())
			{
			case 1: list = "正常";break;
			case 2: list = "加快";break;
		       default: list = "超快";break;
			}
			speed = 400 + orgnpc->get_research_level()*400;
			result += "正在以" + list + "的速度研究中，";
			level = orgnpc->get_skill(i);
			degree = orgnpc->get_skill_degree(i);
			level++;
			result += sprintf("相信%d小时后便能提升一级。\n", (level*level*5 - degree)/speed +1);
		}
		skls = orgnpc->get_researchs();
		search = keys(skls);
		size = sizeof(search);
		if (size>0)
		{
			for (i=0;i<size;i++)
			{
				if (search[i]>0 && objectp(file = load_object(sprintf("/skill/%02d/%04d", search[i]/100, search[i]))))
				{
					result += sprintf("    当前研究的"HIR"%s"NOR"，", file->get_name());
					switch(skls[search[i]])
					{
					case 1: list = "正常";break;
					case 2: list = "加快";break;
				       default: list = "超快";break;
					}
					speed = 400 + skls[search[i]]*400;
					result += "正在以" + list + "的速度研究中，";
					level = orgnpc->get_skill(search[i]);
					degree = orgnpc->get_skill_degree(search[i]);
					level++;
					result += sprintf("相信%d小时后便能提升一级。\n", (level*level*5 - degree)/speed +1);
				}				
			}
		}
		if (len==strlen(result)) result += "当前没有研究技能。\n";
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	}
}

// 帮派的神机院主
void do_look_6(object me, object who )
{
	string result, name, *list;
	int position, store, p, i, size, count;
	object orgnpc, item;
	result = sprintf("%s：\n    我就是神机院的院主，每天十二点和二十四点我这里都会出产一些物品。只要本帮的规模越壮大，我能制作的物品品质便会越高。怎么？是不是想买些什么？\n", who->get_name());
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	// 检查是否过了制作的时间
	who->check_item();
	list = orgnpc->get_productfile2();
	if (position>=ORG_TANGZHU && me->get_org_name()==name)
	{
		size = sizeof(list);
		if (size==0)
		{
			if (orgnpc->get_stable()<1000)
			{
				result += ESC"帮派安定度不足，无法制作。\nCLOSE\n";
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			result += ESC"产品出售完毕\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		count = 0;
		for (i=0;i<size;i++)
		{
			if (list[i]!="")
			{
				result += sprintf(ESC"花费%d金购买%s\ntalk %x# info.%d\n", 20000* orgnpc->get_grade(), list[i]->get_name(), getoid(who), i+1);
				count ++;
			}
		}
		if (count==0) 
		{
			count = orgnpc->get_buytime();
			if (count)
				result += sprintf(ESC"产品已于%s出售完毕\nCLOSE\n", short_time(count) );
			else
				result += ESC"产品出售完毕\nCLOSE\n";
		}
		else result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}

	result += sprintf(ESC"离开\nCLOSE\n");
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
}

// 帮派的神机院主
void do_info_6(object me, object who, string arg )
{
	string result, name, *list;
	int position, store, p, i, size;
	object orgnpc, item;
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	position = me->get_org_position();
	if (position<1||name!=me->get_org_name())
	{
		return;
	}
	if ( position<ORG_TANGZHU)
	{
		return;
	}
	list = orgnpc->get_productfile2();
	size = sizeof(list);
	if (size==0)
	{
		return;
	}
	i = to_int(arg);
	if (i<1||i>size) return;
	i --;
	if (list[i]=="") return;
	if (me->get_cash()<orgnpc->get_grade()*20000)
        {
                notify( "您的现金不足。" );
                return ;
        }
        me->add_cash(-orgnpc->get_grade()*20000);
        me->log_money("帮派产品购买", -orgnpc->get_grade()*20000);
        "/sys/sys/count"->add_use("orgbuy", orgnpc->get_grade()*20000);
	item = new (list[i]);
	if (!item) return;
        if( USER_INVENTORY_D->can_carry( me, item )  < 1 )
        {
                notify( "您携带的东西太多了。" );
                destruct(item);
                return ;
        }
        notify( sprintf("您购买了%s", item->get_name()) );
        if( p = item->move(me, -1) )
        {
                item->add_to_user(p);
        }
        else
        	destruct(item);
        list[i] = "";
        orgnpc->set_productfile2(list);
        orgnpc->set_buytime(time());
        orgnpc->save();
}

// 提升帮派规模
void do_upgrade(object me, object who, string arg )
{
	string result, name;
	int position, grade, stable, favour, store, gold, time;
	object orgnpc, war;
	position = me->get_org_position();
	name = who->get_org_name();
	if (name=="") return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	if (name!=me->get_org_name()) return;
	if ( position<9 ) return;
	grade = orgnpc->get_grade();
	if (grade>=5) return;
	switch(grade)
	{
	case 1: stable = 1; break;
	case 2: stable = 2; break;
	case 3: stable = 3; break;
	case 4: stable = 4; break;
	}
	favour = stable;
	store = grade * 300;
	gold = 2000000*grade;
	time = orgnpc->get_gradetime();
	if (time>0)
	{
		if (time <time())
		{
			orgnpc->set_gradetime(0);
			orgnpc->set_grade(grade+1);
			FAMILY_D->org_channel( name, 0, sprintf( HIR "帮派规模上升1，现帮派的规模为%d。",
				grade + 1 ) );
		}
		else
		{
			result = sprintf("%s：\n    规模提升还剩余%d分钟。\n", who->get_name(), (time-time())/60);
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
	}
	if (arg==""||arg==0)
	{
		result = sprintf("%s：\n    当前你的帮派规模为%d，提升下一级规模其安定度与人气度都必须达到%d，而且需要消耗%d点储备、%d资金，决定提升规模后，本帮无需打怪物，只需要站1-3分钟后便能顺利提升本帮规模了。必须注意的是，一旦防守失败，帮派升级所付出的所有金钱储备是不会返还回来的。你确定要提升帮派规模吗？\n", who->get_name(), grade, favour, store, gold);
		result += sprintf(ESC"确定\ntalk %x# upgrade.1\n", getoid(who));
		result += sprintf(ESC"取消\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_gradewartime())
	{
		stable = (orgnpc->get_gradewartime()- time())/60;
		result = sprintf("%s：\n    本帮%d分钟后会马上受到无数怪物的入侵，如果能成功击退怪物，十秒后便能顺利提升本帮规模了。\n", who->get_name(), stable);
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_stable()<stable)
	{
		result = sprintf("%s：\n    帮派安定度不足%d，暂时无法提升规模。\n", who->get_name(), stable);
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_favour()<favour)
	{
		result = sprintf("%s：\n    帮派人气度不足%d，暂时无法提升规模。\n", who->get_name(), favour);
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_store()<store)
	{
		result = sprintf("%s：\n    帮派储备不足%d，暂时无法提升规模。\n", who->get_name(), store);
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (orgnpc->get_gold()<gold)
	{
		result = sprintf("%s：\n    帮派资金不足%d，暂时无法提升规模。\n", who->get_name(), gold);
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (MAIN_D->get_host_type()==2)
	{
		orgnpc->set_store(orgnpc->get_store()-store);
		orgnpc->set_gold(orgnpc->get_gold()-gold);
		orgnpc->set_gradetime(time()+1*10);
		orgnpc->save();
		FAMILY_D->org_channel( name, 0, HIR "本帮派已经开始进行大规模的升级，需时为十秒。" );
		return;
	}
	war = new ("/inh/std/upgrade");
	if (war)
	{
		orgnpc->set_store(orgnpc->get_store()-store);
		orgnpc->set_gold(orgnpc->get_gold()-gold);
		orgnpc->set_gradewartime(time()+600);
		orgnpc->set_wardamage(0);
		orgnpc->save();
		war->set_org_name(name);
		war->set_z(orgnpc->get("z"));
		war->set_grade(orgnpc->get_grade());
//		war->add_heart_sec(500);
		FAMILY_D->org_channel( name, 0, HIR "本帮派已经开始进行大规模的升级，相信再过10分钟之后本帮便会受到第一波怪物的入侵，请帮派所有成员尽快作好防御的准备！" );
	}
}

// 帮派总管的天枢院任务
void do_quest(object me, object who, string arg )
{
	int position, flag, number, i, size, level, count, gold, p, type, x, y, z, order, exp, pot, cash;
	string result, name, list;
	object orgnpc, city, *char, item, file, npc;
	object *inv;
	position = me->get_org_position();
	flag = to_int(arg);
	name = me->get_org_name();
	if (position==0 || name=="" || name!=who->get_org_name()) return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	number = me->get_number();
	switch(flag)
	{
	case 10:
		if (me->get_save_2("orgtask2.type")!=0)
		{
			result = sprintf("%s：\n    你的天枢院任务还没有完成，不能领取新任务\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask2.time")<180)
		{
			result = sprintf("%s：\n    做事要细心，不要操之过急～！凡事都有个章程，让我去察看一下帮派里面的事物，看看还有什么可差你去办的。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		result = sprintf("%s：\n    本帮最近事务繁多，作为本帮成员的你，一定要维护本帮的荣誉和利益，现在有一些事情要差遣你去做，你一定要尽心尽力去完成。\n", who->get_name());
		result += sprintf(ESC"接受\ntalk %x# quest.11\n", getoid(who));
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 11:
		if (me->get_save_2("orgtask2.type")!=0)
		{
			result = sprintf("%s：\n    你的天枢院任务还没有完成，不能领取新任务\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		if (time()-me->get_save_2("orgtask2.time")<180)
		{
			result = sprintf("%s：\n    领取新的天枢院任务需要间隔三分钟。\n", who->get_name());
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		type = 1+random(6);
		if (is_god(me))
		{
			if (me->get("lb")) type = me->get("lb");
		}
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"帮派任务" );
		if (type==2) type = 1;
		switch(type)
		{
		case 1:
			npc = new ("/npc/org/0100");
			npc->set("user", me->get_number());
			npc->set_name(name+"信差");
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s：\n    %s信差在（%s的%d, %d）不幸遭到敌帮暗算，他身上有本帮的机密情报，你前去将此疗伤药送到%s信差手中，确保他能安全回帮。\n", who->get_name(), name, file->get_name(), get_x(npc), get_y(npc), name );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_2("orgtask2.npc", npc);
			item = new ("/item/01/0003");
                        if( p = item->move(me, -1) )
                        {
                                item->add_to_user(p);
                        }
                        else    destruct(item);
                        send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 1, "扶危救急" );
			break;
		case 2:
			npc = new ("/npc/org/0101");
			npc->set("user", me->get_number());
			npc->set_owner(me);
			size = sizeof(task2);
			i = random(size);
			npc->set_name(sprintf("%s的孩子(%d)", task2[i], me->get_number()));
			me->set_save_2("orgtask2.name", task2[i]);
			me->set_save_2("orgtask2.id", sprintf("%x#", getoid(npc)));
			me->set_2("orgtask2.npc", npc );
	                z = get_z(who);  x = get_x(who);  y = get_y(who);
	                if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
	                {
	                        x = p / 1000;  y = p % 1000;
	                        npc->add_to_scene( z, x, y, 3 );
	                }
			result = sprintf("%s：\n    本帮一位成员领回了一个迷路的孩童，经打听他是%s的孩子，为了搞好和百姓的关系，你就去将%s的孩子送回去。\n", who->get_name(), task2[i], task2[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 2, "迷路的孩童" );
			break;
		case 3:
			npc = new ("/npc/org/0102");
			npc->set("user", me->get_number());
			npc->set_name(name+"的宝箱");
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s：\n    本帮一件重要宝物遗失在%s的（%d,%d）位置处，那件宝物关系到本帮的生死存亡，我希望你尽快能将那件宝物寻回。\n", who->get_name(), file->get_name(), get_x(npc), get_y(npc) );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_save_2("orgtask2.id", sprintf("%x#", getoid(npc)));
			me->set_2("orgtask2.npc", npc);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "寻找遗失的宝物" );
			break;
		case 4:
			size = sizeof(task2);
			i = random(size);
			me->set_save_2("orgtask2.name", task2[i]);
			result = sprintf("%s：\n    本帮的一位弟子甚是思念自己的亲人%s，为了稳定帮众的军心，现在差你将这封家书送到他的亲人手中。\n", who->get_name(), task2[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			item = new ("/item/01/0005");
                        if( p = item->move(me, -1) )
                        {
                                item->add_to_user(p);
                        }
                        else    destruct(item);
                        send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 4, "千里送家书" );
			break;
		case 5:
			size = sizeof(food);
			i = random(size);
			me->set_save_2("orgtask2.name", food[i]);
			result = sprintf("%s：\n    现在天下比较太平，没有太大的动荡，趁这个时候你赶快替帮派收集1个%s，以备帮里应急之需。\n", who->get_name(), food[i] );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5, "丰衣足食" );
			break;
		case 6:
			npc = new ("/npc/org/0103");
			npc->set("user", me->get_number());
			npc->set("target", me->get_name());
			npc->init_level(me->get_level());
			z = 10*(1+random(8));
			p = get_xy_point(z, IS_CHAR_BLOCK);
			if (!p) return;
			npc->add_to_scene(z, p / 1000, p % 1000, 3);
			file = load_object(sprintf("/map/map/%03d", z));
			result = sprintf("%s：\n    本帮乃仁义之帮，出门行走江湖一定要行侠仗义。最近听闻有个%s出现在%s（%d,%d），危害百姓，你前去将他除掉。\n", who->get_name(), npc->get_name(), file->get_name(), get_x(npc), get_y(npc) );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			me->set_save_2("orgtask2.place", file->get_name());
			me->set_save_2("orgtask2.name", npc->get_name());
			me->set_save_2("orgtask2.x", get_x(npc));
			me->set_save_2("orgtask2.y", get_y(npc));
			me->set_2("orgtask2.npc", npc);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 6, "除恶扶弱" );
			break;
		}
		me->set_save_2("orgtask2.type", type);
		me->set_save_2("orgtask2.status", 1);
		me->set_save_2("orgtask2.time", time());
		break;
	case 20:
	case 21:
		switch(me->get_save_2("orgtask2.type"))
		{
		case 3:
			item = present("遗失的宝物", me, 1, MAX_CARRY*4);
			if (!objectp(item))
			{
				result = sprintf("%s：\n    差遣你的事可否完成～！不要偷懒哦～！倘若帮主知道后，定会重重责罚于你。光大本帮是帮中每个成员的责任，希望你牢记。\n", who->get_name() );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			break;
		case 5:
			list = me->get_save_2("orgtask2.name");
			inv = all_inventory(me, 1, MAX_CARRY*4);
			inv -= ({ 0});
			count = 0;
			for( i = 0, size = sizeof(inv); i < size; i ++ )
			{
				if ( inv[i]->get_name()==list)
				{
					if (inv[i]->get_max_combined()<=1) count ++;
					else count += inv[i]->get_amount();
				}
			}
			if (count<1)
			{
				result = sprintf("%s：\n    差遣你的事可否完成～！不要偷懒哦～！倘若帮主知道后，定会重重责罚于你。光大本帮是帮中每个成员的责任，希望你牢记。\n", who->get_name() );
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
				return;
			}
			break;
		default:
			result = sprintf("%s：\n    差遣你的事可否完成～！不要偷懒哦～！倘若帮主知道后，定会重重责罚于你。光大本帮是帮中每个成员的责任，希望你牢记。\n", who->get_name() );
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return ;
		}
		if (flag==20)
		{
			result = sprintf("%s：\n    此事你做的非常好～！%s有你这样的助手，以后定能雄霸各帮之首！我会向帮主禀明你的功劳，让他重重的奖赏你。\n", who->get_name(), name );
			result += sprintf(ESC"完成任务\ntalk %x# quest.21\n", getoid(who));
			result += sprintf(ESC"离开\nCLOSE\n");
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
			return;
		}
		order = me->get_save_2("orgtask2.order");
		order ++;
		level = me->get_level();
		exp = (level*8+order*order*level*4)*3/5;
		exp = exp * me->get_online_rate()/100;
		pot = order*10+level;
		pot = pot * me->get_online_rate()/100;
		cash = (500+level*6*(order-1))*3/6;
		cash = cash * me->get_online_rate()/100;
		switch(me->get_save_2("orgtask2.type"))
		{
		case 3:
			send_user( me, "%c%d", 0x2d, getoid(item) );
                        destruct(item);
                        orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+1+order*2/9);
			orgnpc->add_stable(1);
			orgnpc->add_favour(1);
			me->add_potential(pot);
			me->add_cash(cash);
			me->add_exp(exp);
                        me->log_money("帮派任务", cash);
                        "/sys/sys/count"->add_income("org", cash);
                        send_user(me, "%c%s", ';', sprintf("你获得经验%d，潜能%d，金钱%d，帮贡增加了%d，帮派的人气提升1点、安定提升1点。", exp, pot, cash, 1+order*2/9) );
                        me->delete_save_2("orgtask2");
                        me->delete_2("orgtask2");
                        if (order>=10)
                        {
                        	order = 0;
                        	if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);
                        }
                        me->set_save_2("orgtask2.order", order);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3,"" );
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
			break;
		case 5:
			count = 1;
			for( i = 0, size = sizeof(inv); i < size; i ++ )
			{
				if ( inv[i]->get_name()==list)
				{
					if (inv[i]->get_max_combined()<=1)
					{
						count --;
						send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
	                                	destruct(inv[i]);
					}
					else
					{
						if (count > inv[i]->get_amount())
						{
							count -= inv[i]->get_amount();
							send_user( me, "%c%d", 0x2d, getoid(inv[i]) );
	                                		destruct(inv[i]);
						}
						else
						{
							inv[i]->add_amount( -count );
							count = 0;
						}
					}
					if (count<=0) break;
				}
			}
                        orgnpc->set_member_contribute(number, orgnpc->get_member_contribute(number)+1+order*2/9);
			orgnpc->add_stable(2);
			orgnpc->add_favour(2);
			me->add_potential(pot);
			me->add_cash(cash);
			me->add_exp(exp);
                        me->log_money("帮派任务", cash);
                        "/sys/sys/count"->add_income("org", cash);
                        send_user(me, "%c%s", ';', sprintf("你获得经验%d，潜能%d，金钱%d，帮贡增加了%d，帮派的人气提升2点、安定提升2点。", exp, pot, cash, 1+order*2/9));
                        me->delete_save_2("orgtask2");
                        me->delete_2("orgtask2");
                        if (order>=10)
                        {
                        	if (random100()<5*me->get_online_rate()/100) "/quest/box"->give_box(me);
                        	order = 0;
                        }
                        me->set_save_2("orgtask2.order", order);
			send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5,"" );
			send_user( me, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"" );
			break;
		}
		break;
	case 30:
		if (position!=9) return;
		if (time()>orgnpc->get_demisstime()) return;
		result = sprintf("%s：\n    即将取消本次禅让，确认吗？\n", who->get_name() );
		result += sprintf(ESC"确认\ntalk %x# quest.31\n", getoid(who));
		result += sprintf(ESC"离开\nCLOSE\n");
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 31:
		if (position!=9) return;
		if (time()>orgnpc->get_demisstime()) return;
		orgnpc->set_demissnumber(0);
		orgnpc->set_demisstime(0);
		orgnpc->save();
	        FAMILY_D->org_channel( name, 0, sprintf( HIR "帮主%s经过再三考虑，最终决定不再让位。",
	                who->get_name() ) );
		break;
	}

}

void init_org_place(int z, string name, object orgnpc)
{
	object npc, *all;
	int i;
	int * locate = ({ 87, 123 , 95, 129 , 95, 117 , 107, 126, 121, 111, 110, 102, 86, 140, 77, 134,  });

	npc = new ("/npc/org/0010");
	npc->set_org_name(name);
	npc->set_name(name+"总管");
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 79, 141, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0011");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 67, 134, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0012");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 114, 152, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0013");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 58, 110, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0014");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 67, 104, 6);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0015");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 110, 88, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/0016");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 139, 110, 2);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	npc = new ("/npc/org/qgl_amass");
	npc->set_org_name(name);
	npc->set("orgnpc", orgnpc);
	npc->add_to_scene(z, 82, 139, 3);
	set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	all = ({ });
	// 箭塔
	for (i=0;i<8;i++)
	{
		npc = new ("/npc/org/0017");
		npc->set_org_name(name);
		npc->set("orgnpc", orgnpc);
		npc->set_level(orgnpc->get_science());
		npc->add_to_scene(z, locate[2*i], locate[2*i+1], 2);
		set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
		all += ({ npc });
	}
	orgnpc->set("comrade", all);
}

void task_giveup(object player, int type)
{
	int time;
	object npc;
	if (type==20) return;		// 经商不能放弃
	send_user( player, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, type, "" );
	send_user( player, "%c%c%c%w%s", 0x51, 1, 1, TID_ORG, "" );
	if (type<10)
	{
		switch(type)
		{
		case 1:
		case 2:
		case 3:
		case 6:
			npc = player->get_2("orgtask2.npc");
			if (objectp(npc))
			{
		                npc->remove_from_scene();
		                destruct(npc);
			}
			break;
		}
		time = player->get_save_2("orgtask2.time");
		player->delete_save_2("orgtask2");
		player->set_save_2("orgtask2.time", time);
	}
	else
	if (type==10)
	{
		time = player->get_save_2("orgtask.time");
		player->delete_save_2("orgtask");
		player->set_save_2("orgtask.time", time);
	}
}

void send_task_list(object who)
{
	int type;
	if (who->get_save_2("orgtask.type")==0&&who->get_save_2("orgtask2.type")==0&&who->get_save_2("orgtask3.type")==0) return;
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ORG,"帮派任务" );
	type = who->get_save_2("orgtask.type");
	if (type>0) send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 10, "储备任务" );
	type = who->get_save_2("orgtask2.type");
	switch(type)
	{
	case 1:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 1, "扶危救急" );
		break;
	case 2:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 2, "迷路的孩童" );
		break;
	case 3:
		if (who->get_save_2("orgtask2.status")==1)
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "寻找遗失的宝物" );
		else
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 3, "送回遗失的宝物" );
		break;
	case 4:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 4, "千里送家书" );
		break;
	case 5:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 5, "丰衣足食" );
		break;
	case 6:
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 6, "除恶扶弱" );
		break;
	}
	type = who->get_save_2("orgtask3.type");
	if (type>0) send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, TID_ORG, 20, "商人任务" );
}

string get_task_str(object who, int iKind)
{
	string result, name, unit;
	int count, order, level;
	name = who->get_org_name();
	result = "";
	if (name=="") return result;
	order = who->get_save_2("orgtask2.order");
	level = who->get_level();
	switch(iKind)
	{
	case 1:
		result = sprintf(BLK"扶危救急\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    拯救负伤的%s信差，将疗伤药安全地送到他手中。\n"BLK"任务描述：\n"BLK"    %s信差在%s的（%d,%d）不幸遭到敌帮暗算，他身上有本帮的机密情报，你前去将此疗伤药送到%s信差手中，确保他能安全回帮。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, name, name, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), name, 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 2:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"迷路的孩童\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    将%s的孩子安全地送回%s手中。\n"BLK"任务描述：\n"BLK"    本帮一位成员领回了一个迷路的孩童，经打听他是%s的孩子，为了搞好和百姓的关系，你就去将%s的孩子送回去。他就住在%s的%s。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, name, name, name, name, "/quest/escort"->get_country_name(name), "/quest/escort"->get_place_name(name), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 3:
		result = sprintf(BLK"遗失的宝物\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    将遗失的宝物寻回\n"BLK"任务描述：\n"BLK"    本帮一件重要宝物遗失在%s的（%d,%d）位置处，那件宝物关系到本帮的生死存亡，我希望你尽快能将那件宝物寻回。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 4:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"千里送家书\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    将家书送给%s。\n"BLK"任务描述：\n"BLK"    本帮的一位弟子甚是思念自己的亲人%s，他就住在%s的%s。为了稳定帮众的军心，现在差你将这封家书送到他的亲人手中。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, name, name, "/quest/escort"->get_country_name(name), "/quest/escort"->get_place_name(name), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 5:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"丰衣足食\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    收集1个%s。\n"BLK"任务描述：\n"BLK"    现在天下比较太平，没有太大的动荡，趁这个时候你赶快替帮派收集1个%s，以备帮里应急之需。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, name, name, 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 6:
		name = who->get_save_2("orgtask2.name");
		result = sprintf(BLK"除恶扶弱\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    除掉%s。\n"BLK"任务描述：\n"BLK"    本帮乃仁义之帮，出门行走江湖一定要行侠仗义。最近听闻有个%s出现在%s的（%d,%d）危害百姓，你前去将他除掉。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验%d\n"BLK"          潜能%d\n"BLK"          金钱%d\n", order+1, name, name, who->get_save_2("orgtask2.place"), who->get_save_2("orgtask2.x"), who->get_save_2("orgtask2.y"), 1+(order+1)*2/9, (level*8+(order+1)*(order+1)*level*4)*3/5, (order+1)*10+level, (500+level*6*order)*3/6 );
		break;
	case 10:
		name = who->get_save_2("orgtask.name");
		count = who->get_save_2("orgtask.count");
		unit = who->get_save_2("orgtask.unit");
		order = who->get_save_2("orgtask.order");
		result = sprintf(BLK"增加储备\n"BLK"当前环数：%d/10\n"BLK"任务目的：\n"BLK"    收购"HIR"%d%s%s"BLK"，并交给帮派的帐房先生。\n"BLK"任务描述：\n"BLK"    近期帮派由于发展、研究、维护的关系，需要储备大量的材料以备不时之需。目前帮派缺乏"HIR" %s "BLK"，因此帮中的帐房先生委托我帮忙去找"HIR"%d%s%s"BLK"回来。\n"BLK"任务奖励：帮贡%d点\n"BLK"          经验2000\n", order+1, count, unit, name, name, count, unit, name, order+1 );
		break;
	case 20:
		count = who->get_save_2("orgtask3.money");
		result = sprintf(BLK"帮派经商\n"BLK"任务目的：\n"BLK"    赚取%d金后，带回给帮派的帐房先生\n"BLK"任务描述：\n"BLK"    帮中所有的大小事务都离不开金钱的开销。因此商人的存在是必不可少的。从帐房先生手中得到一张%d金的商票后，要想方设法赚取%d金回来交差才行。\n"BLK"任务奖励：帮贡%d点\n", count/2, count, count/2, who->get_level()/4 );
		break;
	}
	return result;
}

void upgrade(object me)
{
	string name, *all, *names, file, name2;
	object orgnpc;
	mapping skls;
	int level, contrib, store, i, size, skill, level2;
	name = me->get_org_name();
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	level = me->get_level();
	contrib = level * 12 / 10;
	if (level==10) store = 200;
	else
	if (level==20) store = 400;
	else
	if (level==25) store = 800;
	else
	if (level==30) store = 1200;
	else
	if (level>30)
	{
		switch((level-31)/5)
		{
		default:
			  store = 1200+((level-31)/5)*400; break;
		}
	}
	if (store>0)
	{
		skls = orgnpc->get_skill_dbase();
		size = sizeof(skls);
		all = ({ });
		names = sort_array( keys(skls), 1 );
		for (i = 0;i<size;i++)
		{		
			skill = to_int(to_int(names[i]));	
			if (skill==408||skill==409) continue;
			if (skill>=430 && skill<=438) continue;
			if (orgnpc->get_skill(skill)>1)
			{
				all += ({ names[i] });
			}
		}
		if (sizeof(all)==0) all = ({ "0109" });
		i = random(sizeof(all));
		skill = to_int(to_int(all[i]));
		level2 = orgnpc->get_skill(to_int(all[i]));
		orgnpc->improve_skill(to_int(all[i]), store);
		orgnpc->set_member_contribute(me->get_number(), orgnpc->get_member_contribute(me->get_number())+contrib);
		orgnpc->save();
		if( load_object( file = SKILL->get_skill_file(skill) ) && ( file->is_basic_skill()||file->is_vita_skill() ) )
			name2 = file->get_name();
		else
			name2 = all[i];
		if (level2<orgnpc->get_skill(to_int(all[i])))                       
                	FAMILY_D->org_channel( name, 0, sprintf( "恭喜%s（%d）等级达到%d级，帮派的"HIR" %s "NOR"熟练度增加了%d点。"HIR" %s "NOR"提升到%d级。",
                        	me->get_name(), me->get_number(), level, name2, store, name2, orgnpc->get_skill(to_int(all[i])) ) );
		else
 	               	FAMILY_D->org_channel( name, 0, sprintf( "恭喜%s（%d）等级达到%d级，帮派的"HIR" %s "NOR"熟练度增加了%d点。",
        	                me->get_name(), me->get_number(), level, name2, store ) );
		                        	
		
	}
}
//帮派群发信件
void org_mail(int id,string cName, string info)
{
	int i,size,number;
	object orgnpc;
	string cTmp,*nName,account;
	if ( !stringp(info) || sizeof(info) == 0 )
		return ;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", cName ) );
	if (!objectp(orgnpc))
		return ;
	size = orgnpc->sizeof_member_dbase();
	nName = orgnpc->get_all_member();
	for(i=0;i<size;i++)
	{
		number = to_int(nName[i]);
		account = orgnpc->get_member_id(number);
		"/inh/user/mail"->sys_mail(account, number,info);
	}
}