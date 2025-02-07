
#include <ansi.h>
#include <cmd.h>
#include <music.h>
#include <task.h>
#include <time.h>
#include <equip.h>
inherit DBASE_F;
inherit SAVE_F;
static mapping npc_num = ([
	0:({"韩国","赵木","220,176",}),
	1:({"秦国","马显","231,148",}),
	2:({"魏国","程林开","106,146",}),
	3:({"赵国","李防","214,239",}),	
		]);
int num;//第几期
static string *cityname = ({ "齐国", "楚国", "秦国", "燕国", "赵国", "魏国", "韩国", });
int iStart1,iFinish1,iFinish2,iFinish3,iFlag;
int iGame;
// 函数：生成二进制码
void SAVE_BINARY() { }
string get_save_file()	{ return "data/yunbiao"SAVE_EXTENSION;}

void do_task_start( object who, object me,string arg );
void do_task_finish( object who, object me );
void do_task_cancel( object who, object me );
void clear_task_desc(object who);
void send_task_list(object who);

// 函数：构造处理
void create() 
{ 
	restore();
	call_out("check_time",3);
}
// 函数：对话处理(镖头)
void do_look( object who, object me )
{
        int id = getoid(me),iTime;
        string cmd1 = sprintf( "talk %x# tasklist\n", id );
	string tmp="";
	iTime = time();
//	if ( who->get_legend(TASK_NEWBIE_00, 13) && !who->get_legend(TASK_NEWBIE_00, 14) )
//		tmp = ESC HIY "找我谈谈。\n" + sprintf( "talk %x# welcome.1\n", id );
	if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
		tmp = ESC HIY "一探虚实。\n" + sprintf( "talk %x# welcome.3\n", id );
	if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
		tmp = ESC HIY "找我谈谈。\n" + sprintf( "talk %x# welcome.5\n", id );
	if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
		tmp = ESC HIY "拜访左丘明。\n" + sprintf( "talk %x# welcome.7\n", id );
	tmp += ESC HIG "镖王争霸战\n" + sprintf( "talk %x# welcome.11\n", id );
	if ( iTime > iFinish1 && iTime < iFinish3 )
		tmp += ESC HIG "领取镖王奖励\n" + sprintf( "talk %x# welcome.13\n", id );

	send_user( who, "%c%s", ':', me->get_name() + "：\n    近期由于局面混乱，镖局的生意大好。现在人手都不是很充足了。想招几个人来帮忙，可是总遇不上合适的人选，恩，你来找我有什么事？如果你的等级已经达到30级以上，我可以将押镖的任务委托予你。\n" 
			+ tmp +
                        ESC "领取保镖任务\n" + cmd1 +
                        ESC "离开\nCLOSE\n" );
}

// 变量：随机对话
static string *TalkTable = ({ 
        "这年头兵荒马乱的，想找个合适的保镖都不容易……",
        "想找京都镖局护送一批货物，可是他老人家竟然没空……",
        "想找京都镖局护送亲友返乡，可是他老人家竟然没空……",
        "周国的京都镖局尉迟老镖头武艺高强，生性豪爽，真是一条好汉！",
});

static int sizeof_talk = sizeof(TalkTable);

// 函数：对话处理(客户)
void do_look_2( object who, object me )
{
	int id;
	string result;
        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长完成
        &&      who->get_quest("escort.name") == me->get_name() 
        && 	who->get_quest("escort.city")+"国" == me->get_city_name() )    // 找对人了
        {
        	if ( who->get("escort.finish") == 0 )
        	{
        		who->set("escort.finish",1);
        		if ( who->get_quest("escort.flag") == 1 )
        			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s\n    尉迟老镖头说托付了一个热心的人来运这个东西给我，我还担心着呢，不知道你能力如何，你却这么快就安全的送到了，尉迟老镖头看上的人果然不错呀！\n"ESC"完成任务\nlook %x#\n",me->get_name(),id=getoid(me)));
        		else
        			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s\n    一路可安好？让你费心了吧！谢谢你把他安全的送到，我十分感激，这样吧，这点小小意思，不成敬意，但也是我的一份心意，收下吧！\n"ESC"完成任务\nlook %x#\n",me->get_name(),id=getoid(me)));
        	}
        	else
        	{
        		who->delete("escort.finish");
			do_task_finish(who, me);  
		}	
		return;
        }
	result = sprintf( "%s：\n%s\n", me->get_name(), TalkTable[ random(sizeof_talk) ] );
	if (me->is_seller())
		result += sprintf(ESC"购买道具\nlist %x#\n", getoid(me));
	result += ESC"离开\n";
        send_user( who, "%c%s", ':', result );
}

//int check_level(object who, object me,int level)
//{
//	int i,size;
//	object *team;
//	
//	if( !arrayp( team = who->get_team() ) || !who->is_leader() )
//        	return 1;
//	for(i=0,size=sizeof(team);i<size;i++)
//	{
//		if ( team[i]->get_level() < level )
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+sprintf(":\n    不行不行，你的队友等级好像还不足%d级，我无法将押镖的任务委托予你。",level));
//			return 0;
//		}
//	}
//	return 1;	
//}
int check_level(object who, object me,int level)
{

	if ( who->get_level() < level )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+sprintf(":\n    不行不行，你等级还不足%d级，我无法将押镖的任务委托予你。",level));
		return 0;
	}
	return 1;	
}
int check_before_quest(object who,object me,int flag,int gold)
{
//	object *team;
	int size,i;
	
        if( who->get_quest("escort.baiwang") )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    你好像已经接受了本届小超人杯镖王争霸战的护送任务吧？还在这干嘛，还不快去！。\n"ESC"离开"  );
                return 0;
        }
	if( who->get_quest("escort.flag") )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    你怎么还在这，还不快去？！年轻人做事要负责任，别耽误了人家，也别砸了我的名声！\n    如果实在找不到委托的目的地，你大可去找当地的守卫问问，他们会告诉你准确的方位。\n"ESC"离开"  );
                return 0;
        }
//        if( arrayp( team = who->get_team() ) && !who->is_leader() )
//        {
////                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    交了这么多的押金，你能担得起这个重担，负得起这个责吗？还是叫个能负责的人来吧！\n"ESC"离开"  );
//                return 0;
//        }
//        if( ( size = sizeof(team) ) > 2 )
//        {
//                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    你们这么多人，到时候奖励可能会分不平均，引起意见，还是人少点了再来找我。\n"ESC"离开"  );
//                return 0;
//        }
        if( who->get_cash() < gold )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    唉，不是我不想把任务交给你，但是就这点钱实在不能给我什么保证，万一你把镖弄丢了呢？我拿什么赔偿？\n"ESC"离开" );
                return 0;
        }
	if ( flag && gone_time(who->get_quest("escort.quest")) < 210 )
	{
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name()+":\n    运镖这事可不是什么人都能做的，不光要武艺高强，还得有过人的胆识，本来想给你个机会，可惜你不珍惜，只好等下次了。\n"ESC"离开" );
                return 0;
        }	
        return 1;
}
//接受任务
void accept_task( object who, object me )
{
        object *team, npc, item;
        string name, city,npcname;
        int z, x0, y0, x1, y1, p, size, flag,x,y,gold,level;

	gold = who->get("escort.gold");
	level = who->get("escort.level");
	who->delete("escort.gold");
	who->delete("escort.level");
	if ( !gold )
		return ;
	if ( check_before_quest(who,me,0,gold) != 1 )
		return ;
	if ( check_level(who,me,level) != 1 )
		return ;
        team = who->get_team(); 
      	size = sizeof(team);
 	flag = who->get("escort.flag");
 	name = who->get("escort.name");
 	city = who->get("escort.tcity");
 	x = who->get("escort.x");
 	y = who->get("escort.y");
 	if ( flag == 0 || !stringp(name) || !stringp(city) )
 		return ;
   
        switch( flag)
        {
	default : if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
                {
                        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n    你身上的东西那么多，估计没有一个安全的地方能放下这个贵重物品，想想还是不交给你吧。等你能放下这个物品了，你再来找我。");
                        return;
                }
                
                item = new( "/item/std/8100" );
                if( p = item->move(who, -1) ) item->add_to_user(p);

                flag = 1;
                who->add_cash( -gold );  who->add_gold_log( "biao", -gold );
                who->log_money("运镖", - gold);                
                "/sys/sys/count"->add_use("biao", gold);
                who->set_quest("escort.escort", item->get_name() );
                break;

	case 2 : npc = new( "/npc/task/8100" );
                npc->set_name( name + npc->get_name()+sprintf("(%d)", who->get_number()) );
                npc->set_walk_speed(3);
		npcname = npc->get_name();
                z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
                if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
                {
                        x1 = p / 1000;  y1 = p % 1000;
                        npc->add_to_scene( z, x1, y1, get_front_xy(x1, y1, x0, y0) );
                        npc->set_owner(who);
                        who->to_front_xy(x1, y1);
                }

                flag = 2;
                who->add_cash( -gold );  who->add_gold_log( "biao", -gold );
                who->log_money("运镖", - gold);                
                "/sys/sys/count"->add_use("biao", gold);
                who->set_quest("escort.escort", sprintf( "%x#", getoid(npc) ) );
                who->set_quest("escort.npc", npc);
                break;
        }

        who->delete_quest("escort.id");
        who->delete_quest("escort.member");
	who->set_quest("escort.leader", 1);
	who->set_quest("escort.city",city);
        who->set_quest("escort.name", name);
        who->set_quest("escort.time", time() );
        who->set_quest("escort.flag", flag);
        who->set_quest("escort.x", x);
        who->set_quest("escort.y", y);
        who->set_quest("escort.gold", gold);
        if ( stringp(npcname) ) who->set_quest("escort.npcname",npcname);

        who->delete_quest("escort.random");    // 记录随机事件
        who->delete_quest("escort.robber");
        who->delete_quest("escort.robber#");
	send_task_list(who);

//	//询问队友是否加入
//        if( size == 2 && inside_screen_2( team[0], team[1] ) )    // 组队完成
//        {
//        	team -= ({who});
//        	team[0]->set("escort.join",who->get_number());
//        	team[0]->set("escort.time",who->get_quest("escort.time"));
//        	send_user(team[0],"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s\n    %s已经接受了运镖任务，你是否一同协助？\n"ESC"接受\ntalk %x# join\n"ESC"取消",me->get_name(),who->get_name(),getoid(me)));
//        }

}
//加入任务
void join_task(object who,object npc)
{
	int size;
	string id;
	object *team,leader;

	if ( who->get_quest("escort.flag" ) || who->is_leader())
		return ;
	team = who->get_team(); 
	if( (size=sizeof(team))<2  || gone_time( who->get("escort.time") ) > 2400  )
		return ;
	id = who->get_leader();
	leader = find_player(id);
	if ( !objectp(leader) || !inside_screen_2(who,leader) || who->get("escort.join") != leader->get_number() || who->get("escort.time") != leader->get_quest("escort.time") )
		return ;	
	who->delete("escort.join");
	who->delete("escort.time");
	who->delete_quest("escort.leader");
	who->set_quest("escort.city",leader->get_quest("escort.city"));
        who->set_quest("escort.name",leader->get_quest("escort.name"));
        who->set_quest("escort.time", leader->get_quest("escort.time") );
        who->set_quest("escort.flag", leader->get_quest("escort.flag"));
        who->set_quest("escort.x", leader->get_quest("escort.x"));
        who->set_quest("escort.y", leader->get_quest("escort.y"));
        who->set_quest("escort.npcname",leader->get_quest("escort.npcname"));

        who->delete_quest("escort.random");    // 记录随机事件
        who->delete_quest("escort.robber");
        who->delete_quest("escort.robber#");
	send_task_list(who);
	
	who->set_quest("escort.id", leader->get_number() );
	who->set_quest("escort.member", leader->get_name() );
	leader->set_quest("escort.id", who->get_number() );
	leader->set_quest("escort.member", who->get_name() );	
}
// 函数：开始任务
void do_task_start( object who, object me,string arg )
{
        object map,*team, item;
        string name, result, city;
        int z, x, y, p, size,gold,flag,level;
	
	if ( !stringp(arg) )
		return ;
	if ( who->get_legend(TASK_49,13) && !who->get_legend(TASK_49,14) )
	{
		send_user(who,"%c%s",'!',"你正在试运镖呢");
		return;
	}
	flag = to_int(arg);
	switch(flag)
	{
		case 1:
			gold = 60000;
			level = 30;
			break;
		case 2:
			gold = 80000;
			level = 50;
			break;		
		case 3:
			gold = 100000;
			level = 70;
			break;
		default:
			return;
	}
	if ( check_before_quest(who,me,1,gold) != 1 )
		return ;		
	if ( check_level(who,me,level) != 1 )
		return ;
        name = QUEST_ESCORT->get_quest();

        switch( random(2) )
        {
      	default :
      		p = QUEST_ESCORT->get_xy_point(name);
      		city = cityname[random(sizeof(cityname))];
      		z = p / 1000000;
      		x= ( p % 1000000 ) / 1000  ;
      		y= ( p % 1000000 ) % 1000  ;
      		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;  
      		result = sprintf("%s:\n    近期由于局面混乱，镖局的生意大好。现在人手都不是很充足了。想招几个人来帮忙，可是总遇不上合适的人选，既然你愿意帮这个忙，那我就把这个重任托付给你了。\n    前些日子%s的大官员托我把这箱银子运送至%s处，我实在是没空，你去吧，到时候我会给你报酬的！%s就在"HIR"%s国(%d,%d)"NOR"处。\n    但是，你要知道的是，在运镖过程中是不能使用驿站或道具法术等传送功能，否则你的任务就会失败，切记切记！\n",me->get_name(),city,name,name,map->get_name(),x,y);
      		who->set("escort.name",name);
      		who->set("escort.scity",city);
      		who->set("escort.tcity",map->get_name());
      		who->set("escort.flag",1);
      		break;
      	case 1 : 
      		p = QUEST_ESCORT->get_xy_point(name);
      		z = p / 1000000;
      		x= ( p % 1000000 ) / 1000  ;
      		y= ( p % 1000000 ) % 1000  ;
      		if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;  
      		result = sprintf("%s:\n    近期由于局面混乱，镖局的生意大好。现在人手都不是很充足了。想招几个人来帮忙，可是总遇不上合适的人选，既然你愿意帮这个忙，那我就把这个重任托付给你了。\n    这里有位客人看望他的亲友%s，可是路途遥远而且险恶，他身无武艺，不敢一个人独自上路，所以请你做保镖护送。%s就在%s国(%d,%d)处。\n    但是，你要知道的是，在运镖过程中是不能使用驿站或道具法术等传送功能，否则你的任务就会失败，切记切记！\n",me->get_name(),name,name,map->get_name(),x,y);
      		who->set("escort.name",name);
      		who->set("escort.flag",2);
      		who->set("escort.tcity",map->get_name());
      		who->set("escort.x",x);
      		who->set("escort.y",y);
      		break;   

        }
        who->set_quest("escort.quest",time());
        who->set("escort.gold",gold);
        who->set("escort.level",level);
	result += sprintf(ESC"接受\ntalk %x# accept\n",getoid(me));
	item = who->get_equip(HAND_TYPE);
	if (item && item->get_item_number()==10001078)
		result += sprintf(ESC"离开\ntalk %x# welcome.cancel\n", getoid(me));	
	else
		result += ESC"离开";
 	send_user(who, "%c%c%w%s", ':',3, me->get_char_picid(),result); 
}
//清除任务变量
void clear_task(object who)
{
        who->delete_quest("escort.flag");
        who->delete_quest("escort.leader");
        who->delete_quest("escort.time");
        who->delete_quest("escort.name");
        who->delete_quest("escort.escort");
        who->delete_quest("escort.npc");
        who->delete_quest("escort.npcname");
        who->delete_quest("escort.x");
        who->delete_quest("escort.y");
        who->delete_quest("escort.gold");
        
        who->delete_quest("escort.id");
        who->delete_quest("escort.member");

        who->delete_quest("escort.random");
        who->delete_quest("escort.robber");
        who->delete_quest("escort.robber#");	
	who->delete_quest("escort.biaowang");
}
// 函数：结束任务
void do_task_finish( object who, object me )
{
        object member, npc, item;
        string name, file;
        int id, p, gold, exp, flag,escortgold;

        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长完成
        &&      who->get_quest("escort.name") == me->get_name() 
        && 	who->get_quest("escort.city")+"国" == me->get_city_name() )    // 找对人了
        {
		escortgold = who->get_quest("escort.gold");
                switch( who->get_quest("escort.flag") )
                {
              default : 
			if( objectp( npc = who->get_quest("escort.robber#") )    // 寻找蒙面人
				&&  npc->is_escort_robber() )
			{
				notify(npc->get_name()+"出现，您不能完成任务。");
                		return ;
			}
              		flag = 1;
                        name = who->get_quest("escort.escort");
                        if( !( item = present("贵重物品", who, 1, MAX_CARRY*4) ) )
                        {
                                send_user( who, "%c%s", '!', "您护送的东西呢？！" );
                                return;
                        }
                        item->remove_from_user();
                        destruct(item);
                        break;

               case 2 : flag = 2;
                        name = who->get_quest("escort.escort");
                        if( npc = find_char(name) )
                        {
                                if( !inside_screen_2(me, npc) )
                                {
                                        send_user( who, "%c%s", '!', "您护送的人呢？！" );
                                        return;
                                }
                                npc->remove_from_scene();
                                destruct(npc);
                        }
                        else
  			{
                                send_user( who, "%c%s", '!', "您护送的人呢？！" );
                                return;
			}	
                        break;
                }

                if(     flag == 1    // 护送物品
                &&      gone_time( who->get_quest("escort.time") ) > 2400 )    // 超过 40 分钟
                        flag = 0;

                if(   ( id = who->get_quest("escort.id") )
                &&    ( member = find_player( sprintf("%d", id) ) )
                &&      inside_screen_2(me, member) && member->get_quest("escort.time")==who->get_quest("escort.time"))    // 组队完成
                {
			clear_task(who);
                        send_user( who, "%c%c%d%w%w", 0x54, 12, getoid(who), -1, -1 );    // 借用 getoid(who)
                        who->set_task_xy(0);    // 清除任务坐标
			clear_task_desc(who);
                        if( flag )
                        {
                                gold = escortgold+escortgold*2/5* who->get_online_rate() / 100; 
                                who->add_cash(gold);  who->add_gold_log("biao", gold);
                                exp = 500;  
                                exp = exp * who->get_online_rate() / 100;
                                who->add_exp(exp);

                                who->add_log("$escort", gold - escortgold);
                                who->add_log("&escort", exp);
                                who->add_log("#escort", 1);
                        }
                        else
                        {
                                gold = escortgold;  who->add_cash(gold);  who->add_gold_log("biao", gold);
                                exp = 0;  // who->add_exp(exp);
                        }
                        "/sys/sys/count"->add_income("biao", gold);
                        who->log_money("运镖", gold);                
                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                        send_user(who,"%c%s",';',sprintf("您参与完成运镖任务，金钱 %+d, 经验 %+d。", gold, exp ));

			clear_task(member);
                        send_user( member, "%c%c%d%w%w", 0x54, 12, getoid(member), -1, -1 );    // 借用 getoid(member)
                        member->set_task_xy(0);    // 清除任务坐标
			clear_task_desc(member);
                        if( flag )
                        {
                                gold = escortgold*2/5* member->get_online_rate() / 100;  member->add_cash(gold);  member->add_gold_log("biao", gold);
                                exp = 500* member->get_online_rate() / 100;  member->add_exp(exp);

                                member->add_log("$escort", gold);
                                member->add_log("&escort", exp);
                                member->add_log("#escort", 1);
                                who->log_money("运镖", gold);                
                                "/sys/sys/count"->add_income("biao", gold);
                        }
                        else
                        {
                                gold = 0;  // member->add_cash(gold);  member->add_gold_log("biao", gold);
                                exp = 0;  // member->add_exp(exp);
                        }
                        send_user( member, "%c%w", 0x0d, MUSIC_TASK );
                        send_user(member,"%c%s",';',sprintf("您参与完成运镖任务，金钱 %+d, 经验 %+d。", gold, exp ));

                }
                else    // 独自完成
                {
			clear_task(who);

                        send_user( who, "%c%c%d%w%w", 0x54, 12, getoid(who), -1, -1 );    // 借用 getoid(who)
                        who->set_task_xy(0);    // 清除任务坐标
			clear_task_desc(who);
                        if( flag )
                        {
                                gold = escortgold+escortgold/2* who->get_online_rate() / 100;  who->add_cash(gold);  who->add_gold_log("biao", gold);
                                exp = 500* who->get_online_rate() / 100;  who->add_exp(exp);

                                who->add_log("$escort", gold - escortgold);
                                who->add_log("&escort", exp);
                                who->add_log("#escort", 1);
                        }
                        else
                        {
                                gold = escortgold;  who->add_cash(gold);  who->add_gold_log("biao", gold);
                                exp = 0;  // who->add_exp(exp);
                        }
                        who->log_money("运镖", gold);                
                        "/sys/sys/count"->add_income("biao", gold);
                        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
                        send_user(who,"%c%s",';',sprintf("您完成运镖任务，金钱 %+d, 经验 %+d。", gold, exp ));

                }
                "/sys/sys/count"->add_task("运镖", 1);
                SAY_CMD->say(who, "#80");                
        }
}

// 函数：取消任务
void do_task_cancel( object who, object me )
{
        object npc, item;
        int gold;
        
	who->delete("tasklist");
        if( who->get_quest("escort.flag") )    // 运镖任务
        {
                if( gone_time( who->get_quest("escort.time") ) < 180 )
                {
                        send_user( who, "%c%s", '!', "３分钟后才能取消运镖任务。" );
                        return;
                }

                if( who->get_quest("escort.leader") == 1 )    // 队长取消
                {
                        while( item = present("贵重物品", who, 1, MAX_CARRY*4) )
                        {
                                item->remove_from_user();
                                destruct(item);
                        }
                        if( npc = find_char( who->get_quest("escort.escort") ) )
                        {
                                npc->remove_from_scene();
                                destruct(npc);
                        }

                        who->delete_quest("escort.flag");
                        who->delete_quest("escort.leader");
                        who->delete_quest("escort.time");
                        who->delete_quest("escort.name");
                        who->delete_quest("escort.escort");
                        who->delete_quest("escort.npc");

                        who->delete_quest("escort.id");
                        who->delete_quest("escort.member");

                        who->delete_quest("escort.random");
                        who->delete_quest("escort.robber");
                        who->delete_quest("escort.robber#");

                        gold = 75000;  who->add_cash(gold);  who->add_gold_log("biao", gold);
                        who->log_money("运镖", gold);                
                        write_user(who, ECHO "您取消运镖任务，领回 %d 金。", gold);
                        "/sys/sys/count"->add_income("biao", gold);

                        who->add_log("$escort2", gold - 100000);
                     // who->add_log("&escort2", exp);
                        who->add_log("#escort2", 1);
                }
                else    // 队员取消
                {
                        who->delete_quest("escort.flag");
                        who->delete_quest("escort.leader");
                        who->delete_quest("escort.time");
                        who->delete_quest("escort.name");
                        who->delete_quest("escort.escort");
                        who->delete_quest("escort.npc");

                        who->delete_quest("escort.id");
                        who->delete_quest("escort.member");

                        who->delete_quest("escort.random");
                        who->delete_quest("escort.robber");
                        who->delete_quest("escort.robber#");

                        write_user(who, ECHO "您取消运镖任务。");
                }
        }
}

void task_giveup(object who)
{
        object npc, item;
        int gold;

        if( who->get_quest("escort.flag") )    // 运镖任务
        {
                if( gone_time( who->get_quest("escort.time") ) < 180 )
                {
			item = who->get_equip(HAND_TYPE);
			if (item && item->get_item_number()==10001078)
			{
	                        send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
	                        	ESC "%c\n"ESC"use %x# escort\n"
	                                , 1, getoid(item) ) );			
				return;
			}                	
                        send_user( who, "%c%s", '!', "３分钟后才能取消运镖任务。" );
                        return;
                }

                if( who->get_quest("escort.leader") == 1 )    // 队长取消
                {
                        while( item = present("贵重物品", who, 1, MAX_CARRY*4) )
                        {
                                item->remove_from_user();
                                destruct(item);
                        }
                        if( npc = find_char( who->get_quest("escort.escort") ) )
                        {
                                npc->remove_from_scene();
                                destruct(npc);
                        }

                        gold = who->get_quest("escort.gold")*3/4;  who->add_cash(gold);  who->add_gold_log("biao", gold);
                        who->log_money("运镖", gold);                
                        write_user(who, ECHO "您放弃运镖任务，领回 %d 金。", gold);
                        "/sys/sys/count"->add_income("biao", gold);

                        who->add_log("$escort2", gold - who->get_quest("escort.gold"));
                        who->add_log("#escort2", 1);
                        
                }
                else    // 队员取消
                {
                        send_user(who,"%c%s",';',"你已经放弃了这次运镖任务，但是你可以协助你的队友继续完成该项任务。");
                }                 
		clear_task(who);
                clear_task_desc(who);
        }
}

void send_task_list(object who)
{
	int iFlag;
	
        if( iFlag = who->get_quest("escort.flag") )
        {
                if( iFlag == 1 )    // 1. 运镖任务(物品)
                {
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ESCORT,"运镖任务" ); 
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,1,"护送镖银" ); 
                             
                }
                else if( iFlag == 2 )    // 2. 运镖任务(人物)
                {
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ESCORT,"运镖任务" ); 
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,2,"护送要员" );                                       
                }
                else if( iFlag == 3 )    // 镖王争霸战
                {
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ESCORT,"运镖任务" ); 
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,3,"镖王争霸战" );                                       
                }
        }	
}

void clear_task_desc(object who)
{		
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,1,TID_ESCORT,"" );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_ESCORT,"" ); 	
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,1,"" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,2,"" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,3,"" ); 
}
//队员脱离队伍取消任务;队长脱离队伍,队员取消任务
void team_giveup(object who)
{
	object member;
	if ( !who->get_quest("escort.flag") )
		return ;
	if( who->get_quest("escort.leader") == 1 )
	{
		member = find_player(sprintf("%d",who->get_quest("escort.id")));
		if ( objectp(member) )
		{
			clear_task(member);
			clear_task_desc(member);
			send_user(member,"%c%s",';',"由于队长离开队伍，你的运镖任务被取消了。");  	
		}
	}
	else
	{
		send_user(who,"%c%s",';',"你放弃了这次运镖任务。");           
		member = find_player(sprintf("%d",who->get_quest("escort.id")));
		if ( objectp(member) )
			send_user(member,"%c%s",';',who->get_name()+"做事虎头蛇尾，已经离开了队伍，你得继续加油哦！"); 		      
		clear_task(who);
                clear_task_desc(who);		
	}		
}

void do_task_list(object who, object me)
{
	int level,id;
	string tmp="";

	if ( check_before_quest(who,me,1,0) != 1 )
		return ;	
	level = who->get_level();
	if( level < 30 )
	{
		send_user(who,"%c%s",'!',"你的等级不够30级");
		return;
	}
	if ( who->get_legend(TASK_49,13) && !who->get_legend(TASK_49,14) )
	{
		send_user(who,"%c%s",'!',"你正在试运镖呢");
		return;
	}
	id = getoid(me);
	if ( level >= 30 )
		tmp = sprintf(ESC "押金为6万的镖\ntalk %x# task.1\n",id);
	if ( level >=50 )
		tmp += sprintf(ESC "押金为8万的镖\ntalk %x# task.2\n",id);
	if ( level >= 70 )
		tmp += sprintf(ESC "押金为10万的镖\ntalk %x# task.3\n",id);
	
	send_user( who, "%c%s", ':', me->get_name() + "：\n    你想押多少钱的镖？\n" +
			tmp +
                        ESC "离开。\nCLOSE\n" );	
}
//镖王争霸
void check_biaowang(object me ,object who,int iTime)
{
	int i,j,id,id1,pos,size;
	mapping mpTmp;
	if ( time() > iFinish1 )
		return ;
	
	id = who->get_number();
	if ( get_save_2(sprintf("player.%d",id)) )
	{
		//找到之前的记录
		if ( get_save_2(sprintf("player.%d.time",id)) > iTime )
		{
			set_save_2(sprintf("player.%d.time",id),iTime);
			pos = get_save_2(sprintf("player.%d.pos",id));
		}
	}
	else if ( (size=get_save_2("biaowang.size")) < 10 )	
	{
		//插入新记录
		pos = size+1;
		set_save_2(sprintf("biaowang.%d",pos),id);
		set_save_2(sprintf("player.%d.time",id),iTime);
		set_save_2(sprintf("player.%d.account",id),who->get_id());
		set_save_2(sprintf("player.%d.name",id),who->get_name());
		set_save_2(sprintf("player.%d.id",id),who->get_number());
		set_save_2(sprintf("player.%d.pos",id),pos);
		set_save_2("biaowang.size",pos);
	}
	else
	{
		//比较时间最多的
		id1 = get_save_2(sprintf("biaowang.%d",size));
		if ( get_save_2(sprintf("player.%d.time",id1)) > iTime )
		{
			pos = size;
			delete_save_2(sprintf("player.%d",id1));	//删除
			set_save_2(sprintf("biaowang.%d",size),id);
			set_save_2(sprintf("player.%d.time",id),iTime);
			set_save_2(sprintf("player.%d.account",id),who->get_id());
			set_save_2(sprintf("player.%d.name",id),who->get_name());
			set_save_2(sprintf("player.%d.id",id),who->get_number());
			set_save_2(sprintf("player.%d.pos",id),pos);
		}		
	}
	if ( pos )	//重新排序
	{
		for(i=pos;i>1;i--)
		{
			id = get_save_2(sprintf("biaowang.%d",i));
			id1 = get_save_2(sprintf("biaowang.%d",i-1));
			if ( get_save_2(sprintf("player.%d.time",id1)) <= get_save_2(sprintf("player.%d.time",id)) )
				break;
			//交换位置
			set_save_2(sprintf("biaowang.%d",i),id1);
			set_save_2(sprintf("player.%d.pos",id1),i);
			set_save_2(sprintf("biaowang.%d",i-1),id);
			set_save_2(sprintf("player.%d.pos",id),i-1);
		}
		save();
	}
}
//根据名次领取镖王奖励
void get_biaowang_bonus(object who,int flag)
{
	int p;
        string *nTmp,tmp;
        object item;
	if ( flag == 1 )
	{
		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%s",'!',"你携带的物品太多了");
			return 0;	
		}	
		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6));
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return ;
		item = new(tmp);
		item->set_record(1);
		ITEM_EQUIP_D->init_equip_prop_3(item);
		p = item->move(who,-1);
		item->add_to_user(p);
		who->add_cash(200000);
		who->add_title("A006");	
		send_user(who,"%c%s",';',sprintf("你得到争霸战冠军奖励: 镖王称号，200000金，%s",item->get_name()));
	}
	else if ( flag == 2 )
	{
		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%s",'!',"你携带的物品太多了");
			return 0;	
		}	
		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6));
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return ;
		item = new(tmp);
		item->set_record(1);
		ITEM_EQUIP_D->init_equip_prop_3(item);
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who,"%c%s",';',sprintf("你得到争霸战亚军奖励: %s",item->get_name()));
	}
	else if ( flag == 3 )
	{
		who->add_cash(200000);
		send_user(who,"%c%s",';',"你得到争霸战季军奖励: 200000金");
	} 
	else if(flag>3 && flag<=10)
	{
		if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%s",'!',"你携带的物品太多了");
			return 0;	
		}	
		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6));
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return ;
		item = new(tmp);
		item->set_record(1);
		ITEM_EQUIP_D->init_equip_prop_1(item);
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who,"%c%s",';',sprintf("你得到争霸战奖励: %s",item->get_name()));
	}
	set_save_2(sprintf("player.%d.bonus",who->get_number()),1);
	log_file("biaowang.txt",sprintf("%s %s(%d) 领取第%d名奖励\n",short_time(),who->get_name(),who->get_number(),flag));
	save();
}

void biaowang(object me, object who,int flag)
{
	int level,z,p,x1,y1,x0,y0,iTime,gold,pos;
	object npc;
	string cmd = "", tmp = "";
	int i,id,iuse;
	string *npc_info;
	mixed mxTmp;
	
	restore();
	switch(flag)
	{
	case 11:
		if ( time() < iStart1 || time() > iFinish3 )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    现在不是镖王争霸战活动的时间，请去官方网站zg.mop.com查询下次活动的开展时间吧！\n"ESC"离开",me->get_name()));
			return ;
		}
		
		if ( check_before_quest(who,me,0,0) != 1 )
			return ;
		level = who->get_level();
		if( level < 30 )
		{
			send_user(who,"%c%s",'!',"你的等级不够30级");
			return;
		}
		id = getoid(me);
		if(time()>iFinish1)
		{
			mxTmp = localtime(iFinish2);
			
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(),
			sprintf("本届小超人杯“镖王争霸战”今天活动到此结束，已经接受了任务"
			"的玩家可以继续完成，但成绩不会进入镖王排名计算，%d:%d将会给出今天镖"
			"王争霸战结果，请大家拭目以待。\n"ESC"成绩查询\n"+
			sprintf( "talk %x# welcome.15\n", id )+ESC"离开",mxTmp[TIME_HOUR],
			mxTmp[TIME_MIN]));
			break;
		}
		else
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(),
			sprintf("%s:\n    速度与运气的竞争，智慧与技术的比拼！欢迎你参加本届小超人"
			"杯“镖王争霸战”，大奖在向你招手，荣誉在你头顶盘旋！是不是真正的战国镖王，只"
			"有试过才知道。\n    你只需要尽快把镖王小超人送到%s的%s处，就能获得奖励，完"
			"成时间越短奖励越丰厚，达到全服前三的话还有惊喜等着你！\n    你准备好了吗？"
			"\n"ESC"开始护送\ntalk %x# welcome.12\n"ESC"成绩查询\n" + 
			sprintf( "talk %x# welcome.15\n", id )+ESC"离开",me->get_name()
			,npc_num[num][0] ,npc_num[num][1],getoid(me)));
		}
		break;	
	case 12:
		if ( time() < iStart1 || time() > iFinish1 )
			return ;
		if ( check_before_quest(who,me,0,0) != 1 )
			return ;
		if( who->get_online_rate() != 100 )
		{
			send_user(who,"%c%s",'!',"你现在是非健康游戏时间，不能参加活动！");
			return;
		}
		level = who->get_level();
		if( level < 30 )
		{
			send_user(who,"%c%s",'!',"你的等级不够30级");
			return;
		}
		npc = new( "/npc/task/8100" );
                npc->set_name( sprintf("镖王小超人(%d)",who->get_number()));
                npc->set_walk_speed(3);
                z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
                if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
                {
                        x1 = p / 1000;  y1 = p % 1000;
                        npc->add_to_scene( z, x1, y1, get_front_xy(x1, y1, x0, y0) );
                        npc->set_owner(who);
                        who->to_front_xy(x1, y1);
                }

                who->set_quest("escort.escort", sprintf( "%x#", getoid(npc) ) );
                who->set_quest("escort.npc", npc);

	        who->delete_quest("escort.id");
	        who->delete_quest("escort.random");    // 记录随机事件
	        who->delete_quest("escort.robber");
	        who->delete_quest("escort.robber#");
	        who->delete_quest("escort.member");
		who->set_quest("escort.leader", 1);
	        who->set_quest("escort.biaowang", 1 );
	        who->set_quest("escort.time", time() );
	        who->set_quest("escort.flag", 3);
	        who->set_quest("escort.name", "赵木");
	        who->set_quest("escort.npcname","镖王小超人");
	        who->set_quest("escort.npcinfo",npc_num[num]);
	        send_task_list(who);
                break;
	case 13:	//领取奖励
		iTime = time();
		if ( iTime < iFinish1 || iTime > iFinish3 )
			return ;
		if ( iTime >= iFinish1 && iTime <= iFinish2 )
		{
			send_user(who,"%c%s",'!',"本届“镖王争霸战”最终获奖玩家还没有确定，请耐心等候！");
			return ;	
		}
		if ( get_save_2(sprintf("player.%d.bonus",who->get_number())) )
		{
			send_user(who,"%c%s",'!',"你已经领过奖励了！");
			return ;	
		}
		pos = get_save_2(sprintf("player.%d.pos",who->get_number()));
		if ( pos>=1 && pos<=10 )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    哎呀，你就是本届镖王争霸战夺魁的选手吗？这是给你的奖励！\n"ESC"获得奖励\ntalk %x# welcome.14\n"ESC"离开",me->get_name(),getoid(me)));
		else
		{
			send_user(who,"%c%s",'!',"你似乎不是镖王哦。");
			return ;	
		}				
		break;
	case 14:	//领取奖励
		iTime = time();
		if ( iTime < iFinish1 || iTime > iFinish3 )
			return ;
		if ( iTime >= iFinish1 && iTime <= iFinish2 )
		{
			send_user(who,"%c%s",'!',"本届“镖王争霸战”最终获奖玩家还没有确定，请耐心等候！");
			return ;	
		}
		if ( get_save_2(sprintf("player.%d.bonus",who->get_number())) )
		{
			send_user(who,"%c%s",'!',"你已经领过奖励了！");
			return ;	
		}
		pos = get_save_2(sprintf("player.%d.pos",who->get_number()));
		if ( pos<1 || pos > 10 )
		{
			send_user(who,"%c%s",'!',"你似乎不是镖王哦。");
			return ;	
		}	
		if ( pos>=1 && pos<=10 )
		{
			get_biaowang_bonus(who,pos);
		}
		break;
	case 15:
		for(i=1;i<=10;i++)
		{
			id = get_save_2(sprintf("biaowang.%d",i));
			if ( !id )
			{
				tmp = sprintf("%2d.%21s",i,"空缺");	
			}
			else
			{
				iuse = get_save_2(sprintf("player.%d.time",id));
				tmp = sprintf("%2d.%-13s"HIR"%02d分%02d秒"NOR,i,get_save_2(sprintf("player.%d.name",id))+":",iuse/60,iuse%60);
			}
			if((i-1)%2)tmp +="\n";
			else tmp +="\t\t\t\t\t";
			cmd += tmp;
		}
		send_user( who, "%c%s", ':', "本次比赛排名" + "：\n" 
			+ cmd + 
                        ESC "离开\nCLOSE\n" );
		break;        		
	case 21:
		npc_info = who->get_quest("escort.npcinfo");
		if ( !(who->get_quest("escort.biaowang")&& arrayp(npc_info)&&
			npc_info[1] == me->get_name()) )
			return ;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你就是预备争夺镖王的选手吗？让我们拭目以待吧！\n"ESC"完成任务\ntalk %x# welcome.22\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 22:
		npc_info = who->get_quest("escort.npcinfo");
		if ( !(who->get_quest("escort.biaowang")&& arrayp(npc_info)&&
			npc_info[1] == me->get_name()) )
			return ;
		iTime = gone_time(who->get_quest("escort.time"));
		if ( iTime > 2400 )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你来得太晚了，不能参加比赛了，还是请你自己取消任务吧！\n"ESC"离开",me->get_name()));
			return ;	
		}			
		npc = who->get_quest("escort.npc");
		if ( npc )
                {
                        if( !inside_screen_2(me, npc) )
                        {
                                send_user( who, "%c%s", '!', "您护送的人呢？！" );
                                return;
                        }
                        npc->remove_from_scene();
                        destruct(npc);
                }
                else
		{
                        send_user( who, "%c%s", '!', "您护送的人呢？！" );
                        return;
		}		
		send_user( who, "%c%c%d%w%w", 0x54, 12, getoid(who), -1, -1 );    // 借用 getoid(who)
		who->set_task_xy(0);
		check_biaowang(me,who,iTime);
		clear_task(who);
		
		if ( iTime < 180 )
			gold = 55000;
		else if ( iTime < 240 )
			gold = 45000;
		else
			gold = 30000;
		who->add_cash(gold);
		who->add_log("$biaowang", gold);
		send_user(who,"%c%s",';',sprintf("您参与镖王争霸战，金钱 %+d。", gold ));
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_ESCORT,3,"" ); 
		log_file("biaowang.txt",sprintf("%s %s(%d) 完成 %d秒\n",short_time(),who->get_name(),who->get_number(),iTime));
		break;
	}
}

int set_game_flag(int i)
{
	iFlag = i;
	save();
	return i;
}

void check_time()
{
	int iTime,i,id,iUse,call_time;
	mixed mxTmp;
	string cTmp;
	
	remove_call_out("check_time");
	iTime = time();
	if ( iTime > iFinish3 && !iFlag )
		return ;
	if ( iTime < iStart1 )
	{
		if ( (i=iStart1-iTime) <= 600 )
		{
			CHAT_D->sys_channel(0,sprintf(HIY"第%d届小超人杯“镖王争霸战”%d分钟后就要开始了！这是速度与运气的竞争，智慧与技术的比拼！大奖在向您招手，荣誉在您头顶盘旋，最终花落谁家，谁是真正的战国镖王，只有试过才知道！赶快到尉迟老镖头处等待活动的开始吧！",iGame+1,(iStart1-iTime)/60));
			if ( i > 120 )
				i = 120;
			call_out("check_time",i);
		}
		else
			call_out("check_time",i-600);
		return ;
	}
	if ( iTime >= iStart1 && iTime < iFinish1 && !iFlag )
		iFlag = 1;
	if ( iFlag )
	{
		if ( iTime >= iFinish1 && iTime <= iFinish2 && iFlag == 2)
			set_game_flag(3);
		else if ( iTime >= iFinish2 && iTime <= iFinish3 && iFlag == 4 )
			set_game_flag(5);
		else if ( iTime >= iFinish3  && iFlag == 6 )
			set_game_flag(7);
	}
	if ( iTime < iFinish1 )
	{
		call_time = iFinish1 - iTime;
		if ( call_time > 300 )
			call_time = 300;
	}
	else if ( iTime < iFinish2 )
		call_time = iFinish2 - iTime;
	else if ( iTime < iFinish3 )
		call_time = iFinish3 - iTime;
	else
		call_time = 0;
	if ( call_time )
		call_out("check_time",call_time);	
		
	if ( iFlag == 1 )
	{
		delete_save_2("biaowang");
		delete_save_2("player");
		iFlag = 2;
		iGame++;
		CHAT_D->sys_channel(0,sprintf(HIY"第%d届小超人杯“镖王争霸战”已经开始了！这是速度与运气的竞争，智慧与技术的比拼！大奖在向您招手，荣誉在您头顶盘旋，最终花落谁家，谁是真正的战国镖王，只有试过才知道！赶快到尉迟老镖头处接受任务，争夺镖王的荣誉吧！",iGame));
		save();
		return ;
	}
	else if ( iFlag == 2 )
	{
		CHAT_D->sys_channel(0,HIY"本届小超人杯“镖王争霸战”今天活动当前排名前三的镖王有力争夺者是:");
		for(i=1;i<=3;i++)
		{
			id = get_save_2(sprintf("biaowang.%d",i));
			if ( !id )
			{
				CHAT_D->sys_channel(0,sprintf(HIY"第%d名空缺",i));
				continue;	
			}
			iUse = get_save_2(sprintf("player.%d.time",id));
			CHAT_D->sys_channel(0,sprintf(HIY"第%d名"HIR"%s"HIY"，用时"HIR"%d分%d秒",i,get_save_2(sprintf("player.%d.name",id)),iUse/60,iUse%60));
		}
		return ;
	}
	else if ( iFlag == 3 )
	{
		for(i=1;i<=3;i++)
		{
			id = get_save_2(sprintf("biaowang.%d",i));
			if ( !id )
			{
				continue;	
			}
			iUse = get_save_2(sprintf("player.%d.time",id));
			log_file("biaowang.txt",sprintf("%s 第%d届镖王争霸战 第%d名 %s(%d) %s 用时%d分%d秒\n",short_time(),iGame,i,get_save_2(sprintf("player.%d.name",id)),id,get_save_2(sprintf("player.%d.account",id)),iUse/60,iUse%60));
		}
		mxTmp = localtime(iFinish2);
		CHAT_D->sys_channel(0,sprintf(HIY"本届小超人杯“镖王争霸战”今天活动到此结束，已经接受了任务的玩家可以继续完成，但成绩不会进入镖王排名计算，%d:%d将会给出今天镖王争霸战结果，请大家拭目以待。",mxTmp[TIME_HOUR],mxTmp[TIME_MIN]));
		set_game_flag(4);
		return ;
	}
	else if ( iFlag == 5 )	//公布得奖名单
	{
		CHAT_D->sys_channel(0,HIY"本届小超人杯“镖王争霸战”今天活动中的镖王已经产生，他们是:");
		for(i=1;i<=10;i++)
		{         
			id = get_save_2(sprintf("biaowang.%d",i));
			
			if(i<=3)
			{
				if ( !id )
				{
					CHAT_D->sys_channel(0,sprintf(HIY"第%d名空缺",i));
					continue;	
				}
				cTmp = i==1?"镖王":(i==2?"亚军":"季军");
				iUse = get_save_2(sprintf("player.%d.time",id));
				CHAT_D->sys_channel(0,sprintf(HIY"%s"HIR"%s"HIY"，用时"HIR"%d分%d秒",cTmp,get_save_2(sprintf("player.%d.name",id)),iUse/60,iUse%60));
				MAILBOX->sys_mail(get_save_2(sprintf("player.%d.account",id)),id,"恭喜您！您在本届小超人杯“镖王争霸战”中赢得了"+HIR+cTmp+NOR+"奖励，请尽快前往周国找尉迟老镖头领取您应得的奖励！超过今天晚上12点会被视作自行放弃奖励哦。");
			}
			else
				MAILBOX->sys_mail(get_save_2(sprintf("player.%d.account",id)),id,"恭喜您！您在本届小超人杯“镖王争霸战”中赢得了奖励，请尽快前往周国找尉迟老镖头领取您应得的奖励！超过今天晚上12点会被视作自行放弃奖励哦。");
		}
		CHAT_D->sys_channel(0,HIY"请获奖玩家在23：59前去找尉迟老镖头接受应得的荣誉。超过23：59不去领取奖励的话，会被当作自行放弃哦。");
		set_game_flag(6);
		return ;
	}
	else if ( iFlag == 7 )
	{
		for(i=1;i<=3;i++)
		{
			id = get_save_2(sprintf("biaowang.%d",i));
			if ( !id )
				continue;
			iUse = get_save_2(sprintf("player.%d.bonus",id));
			if ( !iUse )
			{
				cTmp = i==1?"镖王":(i==2?"亚军":"季军");	
				log_file("biaowang.txt",sprintf("%s %s(%d) 超时没领取奖励\n",short_time(),get_save_2(sprintf("player.%d.name",id)),id,));
				MAILBOX->sys_mail(get_save_2(sprintf("player.%d.account",id)),id,"很遗憾，虽然您获得了本届小超人杯“镖王争霸战”的"+cTmp+"奖励，但超过23：59仍未前来领取奖励，被视为已经放弃领取奖励。请下次记得及时来领取您应得的奖励。");
			}
		}		
		delete_save_2("biaowang");
		delete_save_2("player");
		iStart1 += 3600*24*7;//一星期后活动开启
		iFinish1 += 3600*24*7;
		iFinish2 += 3600*24*7;
		iFinish3 += 3600*24*7;
		iFlag = 0;
		call_out("check_time",3);
		num++;
		if(num >=4)num=0;//循环4个路径
		save();
		return;
	}
	
}

int set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2,cTmp3;
	if ( sscanf(arg ,"%s-%s-%s",cTmp1,cTmp2,cTmp3) != 3 )
	{
		send_user(who,"%c%s",'!',"错误的格式！");	
		return 0;
	}
	//20070518 2000
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart1 = mktime(year,mon,day,hour,min,0);	//活动开始时间

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish1 = mktime(year,mon,day,hour,min,0);	//结束时间

	year = to_int(cTmp3[0..3]);
	mon = to_int(cTmp3[4..5]);
	day = to_int(cTmp3[6..7]);
	hour = to_int(cTmp3[8..9]);
	min = to_int(cTmp3[10..11]);
	iFinish2 = mktime(year,mon,day,hour,min,0);	//发奖时间
	iFinish3 = mktime(year,mon,day+1,0,0,0);	//发奖结束时间
	
	if ( !iStart1 || !iFinish1 || !iFinish2 )
	{
		send_user(who,"%c%s",'!',"错误的时间！");	
		return 0;
	}
	if ( iStart1 > iFinish1 || iFinish1 < time() || iFinish1 > iFinish2 )
	{
		send_user(who,"%c%s",'!',"错误的时间！！");	
		return 0;
	}
	tell_user(who,"镖王争霸战开启：%s！",arg);	
	send_user(who,"%c%s",'!',"镖王争霸战开启！");	
	iFlag = 0;		
	save();
	call_out("check_time",3);
	return 1;
}

int set_close(object who)
{
	remove_call_out("check_time");
	iStart1 = 0;	
	iFinish1 = 0;		
	iFinish2 = 0;		
	iFinish3 = 0;
	iFlag = 0;
	num = 0;		
	send_user(who,"%c%s",'!',"镖王争霸战关闭！");	
	save();
	return 1;	
}

int test(int i)
{
	if ( i == 1 )
	{
		iStart1 = time()+610;		
		iFinish1 = time()+1800;
		iFinish2 = time()+1830;
		iFinish3 = time()+1840;
		iFlag = 0;
		save();
	}
	else if ( i == 2 )
	{
		iStart1 = time()+10;		
		iFinish1 = time()+1800;
		iFinish2 = time()+1830;
		iFinish3 = time()+1840;
		iFlag = 0;
		save();
	}
	else if ( i == 3 )
	{
		iStart1 = time()-10;		
		iFinish1 = time()-5;
		iFinish2 = time()+1830;
		iFinish3 = time()+1840;
//		iFlag = 3;
		save();
	}
	else if ( i == 4 )
	{
		iStart1 = time()-20;		
		iFinish1 = time()-10;
		iFinish2 = time()-5;
		iFinish3 = time()+1840;
//		iFlag = 4;
		save();
	}
	else if ( i == 5 )
	{
		iStart1 = time()-20;		
		iFinish1 = time()-10;
		iFinish2 = time()-5;
		iFinish3 = time()-2;
//		iFlag = 5;
		save();
	}
	check_time();
}
