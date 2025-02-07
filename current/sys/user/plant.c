
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <npc.h>
#include <time.h>

#define SAVE_FILE       "data/city/plant" SAVE_EXTENSION

inherit DBASE_F;
inherit SAVE_F;

int Day;

static mapping sayword = ([
	"齐国" : "不要相信楚国的杨玉米说的话，楚国经常发生水灾，根本种不出好东西。只有我们齐国人才是最勤劳的，你找我帮你的话一定可以获得大丰收。",
	"韩国" : "我们韩国的农夫是最会帮你打理农田的，不像魏国那些蠢农夫那样，你看，他们的地里满是蝗虫。",
	"赵国" : "我们赵国的农夫不但能种田，还能养畜放牧，不像燕国那样寒冷的小国，他们的牛经常被冻成一块冰。",
	"魏国" : "赵国是个荒芜的地区，在那里无论种什么下去都会死掉的，所以你要找人种田的话千万不要到赵国人，要找一定要找好像我们魏国这样丰润的地方种。",
	"秦国" : "国之中要数我们秦国的国力最强，所以我们的农民也很有能耐，你找我们秦国人帮你生产是明智的选择，如果你找好像韩国的张肥牛那种不讲信用的人种东西的话你种的东西都会烂掉。",
	"楚国" : "七国之中要数我们楚国的国土最广，所以我们的农夫一定可以种出最好的农产品。好像秦国这样的边境小国的农夫都是土包子，根本就不会种东西。",
	"燕国" : "齐国那边天天刮台风，齐国农夫种的东西都会飞到天上的。你就不要旨意找他种点什么啦，要想风调雨顺的话还是要找我们燕国人帮你吧！",
	]);

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：构造处理
void create() 
{
	restore_object(SAVE_FILE);	
        call_out( "hour_callout", time() -  time() / 3600 * 3600 ); 
}

int set_day(int d) {return Day = d;}

int get_day() {return Day;}

// 函数：取存盘文件名
string get_save_file() { return SAVE_FILE; }

void reset_plant()
{
	object me = this_object();
	int iTime, day, hour, i, size, j;
	string * country = ({ "齐国", "韩国", "赵国", "魏国", "秦国", "楚国", "燕国",  });
	string result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);
	hour = mxTime[TIME_HOUR];
	day = time()/(24*3600);	
	me->set_day(day);	
	if (MAIN_D->get_host_type()==6012) return;
	size = sizeof(country);
	for (i=0;i<size;i++)
	{
		me->set_save(country[i], 0);
	}
	i = random(size);
	j = random(2);
	if (j==0)
	{
		me->set_save(country[i], -90);
		result = sprintf("传闻%s发生了大台风，农产品损毁好严重啊！听说还有人看见连牛也被卷到了天上的样子，也不知道是不是真的。", country[i] );
	}
	else
	{
		me->set_save(country[i], -50);
		result = sprintf("听说最近在%s发生了水灾，农产品好像都受到了不同程度的破坏的样子。", country[i] );
	}		
	CHAT_D->rumor_channel( 0, HIM + result );
	country -= ({ country[i] }); 
	size = sizeof(country);
	i = random(size);
	j = random(2);
	if (j==0)
	{
		me->set_save(country[i], 50);
		result = sprintf("听说%s最近风调雨顺，农场的农产品都好像长得特别好。", country[i] );
	}
	else
	{
		me->set_save(country[i], 100);
		result = sprintf("%s最近好像获得了大丰收，有人说那里的鸡每次都可以生两个蛋，真是上天眷顾啊！", country[i] );
	}		
	CHAT_D->rumor_channel( 0, HIM + result );	
	save();	
}

void hour_callout()
{
	object me = this_object();
	int iTime, day, hour, i, size, j;
	string * country = ({ "齐国", "韩国", "赵国", "魏国", "秦国", "楚国", "燕国",  });
	string result;
	mixed *mxTime;
	iTime = time();
	call_out( "hour_callout", 3600 ); 
	mxTime = localtime(iTime);
	hour = mxTime[TIME_HOUR];
	day = time()/(24*3600);
	if (hour>=12 && day!=me->get_day())
	{	
		reset_plant();
	}	
}

void do_look(object me, object who )
{
        string result = "";
	mixed *mxTime;
	int iTime, day, hour;
	iTime = time();
	mxTime = localtime(iTime);
	day = time()/(24*3600);
	hour = mxTime[TIME_HOUR];
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(me, "%c%s", '!', "种植系统尚未开放！");
		return;
	}
	if (hour>=12 && day!="/sys/user/plant"->get_day()) reset_plant();
        if (me->get_level()<30)
        {
        	result = sprintf("%s：\n    %s\n    你等级到达30后，我可以帮你生产一些农产品去做酒食的材料，你到了30级的时候一定要来找我哦。\n", who->get_name(), sayword[who->get_city_name()] );
        	result += ESC "离开\nCLOSE\n";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
        	return;
        }
        if (hour<12)
        {
        	result = sprintf("%s：\n    以前有个叫孟子的人说过：“不违农时，谷不可胜食也。”这么说我只在农时才生产农产品，我的食物一定会食之不尽。哈哈，我聪明吧？所以我在这个时间是不会生产农产品的，你农时的时候再来找我吧，农时是从每天中午12点开始到晚上24点结束。\n", who->get_name() );
        	result += sprintf( ESC "领取收成\ntalk %x# welcome.20\n", getoid(who) );
        	result += ESC "离开\nCLOSE\n";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
        	return;
        }
        result = sprintf("%s：\n    %s\n", who->get_name(), sayword[who->get_city_name()] );
        result += sprintf( ESC "生产农产品\ntalk %x# welcome.10\n", getoid(who) );
        result += sprintf( ESC "领取收成\ntalk %x# welcome.20\n", getoid(who) );
        result += sprintf( ESC "查询种植情况\ntalk %x# welcome.30\n", getoid(who) );
        if (is_god(me))
        {
        	result += sprintf( ESC "设置种植完成\ntalk %x# welcome.40\n", getoid(who) );
        	result += sprintf( ESC "随机天灾人祸\ntalk %x# welcome.50\n", getoid(who) );
        }
	result += ESC "离开\nCLOSE\n";
	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
}

void do_welcome(object me, object who, string arg )
{
	string result = "", *key, file, result2;
	int type, level, price, flag, p, i;
	object plant;
	mixed *mxTime;
	int iTime, day, hour, count, inv;
	object obj;
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(me, "%c%s", '!', "种植系统尚未开放！");
		return;
	}	
	iTime = time();
	mxTime = localtime(iTime);
	hour = mxTime[TIME_HOUR];
	level = me->get_level();
	day = time()/(24*3600);
	if (hour>=12 && day!="/sys/user/plant"->get_day()) reset_plant();
	if (level<30) return;
	if (!arg) return;
	plant = this_object();
	key = explode (arg, " ");
	type = to_int(key[0]);
	switch(type)
	{
	case 10:
		if (hour<12) return;
		if (me->get_save_2("plant1.city") && me->get_save_2("plant1.city")!=who->get_city_name())
		{
			result = sprintf("%s：\n    你既然已经找了%s的农夫帮你生产农产品，那么我就无法再插手帮你了，你还是下次农时再来找我吧。\n", who->get_name(), me->get_save_2("plant1.city") );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}
		if (me->get_save_2("plant1.count")>0 && me->get_save_2("plant2.count")>0)
		{
			result = sprintf("%s：\n    现在我的农场里面都已经是满满的了，想要再多种其他的农产品看来是不可能了。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}
		if ( (me->get_save_2("plant1.count")>0 && me->get_save_2("plant1.day")!=day ) || (me->get_save_2("plant2.count")>0 && me->get_save_2("plant2.day")!=day ) )
		{
			result = sprintf("%s：\n    你还有些农产品在我的仓库还没领取，我劝你还是尽快把这些农产品拿走吧！不然等到了时间这些农产品都会坏掉的。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}		
		result = sprintf("%s：\n    我生产出来的农产品是最好的，你找我替你生产农产品肯定是找对人了，你想要我帮你生产些什么农产品？\n", who->get_name() );
		result += sprintf( ESC "地瓜\ntalk %x# welcome.220\n", getoid(who) );
		result += sprintf( ESC "小米\ntalk %x# welcome.145\n", getoid(who) );
		result += sprintf( ESC "玉米\ntalk %x# welcome.144\n", getoid(who) );
		result += sprintf( ESC "鸡蛋\ntalk %x# welcome.171\n", getoid(who) );
		if (level>=45)
			result += sprintf( ESC "牛肉\ntalk %x# welcome.181\n", getoid(who) );
		if (level>=50)
			result += sprintf( ESC "南瓜\ntalk %x# welcome.148\n", getoid(who) );
		if (level>=60)
			result += sprintf( ESC "高粱\ntalk %x# welcome.146\n", getoid(who) );
		if (level>=65)
			result += sprintf( ESC "鱼\ntalk %x# welcome.187\n", getoid(who) );							
		result += ESC "离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 20:
	case 21:
		if (me->get_save_2("plant1.city")==0 || me->get_save_2("plant1.city") && me->get_save_2("plant1.city")!=who->get_city_name())
		{
			result = sprintf("%s：\n    我没有什么收成可以给你的，你又没有委托我种什么或养什么。我看你肯定是让其他国家的农夫把你的农产品给搞坏了吧？我早说过要找我的了。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}	
		if (me->get_save_2("plant2.day")>0 && me->get_save_2("plant2.day")<day-1 )
		{
			me->delete_save_2("plant2");
		}
		if (me->get_save_2("plant1.day")>0 && me->get_save_2("plant1.day")<day-1 )
		{
			me->delete_save_2("plant1");
			if (me->get_save_2("plant2.day")) me->set_save_2("plant1.city", who->get_city_name());
		}		
		if ( me->get_save_2("plant1.day")>day+10) me->set_save_2("plant1.day", day-1);
		if ( me->get_save_2("plant2.day")>day+10) me->set_save_2("plant2.day", day-1);
		if ( ( me->get_save_2("plant1.day")==0 || me->get_save_2("plant1.day")>=day ) && ( me->get_save_2("plant2.day")==0 || me->get_save_2("plant2.day")>=day ) )
		{
			result = sprintf("%s：\n    还没有到收成的时候呢。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}			
		if (day>plant->get_day())
		{
			result = sprintf("%s：\n    还没有到收成的时候呢。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}				
		flag = plant->get_save(who->get_city_name());	
		if (flag!=0 && type==20)
		{
			switch(flag)
			{
			case -90:
				result = sprintf("%s：\n    由于最近的天灾人祸，我国受到了台风的袭击，现在你的收成就只剩下这些了。\n", who->get_name() );
				break;
			case -50:
				result = sprintf("%s：\n    由于最近的天灾人祸，我国受到了水灾的袭击，现在你的收成就只剩下这些了。\n", who->get_name() );
				break;
			case 50:
				result = sprintf("%s：\n    由于我的辛勤耕耘，最近我国风调雨顺，所以你也可以领取到更多的农产品了。\n", who->get_name() );
				break;
			case 100:
			default:
				result = sprintf("%s：\n    由于我的辛勤耕耘，最近我国大丰收，所以你也可以领取到更多的农产品了。\n", who->get_name() );
				break;
			}
			result += sprintf( ESC "领取收成\ntalk %x# welcome.21\n", getoid(who) );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}		
		// 检查身上的位置够不够	
		count = 0;	
		inv = 0;
		if (me->get_save_2("plant1.day")+1==plant->get_day())
		{
			count = me->get_save_2("plant1.count") * (100 + flag)/100;
			if ((count/30)*30==count) inv += count/30;
			else inv += (count/30+1);
		}
		if (me->get_save_2("plant2.day")+1==plant->get_day())
		{
			count = me->get_save_2("plant2.count") * (100 + flag)/100;			
			if ((count/30)*30==count) inv += count/30;
			else inv += (count/30+1);			
		}
		if( sizeof_inventory(me, 1, MAX_CARRY) > MAX_CARRY - inv )
		{
			result = sprintf("%s：\n    你身上放这么多杂七杂八的东西怎么可以把你的收成拿走啊？去放下一些东西再回来拿吧，你需要%d个空格才可以放你的所有收成。\n", who->get_name(), inv );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;					
		}			
		if (me->get_save_2("plant2.day")+1==plant->get_day())
		{
			type = me->get_save_2("plant2.type");
			count = me->get_save_2("plant2.count");
			count = count * (100 + flag)/100;
			flag = plant->get_save(who->get_city_name());
			
			me->delete_save_2("plant2");
			for (i=0;i<count/30;i++)
			{
				obj = new (sprintf("/item/stuff/%04d", type));
				if (!obj) continue;
				obj->set_amount(30);
                                p =obj->move(me, -1);
                                obj->add_to_user(p);				
			}
			if ((count/30)*30!=count)
			{
				obj = new (sprintf("/item/stuff/%04d", type));
				if (!obj) return;
				obj->set_amount(count - (count/30)*30);
                                p =obj->move(me, -1);
                                obj->add_to_user(p);				
			}			
		}		
		if (me->get_save_2("plant1.day")+1==plant->get_day())
		{
			type = me->get_save_2("plant1.type");
			count = me->get_save_2("plant1.count");
			// 判断是否同一天						
			count = count * (100 + flag)/100;			
			me->delete_save_2("plant1");
			if (me->get_save_2("plant2.day")) me->set_save_2("plant1.city", who->get_city_name());
			for (i=0;i<count/30;i++)
			{
				obj = new (sprintf("/item/stuff/%04d", type));
				if (!obj) continue;
				obj->set_amount(30);
                                p =obj->move(me, -1);
                                obj->add_to_user(p);				
			}
			if ((count/30)*30!=count)
			{
				obj = new (sprintf("/item/stuff/%04d", type));
				if (!obj) return;
				obj->set_amount(count - (count/30)*30);
                                p =obj->move(me, -1);
                                obj->add_to_user(p);				
			}			
		}
		result = sprintf("%s：\n    领取收成成功。\n", who->get_name() );
		result += ESC "离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);		
		break;
	case 30:
		if (me->get_save_2("plant2.day")>0 && me->get_save_2("plant2.day")<day-1 )
		{
			me->delete_save_2("plant2");
		}
		if (me->get_save_2("plant1.day")>0 && me->get_save_2("plant1.day")<day-1 )
		{
			me->delete_save_2("plant1");
			if (me->get_save_2("plant2.day")) me->set_save_2("plant1.city", who->get_city_name());
		}	
		if (me->get_save_2("plant1.city")==0 )
		{
			result = sprintf("%s：\n    你现在没有在任何地方种植过任何农产品。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;				
		}
		if ( me->get_save_2("plant1.city")!=who->get_city_name())
		{
			result2 = "";
			if (me->get_save_2("plant1.day"))
			{
				type = me->get_save_2("plant1.type");
				count = me->get_save_2("plant1.count");	
				file = sprintf("/item/stuff/%04d", type);			
				result2 = sprintf("%d个%s", count, file->get_name());
			}
			if (me->get_save_2("plant2.day"))
			{
				type = me->get_save_2("plant2.type");
				count = me->get_save_2("plant2.count");	
				file = sprintf("/item/stuff/%04d", type);			
				if (result2=="")
					result2 = sprintf("%d个%s", count, file->get_name());
				else
					result2 = sprintf("和%d个%s", count, file->get_name());
			}			
			result = sprintf("%s：\n    听说你在%s农夫那里种了%s了？这个我是知道的，告诉你，这是个阴谋，他不会给你收成到什么的。\n", who->get_name(), me->get_save_2("plant1.city"), result2 );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}	
		result = sprintf("%s：\n    您的种植情况如下：\n", who->get_name() );
		if (me->get_save_2("plant1.day"))
		{
			type = me->get_save_2("plant1.type");
			count = me->get_save_2("plant1.count");	
			file = sprintf("/item/stuff/%04d", type);
			result += sprintf("    %s%d个，收获时间：", file->get_name(), count);
			if (hour>=12 && me->get_save_2("plant1.day")==plant->get_day())
				result += ("明天中午十二点至后天中午十二点\n");			
			else	
				result += ("中午十二点至明天中午十二点\n");
		}
		if (me->get_save_2("plant2.day"))
		{
			type = me->get_save_2("plant2.type");
			count = me->get_save_2("plant2.count");	
			file = sprintf("/item/stuff/%04d", type);
			result += sprintf("    %s%d个，收获时间：", file->get_name(), count);
			if (hour>=12 && me->get_save_2("plant2.day")==plant->get_day())
				result += ("明天中午十二点至后天中午十二点\n");			
			else	
				result += ("中午十二点至明天中午十二点\n");
		}		
		result += ESC "离开\nCLOSE\n";
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;	
	case 40:
		if (!is_god(me)) return;	
		if (me->get_save_2("plant1.day"))		
			me->set_save_2("plant1.day", plant->get_day()-1);	
		if (me->get_save_2("plant2.day"))
			me->set_save_2("plant2.day", plant->get_day()-1);			
		break;
	case 50:
		if (!is_god(me)) return;
		"/sys/user/plant"->reset_plant();
		break;
	case 220:
	case 145:
	case 144:
	case 171:
	case 181:
	case 148:
	case 146:
	case 187:	
		if (hour<12) return;
		if (me->get_save_2("plant1.city") && me->get_save_2("plant1.city")!=who->get_city_name())
		{
			result = sprintf("%s：\n    你既然已经找了%s的农夫帮你生产农产品，那么我就无法再插手帮你了，你还是下次农时再来找我吧。\n", who->get_name(), me->get_save_2("plant1.city") );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}	
		if ( me->get_save_2("plant1.count")>0 && me->get_save_2("plant2.count")>0  )
		{
			result = sprintf("%s：\n    现在我的农场里面都已经是满满的了，想要再多种其他的农产品看来是不可能了。\n", who->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}	
		file = sprintf("/item/stuff/%04d", type);		
		if ( me->get_save_2("plant1.type")==type || me->get_save_2("plant2.type")==type  )
		{
			result = sprintf("%s：\n    你想要的%s我已经在帮你生产了，你不需要再生产这个农产品了。\n", who->get_name(), file->get_name() );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}		
		if (me->get_level()<file->get("plant"))
		{
			return;
		}	
		if (sizeof(key)==1)
		{
			result = sprintf("%s：\n    我的一块农地能生产出90份的%s，你要生产多少分量的%s？\n", who->get_name(), file->get_name(), file->get_name() );
			result += sprintf( ESC "30\ntalk %x# welcome.%d 30\n", getoid(who), type );
			result += sprintf( ESC "60\ntalk %x# welcome.%d 60\n", getoid(who), type );
			result += sprintf( ESC "90\ntalk %x# welcome.%d 90\n", getoid(who), type );
			result += ESC "离开\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;
		}
		count = to_int(key[1]);
		if (sizeof(key)==2)
		{			
			result = sprintf("%s：\n    你要生产%d份%s的话，需要的费用一共是%d金，你真的要生产吗？\n", who->get_name(), count, file->get_name(), count* file->get("pvalue") );
			result += sprintf( ESC "好吧，生产\ntalk %x# welcome.%d %d !\n", getoid(who), type, count );
			result += ESC "这么贵？会不会算帐呀！\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
			return;			
		}
		if (sizeof(key)==3)
		{
			price = count * file->get("pvalue");
			if (me->get_cash()<price)
			{
				result = sprintf("%s：\n    原来你钱不够啊？看来你比我还穷，你还是先去凑够钱再来找我吧！\n", who->get_name() );
				result += ESC "离开\nCLOSE\n";
				send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
				return;
			}
			me->add_cash(-price);
			me->add_gold_log("plant", price);
                	me->log_money("种植", -price);
                	"/sys/sys/count"->add_use("种植", price);
                	me->set_save_2("plant1.city", who->get_city_name());
                	if (me->get_save_2("plant1.count")==0)
                	{
                		me->set_save_2("plant1.type", type);
                		me->set_save_2("plant1.count", count);
                		me->set_save_2("plant1.day", day);
                	}
                	else
                	{
                		me->set_save_2("plant2.type", type);
                		me->set_save_2("plant2.count", count);
                		me->set_save_2("plant2.day", day);
                	}                	
			result = sprintf("%s：\n    你一定要记得明天回来取你的农产品啊！不然那些成品会坏掉的。\n", who->get_name() );
			result += ESC "确定\nCLOSE\n";
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
                	
		}
		break;
	}
}
