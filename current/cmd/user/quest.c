
#include <ansi.h>
#include <task.h>
int quest_other(object me, string arg);
// 函数：命令处理
int main( object me, string arg )
{	
	string com,arg1;
	
	if ( !stringp(arg) || ( sscanf(arg,"%s %s", com,arg1) != 2 && arg != "list" ) )
	{
		return quest_other(me,arg);
	}
	
	if ( arg == "list" || com == "list" )
		USER_TASK_D->get_task_list(me);
	else if ( com == "intro")
		USER_TASK_D->get_task_intro(me,arg1);
	else if ( com == "giveup" )
		USER_TASK_D->task_giveup(me,arg1);
		
	
}
int quest_other(object me, string arg)
{
        object map, city, npc, who = me;
        string id, name, result, result2;
        int z, x, y, time, index = 0, status;

        result = "";  result2 = "";
        
        if( arg && arg != "" )
        {
                if( arg == "?" )    // 收集任务
                {
                        send_user( me, "%c%c%c", 0x51, '2', 0 );
                        result = USER_TASK_D->get_task_desc_2(who, me );                

                        if( result == "" ) 
                        {                                
                                result = "您现在没有剧情任务。\n";
                                send_user( me, "%c%c%s", 0x51, '2', result );
                        }
                        return 1;
                }

                if( is_player(me) )    // ＧＭ查看任务
                {
                        notify( "您没有足够的权限。" );
        		return 1;
                }

                if( sscanf(arg, "? %s", id) )
                {
                        send_user( me, "%c%c%c", 0x51, '2', 0 );
                        if( !( who = find_player(id) ) )
                        {
                                notify( "您无法找到这个人。" );
        		        return 1;
                        }

                        tell_user(me, "列示%s(%d)的任务。", who->get_name(), who->get_number() );
                
                        result = USER_TASK_D->get_task_desc_2(who, me);

                        if( result == "" ) 
                        {                                
                                result = "对方没有剧情任务。\n";
                                send_user( me, "%c%c%s", 0x51, '2', result );
                        }

                        return 1;
                }

                if( !( who = find_player(arg) ) )
                {
                        notify( "您无法找到这个人。" );
        		return 1;
                }

                tell_user(me, "列示%s(%d)的任务。", who->get_name(), who->get_number() );
        }
       send_user( me, "%c%c%s", 0x51, '1' , 0 );

//        result = USER_TASK_D->get_task_desc(who);
//        send_user( me, "%c%c%s", 0x51, '1', result );

	if ( who->get_task("criminal.bonus") )
	{
                result = sprintf("［挖宝任务］\n"BLK"追捕逃犯\n\n"BLK"任务目的：\n"BLK"    剿灭因监狱墙壁破损而出逃的逃犯。\n"BLK"    剿灭%s： 1/1（已经完成）。\n"BLK"任务描述：\n"BLK"    前些日子因暴风雨的缘故，监狱墙壁破损严重，导致小部分逃犯趁机逃跑，听闻探子回报，"HIR"%s"BLK"就藏匿于"HIR"%s"BLK"一带，若你能顺利剿灭此逃犯，大王定会重重有赏。\n"BLK"奖励：1500金\n",
                        who->get_task("criminal.name"),who->get_task("criminal.name"),  who->get_task("criminal.map"));
                send_user( me, "%c%c%s", 0x51, '1', result );                        
        }
        else if(     stringp( id = who->get_task("criminal") ) 
        &&    ( npc = find_char(id) ) && npc->is_criminal() )    // 30 分钟
        {
                time = 1800 - gone_time( npc->get("birthday") );
                map = get_map_object( get_z(npc) );
                name = map ? map->get_name() : "无名地图";
                result = sprintf("［挖宝任务］\n"BLK"追捕逃犯\n\n"BLK"任务目的：\n"BLK"    剿灭因监狱墙壁破损而出逃的逃犯。\n"BLK"    剿灭%s： 0/1（剩余时间%d分钟）。\n"BLK"任务描述：\n"BLK"    前些日子因暴风雨的缘故，监狱墙壁破损严重，导致小部分逃犯趁机逃跑，听闻探子回报，"HIR"%s"BLK"就藏匿于"HIR"%s"BLK"一带，若你能顺利剿灭此逃犯，大王定会重重有赏。\n"BLK"奖励：1500金\n",
                        npc->get_name(),range_value( time / 60, 0, MAX_NUMBER ),  npc->get_name(),name);
                send_user( me, "%c%c%s", 0x51, '1', result );                        
        }
	
	if ( who->get_task("robber.bonus") )
	{
		result = sprintf("［师爷任务］\n"BLK"剿灭%s（第%d环）\n"BLK"任务目的：\n"BLK"    助周国衙门的师爷剿灭"HIR"%s"BLK"。\n"BLK"    消灭%s： 1/1（已经完成）\n"BLK"任务描述：\n"BLK"    据报说最近有一个悍匪"HIR"%s"BLK"在"HIR"%s"BLK"一带活动，他杀人越货无恶不作，十分猖獗。\n"BLK"    现在衙门人手严重不足，只希望少侠能出手相助。如果能成功剿灭这贼，本师爷会给少侠丰厚报酬的。\n"BLK"任务奖励："HIR"500金",
                	who->get_task("robber.name"),who->get_task("robber#") + 1,who->get_task("robber.name"),who->get_task("robber.name"),who->get_task("robber.name"),who->get_task("robber.map"));
                send_user( me, "%c%c%s", 0x51, '1', result ); 
	}
        else if(     stringp( id = who->get_task("robber") ) 
        &&    ( npc = find_char(id) ) && npc->is_robber() )    // 30 分钟
        {
                time = 3600 - gone_time( npc->get("birthday") );
                map = get_map_object( get_z(npc) );
                name = map ? map->get_name() : "无名地图";
                result = sprintf("［师爷任务］\n"BLK"剿灭%s（第%d环）\n"BLK"任务目的：\n"BLK"    助周国衙门的师爷剿灭"HIR"%s"BLK"。\n"BLK"    消灭%s： 0/1（剩余时间%d分钟）\n"BLK"任务描述：\n"BLK"    据报说最近有一个悍匪"HIR"%s"BLK"在"HIR"%s"BLK"一带活动，他杀人越货无恶不作，十分猖獗。\n"BLK"    现在衙门人手严重不足，只希望少侠能出手相助。如果能成功剿灭这贼，本师爷会给少侠丰厚报酬的。\n"BLK"任务奖励："HIR"500金",
                	npc->get_name(),who->get_task("robber#") + 1,npc->get_name(),npc->get_name(),
                        range_value( time / 60, 0, MAX_NUMBER ),npc->get_name(),name );
                send_user( me, "%c%c%s", 0x51, '1', result );                        
        }
        if( stringp( id = who->get_task("banditi") ) 
        &&    ( npc = find_char(id) ) && npc->is_banditi() )    // 30 分钟
        {
                z = npc->get("xy.z");
                x = npc->get("xy.x");
                y = npc->get("xy.y");
                time = 3600 - gone_time( npc->get("birthday") );
                map = get_map_object( get_z(npc) );
                name = map ? map->get_name() : "无名地图";
                result = sprintf("［剿匪任务］\n"BLK"任务目的：\n"BLK"    消灭在" HIR "%s(%d,%d)" BLK "附近出没的" HIR "%s"BLK"。\n" BLK "%s : 0/1  （剩余时间：%d分钟）。\n"BLK"任务描述：\n"BLK"    近期听闻在"HIR"%s(%d,%d)"BLK"附近有匪徒%s正纠结同伙，打算对我村进行洗劫，希望大侠能仗义剿匪。",
                        name, x, y, npc->get_name(), npc->get_name(),range_value( time / 60, 0, MAX_NUMBER ),name,x,y,npc->get_name() );

                send_user( me, "%c%c%s", 0x51, '1', result );                        
        }
	if(  who->get_task("banditi_bonus") )
	{
                result = sprintf("［剿匪任务］\n"BLK"任务目的：\n"BLK"    消灭在" HIR "%s(%d,%d)" BLK "附近出没的" HIR "%s" BLK "。\n" BLK "%s : 1/1  （已经完成）。\n"BLK"任务描述：\n"BLK"    近期听闻在"HIR"%s(%d,%d)"BLK"附近有匪徒"HIR"%s"BLK"正纠结同伙，打算对我村进行洗劫，希望大侠能仗义剿匪。",
                        who->get_task("banditi_map"), who->get_task("banditi_x"), who->get_task("banditi_y"), who->get_task("banditi_name"), who->get_task("banditi_name"),who->get_task("banditi_map"), who->get_task("banditi_x"), who->get_task("banditi_y"), who->get_task("banditi_name"));
		if ( stringp(result) )
			send_user( me, "%c%c%s", 0x51, '1', result );
	}	

	if( time = who->get_quest("thief.time") )
	{
		if ( 1800 < gone_time(time) )
		{
			who->delete_quest("thief.bonus");
			who->delete_quest("thief.task");
			who->delete_quest("thief.flag");
			who->delete_quest("thief.time");		
		}
		else if( time = who->get_quest("thief.bonus") ) 
		{
			switch( time )
			{
				case 1:
					result = sprintf("[老村长任务]\n"BLK"教训小偷\n"BLK"任务目的：\n"BLK"    到" HIR "%s" BLK "的" HIR "%d，%d" BLK "一带，把" HIR "%s" BLK "教训一顿后回报新手村的老村长。(已经完成)\n" BLK "教训%s：1/1\n"BLK"任务描述：\n"BLK"    昨天晚上%s又光顾了我们的村子。尽管村子没有损失什么贵重的东西，但是就这样饶过了那贼，老夫实在不甘心。刚才有村民说见到%s在%s的（%d，%d）附近出现。如果%s能助老夫一臂之力，教训一下%s。让他知道村子的厉害就好了。",
							who->get_quest("thief.map"),x,y,who->get_quest("thief.name"),who->get_quest("thief.name"),who->get_quest("thief.name"),who->get_quest("thief.name"),who->get_quest("thief.map"),x,y,NPC_RANK_D->get_respect_2(who),who->get_quest("thief.name"));        
					if ( stringp(result) )
						send_user( me, "%c%c%s", 0x51, '1', result );      	
					break;
				case 4:
					result = sprintf("[老村长任务]\n"BLK"追捕窃贼\n"BLK"任务目的：\n"BLK"    追捕逃窜到" HIR "%s(%d，%d)" BLK "附近的" HIR "%s" BLK "，并将被窃的贵重品交还给新手村老村长。任务已经完成。\n" BLK "失窃的贵重品：1/1\n"BLK"任务描述：\n"BLK"    那个可恶的%s昨天晚上又光顾了我们的村子！竟将村中的贵重物品洗劫一空！据村民回报最后一次见到%s是在%s的（%d，%d）附近。 如今村卫团人手实在不足，实在无法分派出更多的人手了。如果%s能帮忙夺回失窃的物品，老夫定会重重有赏。",who->get_quest("thief.map"),who->get_quest("thief.x"),who->get_quest("thief.y"),who->get_quest("thief.name"),who->get_quest("thief.name"),who->get_quest("thief.name"),who->get_quest("thief.map"),who->get_quest("thief.x"),who->get_quest("thief.y"),NPC_RANK_D->get_respect_2(who));
					if ( stringp(result) )
						send_user( me, "%c%c%s", 0x51, '1', result );  
					break;	
			}
		}
		else if( time = who->get_quest("thief.flag") ) 		
		{
			switch( time )
			{
			       	case 1 : // 2. 失窃任务(人物)
			                if(     stringp( id = who->get_quest("thief.thief") ) 
			                &&    ( npc = find_char(id) ) && npc->is_thief() )    // 30 分钟
			                {
			                        z = who->get_quest("thief.z");
			                        x = who->get_quest("thief.x");
			                        y = who->get_quest("thief.y");
			                        time = 1800 - gone_time( who->get_quest("thief.time") );
			                        map = get_map_object(z);
			                        name = map ? map->get_name() : "无名地图";
						result = sprintf("[老村长任务]\n"BLK"教训小偷\n"BLK"任务目的：\n"BLK"    到" HIR "%s" BLK "的" HIR "%d，%d" BLK "一带，把" HIR "%s" BLK "教训一顿后回报新手村的老村长。任务剩余时间%d分钟。\n" BLK "教训%s：0/1\n"BLK"任务描述：\n"BLK"    昨天晚上%s又光顾了我们的村子。尽管村子没有损失什么贵重的东西，但是就这样饶过了那贼，老夫实在不甘心。刚才有村民说见到%s在%s的（%d，%d）附近出现。如果%s能助老夫一臂之力，教训一下%s。让他知道村子的厉害就好了。",
							name,x,y,npc->get_name(),range_value( time / 60, 0, MAX_NUMBER ),npc->get_name(),npc->get_name(),npc->get_name(),name,x,y,NPC_RANK_D->get_respect_2(who),npc->get_name());                        	
			                        send_user( me, "%c%c%s", 0x51, '1', result );                                
			                }
			                break;
			                
			       	case 2 : // 1. 失窃任务(物品)
			                if( ( time = 1800 - gone_time( who->get_quest("thief.time") ) ) > 0 )    // 15 分钟
			                {
			                        z = who->get_quest("thief.z");
			                        x = who->get_quest("thief.x");
			                        y = who->get_quest("thief.y");
			//                      time = 1800 - gone_time( who->get_quest("thief.time") );
			                        map = get_map_object(z);
			                        name = map ? map->get_name() : "无名地图";
						result = sprintf("[老村长任务]\n"BLK"找回丢失的物品\n"BLK"任务目的:\n"BLK"    到" HIR "%s" BLK "的" HIR "%d，%d" BLK "一带，找回八姑丢失的" HIR "%s" BLK "，并带回给老村长。任务剩余时间%d分钟。\n" BLK "%s：0/1\n"BLK"任务描述：\n"BLK"    昨天八姑又来我这诉苦，说自己的东西又丢了。实话说，老夫实在不想管这些鸡婆的事，但是又不能坐视不理……这次八姑丢失了一%s%s，据她描述应该是在%s的（%d，%d）一带丢失的。怎样？%s是否愿意帮老夫这个忙，将八姑丢失的东西找回来呢？"
							,name,x,y,who->get_quest("thief.thief"),range_value( time / 60, 0, MAX_NUMBER ),who->get_quest("thief.thief"),who->get_quest("thief.unit"),who->get_quest("thief.thief"),name,x,y,NPC_RANK_D->get_respect_2(who)); 
			                        send_user( me, "%c%c%s", 0x51, '1', result );                                
			                }
			                break;
			
			       	case 3 : // 5. 寻物任务
			                if( ( time = 1800 - gone_time( who->get_quest("thief.time") ) ) > 0 )    // 15 分钟
			                {
						result = sprintf("[老村长任务]\n"BLK"物品采购\n"BLK"任务目的：\n"BLK"    帮老村长买一%s"HIR"%s"BLK"。回来后记得用给予指令（快捷键G）将物品交给老村长。\n"BLK"%s：0/1\n"BLK"任务描述：\n"BLK"    %s，见到你刚好。老夫原本想今天出门买些东西，没想到一把年纪，老毛病风湿又犯了。现在腰疼得实在受不了。不知道%s是否愿意帮老夫跑一趟，买%s%s回来呢？\n", who->get_quest("thief.unit"), who->get_quest("thief.thief"), who->get_quest("thief.thief"),NPC_RANK_D->get_respect_2(who),NPC_RANK_D->get_respect_2(who),who->get_quest("thief.unit"),who->get_quest("thief.thief")); 			                        
			                        send_user( me, "%c%c%s", 0x51, '1', result );                                
			                }
			                break;
			
			       	case 4 : // 3. 失窃任务(人物)
			                if(     stringp( id = who->get_quest("thief.thief") ) 
			                &&    ( npc = find_char(id) ) && npc->is_thief() )    // 15 分钟
			                {
			                        z = who->get_quest("thief.z");
			                        x = who->get_quest("thief.x");
			                        y = who->get_quest("thief.y");
			                        time = 1800 - gone_time( who->get_quest("thief.time") );
			                        map = get_map_object(z);
			                        name = map ? map->get_name() : "无名地图";
			                        result = sprintf("[老村长任务]\n"BLK"追捕窃贼\n"BLK"任务目的：\n"BLK"    追捕逃窜到" HIR "%s(%d，%d)" BLK "附近的" HIR "%s" BLK "，并将被窃的贵重品交还给新手村老村长。任务剩余时间%d分钟。\n" BLK "失窃的贵重品：0/1\n"BLK"任务描述：\n"BLK"    那个可恶的%s昨天晚上又光顾了我们的村子！竟将村中的贵重物品洗劫一空！据村民回报最后一次见到%s是在%s的（%d，%d）附近。 如今村卫团人手实在不足，实在无法分派出更多的人手了。如果%s能帮忙夺回失窃的物品，老夫定会重重有赏。",map->get_name(),x,y,npc->get_name(),range_value( time / 60, 0, MAX_NUMBER ),npc->get_name(),npc->get_name(),map->get_name(),x,y,NPC_RANK_D->get_respect_2(who));                        
			                        send_user( me, "%c%c%s", 0x51, '1', result );                                
			                }
			                break;
			        }			
		}
	}
        
        if( time = who->get_quest("escort.flag") )
        {
                if( time == 1 )    // 1. 运镖任务(物品)
                {
                        time = 2400 - gone_time( who->get_quest("escort.time") );    // 40 分钟

                        if( who->get_quest("escort.id") && who->get_quest("escort.member") )
                                result = sprintf("［运镖任务］\n"BLK"剩 %d 分\n" BLK "与队友%s护送物品到" HIR "%s" BLK "处。\n",
                                        range_value( time / 60, 0, MAX_NUMBER ), who->get_quest("escort.member"), who->get_quest("escort.name") );
                        else    result = sprintf("［运镖任务］\n"BLK"剩 %d 分\n" BLK "护送物品到" HIR "%s" BLK "处。\n", 
                                        range_value( time / 60, 0, MAX_NUMBER ), who->get_quest("escort.name") );
                        send_user( me, "%c%c%s", 0x51, '1', result );                                        

                        if(     objectp( npc = me->get_quest("escort.robber#") )    // 寻找蒙面人
                        &&      npc->is_escort_robber_2()    // 被动乞丐
                        &&      npc->get("gold") )
                        {
                                result = sprintf("［突发任务］\n"BLK"把" HIR " %d " BLK "金给" HIR "%s" BLK "。\n",
                                        npc->get("gold"), npc->get_name() );
                                send_user( me, "%c%c%s", 0x51, '1', result );         
                        }                               
                }
                else if( time == 2 )    // 2. 运镖任务(人物)
                {
                        time = 2400 - gone_time( who->get_quest("escort.time") );

                        if( time < 0 )
                                result = sprintf("［运镖任务］\n"BLK"失败，请回报" HIR "尉迟老镖头" BLK "。\n");
                        else if( who->get_quest("escort.id") && who->get_quest("escort.member") )
                                result = sprintf("［运镖任务］\n"BLK"剩 %d 分\n" BLK "与队友%s护送人员到" HIR "%s" BLK "处。\n",
                                        range_value( time / 60, 0, MAX_NUMBER ), who->get_quest("escort.member"), who->get_quest("escort.name") );
                        else    result = sprintf("［运镖任务］\n"BLK"剩 %d 分\n" BLK "护送人员到" HIR "%s" BLK "处。\n", 
                                        range_value( time / 60, 0, MAX_NUMBER ), who->get_quest("escort.name") );
                        send_user( me, "%c%c%s", 0x51, '1', result );                                        
                }
        }

        if(     stringp( id = who->get_task("rascal") ) 
        &&    ( npc = find_char(id) ) && npc->is_rascal() )    // 40 分钟
        {
                z = npc->get("xy.z");
                x = npc->get("xy.x");
                y = npc->get("xy.y");
                time = 2400 - gone_time( npc->get("birthday") );
                map = get_map_object( get_z(npc) );
                name = map ? map->get_name() : "无名地图";
                result = sprintf("［巡逻任务］\n"BLK"剩 %d 分\n" BLK "去" HIR "%s(%d,%d)" BLK "教训" HIR "%s" BLK "。\n",
                        range_value( time / 60, 0, MAX_NUMBER ), name, x, y, npc->get_name() );
                send_user( me, "%c%c%s", 0x51, '1', result );                        
        }

        if( time = who->get_save_2("build.flag") ) switch( time )    // 40 分钟
        {
      default : if(     stringp( id = who->get_task("rascal2") ) 
                &&    ( npc = find_char(id) ) && npc->is_rascal_2() )
                {
                        z = npc->get("xy.z");
                        x = npc->get("xy.x");
                        y = npc->get("xy.y");
                        time = 2400 - gone_time( npc->get("birthday") );
                        map = get_map_object( get_z(npc) );
                        name = map ? map->get_name() : "无名地图";
                        result = sprintf("［建设任务］\n"BLK"剩 %d 分\n" BLK "去" HIR "%s(%d,%d)" BLK "教训" HIR "%s" BLK "。\n",
                                range_value( time / 60, 0, MAX_NUMBER ), name, x, y, npc->get_name() );
                        send_user( me, "%c%c%s", 0x51, '1', result );                                
                }
                break;
       case 2 : if( ( time = gone_time( who->get_save_2("build.time") ) ) < 2400 )
                {
                        result = sprintf("［建设任务］\n"BLK"剩 %d 分\n" BLK "去财政官那儿帮手" HIR "算几天帐" BLK "。\n", ( 2400 - time ) / 60 );
                        send_user( me, "%c%c%s", 0x51, '1', result );
                }
                break;
       case 3 : if( ( time = gone_time( who->get_save_2("build.time") ) ) < 2400 )
                {
                        result = sprintf("［建设任务］\n"BLK"剩 %d 分\n" BLK "将食物送给城中四处的" HIR "工匠" BLK "。\n", ( 2400 - time ) / 60 );
                        send_user( me, "%c%c%s", 0x51, '1', result );
                }
                break;
       case 4 : if( ( time = gone_time( who->get_save_2("build.time") ) ) < 2400 )
                {
                        result = sprintf("［建设任务］\n"BLK"剩 %d 分\n" BLK "寻“" HIR "%s" BLK "”给内政官。\n", 
                                ( 2400 - time ) / 60, who->get_save_2("build.item") );
                        send_user( me, "%c%c%s", 0x51, '1', result );                                
                }
                break;
        }

        if(   ( time = gone_time( who->get_save_2("relation.time") ) ) < 2400    // 40 分钟
        &&    ( x = who->get_save_2("relation.city") ) && ( y = who->get_save_2("relation.city2") ) )
        {
                switch( who->get_save_2("relation.flag") )
                {
              default : result = sprintf("［外交任务］\n"BLK"剩 %d 分\n" BLK "作为%s使节同" HIR "%s" BLK "进行" HIR "友好" BLK "外交。\n", 
                                ( 2400 - time ) / 60, CITY_D->get_city_name(x), CITY_D->get_city_name(y) );
                        break;
               case 2 : result = sprintf("［外交任务］\n"BLK"剩 %d 分\n" BLK "作为%s使节同" HIR "%s" BLK "进行" HIR "交恶" BLK "外交。\n", 
                                ( 2400 - time ) / 60, CITY_D->get_city_name(x), CITY_D->get_city_name(y) );
                        break;
                }
                send_user( me, "%c%c%s", 0x51, '1', result );
        }
        if(     who->is_scholar()
        &&    ( x = who->get_save_2("advice.city") ) && ( y = who->get_save_2("advice.city2") ) )
        {
                switch( who->get_save_2("advice.type") )
                {
              default : result = sprintf("［纵横任务］\n"BLK"作为%s使节同" HIR "%s" BLK "共商" HIR "结盟" BLK "大计。\n",
                                CITY_D->get_city_name(x), CITY_D->get_city_name(y) );
                        break;
               case 2 : result = sprintf("［纵横任务］\n"BLK"作为%s使节对" HIR "%s" BLK "提出" HIR "警告" BLK "。\n",
                                CITY_D->get_city_name(x), CITY_D->get_city_name(y) );
                        break;
                }
                send_user( me, "%c%c%s", 0x51, '1', result );
        }
        if (me->get_fam_name())
        {	
		if (me->get_save_2("mastertask.type")>0)
		{

			switch(me->get_save_2("mastertask.type"))
			{
			case 1:
				if (me->get_save_2("mastertask.status")!=99)
					result = sprintf("师门任务\n"BLK"抓怪(第%d轮)\n"BLK"任务目的：\n"BLK"    捕抓一个"HIR"%s"BLK"回来给师傅。\n"BLK"%s  0/1\n"BLK"任务描述：\n"BLK"    如今天下世道纷乱不堪，妖魔鬼怪四出肆虐，师傅要我去捉一个回来严加审问。据说%s，何不去寻寻看。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.target"));
				else
					result = sprintf("师门任务\n"BLK"抓怪(第%d轮)\n"BLK"任务目的：\n"BLK"    捕抓一个"HIR"%s"BLK"回来给师傅。\n"BLK"%s  1/1\n"BLK"任务描述：\n"BLK"    如今天下世道纷乱不堪，妖魔鬼怪四出肆虐，师傅要我去捉一个回来严加审问。据说%s，何不去寻寻看。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.target"));
				break;				
			case 2:
				if (me->get_save_2("mastertask.status")!=99)					
					result = sprintf("师门任务\n"BLK"历练(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点经验值后，回去禀告师傅。\n"BLK"提升经验：  %d/%d\n"BLK"任务描述：\n"BLK"    学艺之人只有勤加练习，技艺才可能日近精湛。如此坚持下去，方可领略到本门武学之精华，看来师傅要你提升%d经验来检验你平时练习的成果。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetxy"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
				else
					result = sprintf("师门任务\n"BLK"历练(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点经验值后，回去禀告师傅。\n"BLK"提升经验：  %d/%d\n"BLK"任务描述：\n"BLK"    学艺之人只有勤加练习，技艺才可能日近精湛。如此坚持下去，方可领略到本门武学之精华，看来师傅要你提升%d经验来检验你平时练习的成果。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
				break;
			case 3:
				if (me->get_save_2("mastertask.status")!=99)					
					result = sprintf("师门任务\n"BLK"游历(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点潜能后，回去禀告师傅。\n"BLK"提升潜能：  %d/%d\n"BLK"任务描述：\n"BLK"    想学到更上乘的武学精要，能力显得极为重要，能力只有在实践中磨练出来。师傅希望我出去走一走，去磨练一下，以此来提高我的武学能力。\n", me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetxy"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
				else
					result = sprintf("师门任务\n"BLK"游历(第%d轮)\n"BLK"任务目的：\n"BLK"    提升%d点潜能后，回去禀告师傅。\n"BLK"提升潜能：  %d/%d\n"BLK"任务描述：\n"BLK"    想学到更上乘的武学精要，能力显得极为重要，能力只有在实践中磨练出来。师傅希望我出去走一走，去磨练一下，以此来提高我的武学能力。\n", me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic"),me->get_save_2("mastertask.targetpic")    );
				break;
			case 4:
				if (me->get_save_2("mastertask.status")==0)
					result = sprintf("师门任务\n"BLK"采购(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，看看能有什么可以帮忙的地方。\n"BLK"任务描述：\n:"BLK"    %s最近禀报说本门部分物品储备不足，急需出门去采购一部分物品回来。师傅让我去找%s问明情况，看能不能帮上忙。\n", 
						me->get_save_2("mastertask.time")+1, name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name );
				else					
					result = sprintf("师门任务\n"BLK"采购(第%d轮)\n"BLK"任务目的：\n"BLK"    采购%s%s，并交给%s。\n"BLK"任务描述：\n"BLK"    %s最近回报说门里部分物品储备不足，过去问问，看看有什么能帮上忙的地方。\n"BLK"    由于平时没有细加留意，本门有些物品储备明显不足，如果不抓紧时间解决，将会给本门带来很大麻烦。但此时人手不够，%s托我采购%s%s回来交给他。\n", 
						me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.giftname"), me->get_save_2("mastertask.targetname"),name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name,me->get_save_2("mastertask.giftname"), me->get_save_2("mastertask.targetname")  );					
				break;		
			case 5:
				if (me->get_save_2("mastertask.status")==0)
					result = sprintf("师门任务\n"BLK"收集(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，看看能有什么可以帮忙的地方。\n"BLK"任务描述：\n"BLK"    %s最近向师傅禀报说本门需要部分物品以做必备之用，师傅让我过去询问一下具体情况，看看有什么能帮忙的地方。\n", 
						me->get_save_2("mastertask.time")+1, name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name );
				else
					result = sprintf("师门任务\n"BLK"收集(第%d轮)\n"BLK"任务目的：\n"BLK"    收集五个%s，并交给%s。\n"BLK"任务描述：\n"BLK"    %s最近向师傅禀报说本门需要部分物品以做必备之用，师傅让我过去询问一下具体情况，看看有什么能帮上忙的地方。\n"BLK"    当我找到%s后，他向我说明有些物品必须收集一部分以做必备之用，因而委托我帮忙收集%s回来。据说%s，何不去寻寻看。\n", 
						me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetname") ,name ="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetpic")  );
				break;
			case 6:
				result = sprintf("师门任务\n"BLK"拜访(第%d轮)\n"BLK"任务目的：\n"BLK"    拜访%s\n"BLK"任务描述：\n"BLK"    师傅闭关修行有些时日了，也不知师傅的老友们近况如何。想当初他们常来探访师傅，如果师傅不去拜访一下未免有些失礼。因而，师傅让我替他老人家问候一下%s的%s。",me->get_save_2("mastertask.time")+1,me->get_save_2("mastertask.targetname"),me->get_save_2("mastertask.targetcity"),me->get_save_2("mastertask.targetname"));
				break;	
			case 7:
				if (me->get_save_2("mastertask.status")==99)
					result = sprintf("师门任务\n"BLK"寻踪(第%d轮)\n"BLK"任务目的：\n"BLK"  寻踪云游商人\n"BLK"灵药：1/1\n"BLK"任务描述：\n"BLK"    云游商人游历四方，行踪飘忽不定，我既然能寻到他本人也真算是一种缘分。如今云游商人答应了我的要求，给了我灵药，我得尽快将灵药交给师傅，免得他老人家着急。",
					me->get_save_2("mastertask.time")+1);
				else
					result = sprintf("师门任务\n"BLK"寻踪(第%d轮)\n"BLK"任务目的：\n"BLK"    寻找云游商人\n"BLK"任务描述：\n"BLK"    师傅最近想尝试炼制一种丹药，但炼制这种丹药须得一种灵药做药引，据说只有传闻中的云游商人才有此种灵药。师傅让我试着去寻找云游商人，如若找到就向他求得此种灵药！\n",
						me->get_save_2("mastertask.time")+1);
				break;
			case 8:
				status = me->get_save_2("mastertask.status");
				if ( status == 2 || status == 99 )
					result = sprintf("师门任务\n"BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    消灭城外造遥闹事的流氓。\n"BLK"造遥的混混：1/1\n"BLK"任务描述：\n"BLK"%s的典狱官近日来信要求我们去协助其维持治安，家师命我全力以赴去协助其解决问题。\n"BLK"    当我来到%s后，听城里的典狱官说城外有人在造遥生事。我最好还是亲自过去处理一下。",
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name);
				else if ( status == 0 )
					result = sprintf("师门任务\n"BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    找%s典狱官协助其维持治安。\n"BLK"任务描述：\n"BLK"    %s的典狱官近日来信，说%s内的治安形势越发严峻，请求家师派几名得力弟子前去协助其维持治安。刚好家师就看见我，命我去协助其解决治安混乱问题。\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name);
				else if( stringp( id = who->get_save_2("mastertask.target") ) && ( npc = find_char(id) ) && npc->get("user")==who->get_number() )
					result = sprintf("师门任务\n"BLK"协助治安(第%d轮)\n"BLK"任务目的：\n"BLK"    消灭城外造遥闹事的流氓。\n"BLK"造遥的混混：0/1\n"BLK"任务描述：\n"BLK"%s的典狱官近日来信要求我们去协助其维持治安，家师命我全力以赴去协助其解决问题。\n"BLK"    当我来到%s后，听城里的典狱官说城外有人在造遥生事。我最好还是亲自过去处理一下。",
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name);
				break;		
			case 9:
				if ((status=me->get_save_2("mastertask.status"))==99 || status == 2)
					result = sprintf("师门任务\n"BLK"巡山(第%d轮)\n"BLK"任务目的：\n"BLK"    在本门派一带巡查，扫除一切可疑的人物。\n"BLK"可疑的人物：1/1\n"BLK"任务描述：\n"BLK"    有弟子禀报师傅说在师门附近出现了可疑人物，为师命我前去察看一下，如果被我发现是些鸡鸣狗盗之类，定要好好惩治一下他们，否则本门威信何在？\n", 
						me->get_save_2("mastertask.time")+1   );
				else if( stringp( id = who->get_save_2("mastertask.target") ) && ( npc = find_char(id) ) && npc->get("user")==who->get_number() )
					result = sprintf("师门任务\n"BLK"巡山(第%d轮)\n"BLK"任务目的：\n"BLK"    在本门派一带巡查，扫除一切可疑的人物。\n"BLK"可疑的人物：0/1\n"BLK"任务描述：\n"BLK"    有弟子禀报师傅说在师门附近出现了可疑人物，为师命我前去察看一下，如果被我发现是些鸡鸣狗盗之类，定要好好惩治一下他们，否则本门威信何在？\n", 
						me->get_save_2("mastertask.time")+1   );					
				break;				
			case 10:
				if ( me->get_save_2("mastertask.status")==99 )
					result = sprintf("师门任务\n"BLK"门派切磋(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s门派切磋武艺。\n"BLK"%s弟子：1/1\n"BLK"任务描述：\n"BLK"    %s掌门差人来信邀请本门弟子去其处切磋武艺，以此来弥补各自武学之缺陷。师傅命我前去，此等机会，我可不能错失了，时间有限，我得马上赶过去\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name  );
				else
					result = sprintf("师门任务\n"BLK"门派切磋(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s门派切磋武艺。\n"BLK"%s弟子：0/1\n"BLK"任务描述：\n"BLK"    %s掌门差人来信邀请本门弟子去其处切磋武艺，以此来弥补各自武学之缺陷。师傅命我前去，此等机会，我可不能错失了，时间有限，我得马上赶过去\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name  );
				break;	
			case 11:
				status = me->get_save_2("mastertask.status");
				if (status==0)
					result = sprintf("师门任务\n"BLK"筹集资金(第%d轮)\n"BLK"任务目的：\n"BLK"    去找%s问问，帮助他解决问题。\n"BLK"任务描述：\n"BLK"    最近%s好像经常心神不定，看来是有什么烦恼。过去问问，看看可有帮得上忙的地方。\n", 
						me->get_save_2("mastertask.time")+1, name="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name );	
				else
				if (status!=99)				
					result = sprintf("师门任务\n"BLK"筹集资金(第%d轮)\n"BLK"任务目的：\n"BLK"    赚取%d贯后，带回给司库。\n"BLK"任务描述：\n"BLK"    最近%s好像经常心神不定，好象是为本门资金而烦恼。过去问问，看看能有可以帮得上忙的地方。\n"BLK"    与%s聊过后，才知道门派的金库已经所剩无几。在%s强大的威迫之下，也只好硬着头皮带着五万金额的银票下山做点小生意了。\n", 
						me->get_save_2("mastertask.time")+1, me->get_save_2("mastertask.targetxy"), name="/sys/task/quest1"->get_manager_name(me->get_fam_name()),name,name );	
				else
					result = sprintf("师门任务\n"BLK"第"HIR" %d "BLK"个任务，筹集资金任务完成，回师门禀告师傅。\n", 
						me->get_save_2("mastertask.time")+1 );								
				break;	
			case 12:
				status = me->get_save_2("mastertask.status");
				if (status==0)
					result = sprintf("师门任务\n"BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"    速去%s找王府总管，帮助其解决困难。\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装前往%s。\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name,name );	
				else
				if (status<4)				
					result = sprintf("师门任务\n"BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"  追杀%s的%s\n"BLK"%s    0/1\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装往%s出发。\n"BLK"    与%s总管见面之后，我也了解到了事态的严重性。对于叛国之徒是绝对不能轻饶的！\n"BLK"    %s总管的手下已经送来了确切信报，%s正在"HIR"%s(%d,%d)"BLK"一带逃窜。而且%s买通了那一带的山贼流氓做他的贴身保镖。\n"BLK"    为了%s的机密不被泄漏出去，权宜之计只有杀了他。\n", 
						me->get_save_2("mastertask.time")+1,id=me->get_save_2("mastertask.targetname"), name=me->get_save_2("mastertask.targetpic"),name,id,id,id,id,name,me->get_save_2("mastertask.giftname"),((z=me->get_save_2("mastertask.targetxy"))/1000),z%1000,name,id);	
				else
					result = sprintf("师门任务\n"BLK"追杀叛徒(第%d轮)\n"BLK"任务目的：\n"BLK"  追杀%s的叛徒%s\n"BLK"%s    1/1\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的紧急求助信，看来是发生了什么大事。在师傅的命令下，我整装往%s出发。\n"BLK"    与%s总管见面之后，我也了解到了事态的严重性。对于叛国之徒是绝对不能轻饶的！\n"BLK"    %s总管的手下已经送来了确切信报，%s正在"HIR"%s(%d,%d)"BLK"一带逃窜。而且%s买通了那一带的山贼流氓做他的贴身保镖。\n"BLK"    为了%s的机密不被泄漏出去，权宜之计只有杀了他。\n", 
						me->get_save_2("mastertask.time")+1,id=me->get_save_2("mastertask.targetname"), name=me->get_save_2("mastertask.targetpic"),name,id,id,id,id,name,me->get_save_2("mastertask.giftname"),((z=me->get_save_2("mastertask.targetxy"))/1000),z%1000,name,id);	
				break;	
			default:
				status = me->get_save_2("mastertask.status");
				if (status==0)
					result = sprintf("师门任务\n"BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    去%s找到王府总管，并听从其命令协助追捕刺客。\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.targetname"),name);	
				else
					result = sprintf("师门任务\n"BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    追捕已经逃窜到%s的蒙面刺客。\n"BLK"刺客首领	%d/1\n"BLK"蒙面刺客	%d/4\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n"BLK"    来到%s后，得知行刺者已经逃窜到%s后便失去了踪影。总管大人相信他们仍潜藏在%s。\n"BLK"    大人已经颁发了追杀令，一旦发现目标，格杀无论！\n", 
						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.giftname"),me->get_save_2("mastertask.y"),me->get_save_2("mastertask.x"),id=me->get_save_2("mastertask.targetname"),id,name,name);	
//				else
//					result = sprintf("师门任务\n"BLK"追捕刺客(第%d轮)\n"BLK"任务目的：\n"BLK"    追捕已经逃窜到%s的蒙面刺客。\n"BLK"刺客首领	1/1\n"BLK"蒙面刺客	4/4\n"BLK"任务描述：\n"BLK"    师傅刚刚收到了一封来自%s王府总管的来信，信中说昨晚有刺客潜入了王府企图行刺王爷。尽管最后暗杀失败，王爷也没受伤，但刺客却逃掉了。总管希望我们协助他抓拿刺客，以免后患。\n"BLK"    来到%s后，得知行刺者已经逃窜到%s后便失去了踪影。总管大人相信他们仍潜藏在%s。\n"BLK"    大人已经颁发了追杀令，一旦发现目标，格杀无论！\n", 
//						me->get_save_2("mastertask.time")+1, name=me->get_save_2("mastertask.giftname"),id=me->get_save_2("mastertask.targetname"),id,name,name);	
				break;																										
			}

//			if (time()<me->get_save_2("mastertask.endtime"))
//				result = result + BLK + sprintf("任务剩余 %d 分钟\n", (me->get_save_2("mastertask.endtime") - time()) / 60);
//			else
//				result = result + BLK + "超时未完成，任务失败。\n";
                        send_user( me, "%c%c%s", 0x51, '1', result );				
				
		}
		if (me->get_save_2("masterfight.status")>0)
                {		        
		        result = "［师门进级任务］\n"BLK"师门挑战，去练功房击败师叔即可。\n";
		        send_user( me, "%c%c%s", 0x51, '1', result );
		}
	}


        if( result == "" ) 
        {                        
                result = "您现在没有任务。\n";
                send_user( me, "%c%c%s", 0x51, '1', result );
        }

	return 1;
}
