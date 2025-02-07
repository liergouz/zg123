
#include <npc.h>
#include <ansi.h>
#include <map.h>
#include <cmd.h>
#include <task.h>

inherit OFFICER;

void do_welcome( string arg );

// 函数：获取人物造型
int get_char_picid() { return 0950; } 

// 函数：构造处理
void create()
{
        set_name( "六道轮回(角色自杀)" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
        int status, time, id;
        string result;
        object me = this_object();
        status = who->get("xiannv.status");
        if (who->get_org_name()!="" && who->get_org_name()!=0)
        {
                send_user( who, "%c%c%w%s", ':', 3, 950,
                        sprintf("%s：\n    你还处身于帮派中，不能自杀。\n"
                        , me->get_name() ) );
                return;         
        }
//              send_user( who, "%c%c%w%s", ':', 3, 950,
//                      sprintf("%s：\n    你现在还不能自杀。\n"
//                      , me->get_name() ) );
//              return;          
        id = getoid(me);
        result = sprintf("%s：\n    你想从头再来吗？我可以帮助你。\n", me->get_name() );
	time = who->get_save("suicide");               
	if (time>0)
	{
		if (time()>time)
		{
			result = sprintf("%s：\n    你确定要自杀吗？\n", me->get_name() );
			result += sprintf(ESC "我考虑了一个星期，还是决定自杀。\ntalk %x# welcome.1\n", id);
			
		}
		else
		{
			time = time - time();
			time /= 60;
			if (time<60)			
				result = sprintf("%s：\n    你还有%d分钟就可以选择踏入六道轮回，不过你仍然有机会取消自杀的念头。你要打消自杀的念头吗？\n", me->get_name(), time );
			else
			{
				time /= 60;
				if (time<24) result = sprintf("%s：\n    你还有%d小时就可以选择踏入六道轮回，不过你仍然有机会取消自杀的念头。你要打消自杀的念头吗？\n", me->get_name(), time );
				else
				{
					time /= 24;
					result = sprintf("%s：\n    你还有%d天就可以选择踏入六道轮回，不过你仍然有机会取消自杀的念头。你要打消自杀的念头吗？\n", me->get_name(), time );
				}
			}
		}
		result += sprintf(ESC "我打消自杀的念头了。\ntalk %x# welcome.20\n", id);
	}  
	else
	{
		result += sprintf(ESC "我想从头再来，你帮帮我吧。\ntalk %x# welcome.1\n", id );
	}              
        result += ESC "我点错了，再见\nCLOSE\n";
	send_user( who, "%c%c%w%s", ':', 3, 950, result );               
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        object npc, who, *inv, obj;
        int i, flag, size, time;
        string result, name1, name2, id, order;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
                send_user( who, "%c%c%w%s", ':', 3, 950,
                        sprintf("%s：\n    从头再来的话你需要重新练级，赚取经验和钱，你愿意这样子吗？\n"
                        ESC "我决定从头再来\ntalk %x# welcome.2\n"
                        ESC "我还是考虑考虑吧\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;
        case 2:
                send_user( who, "%c%c%w%s", ':', 3, 950,
                        sprintf("%s：\n    原来的朋友可能也不认得你，你还是愿意这样做吗？\n"
                        ESC "我已经决定，你不用再劝我了\ntalk %x# welcome.3\n"
                        ESC "我还是考虑考虑吧\nCLOSE\n", me->get_name(), getoid(me) ) );
                break;
        case 3:
        	time = who->get_save("suicide");   
        	if (time==0 )
        	{
        		who->set_save("suicide", time() + 7*24*3600);
        		send_user( who, "%c%s", '!', "你需一周后重新确定自杀的决定。");
	                result = sprintf( "%s 您起了自杀的念头！", short_time(time()) );
	                who->log_legend(result);            		
        		return;
        	}
                send_user( who, "%c%s", '!', "你的游戏角色删除成功。");
                who->add_gold_log("角色自杀", 0);
                if( arrayp( who->get_team() ) ) TEAM_CMD->main( me, sprintf( "x %d", who->get_number() ) );
                result = sprintf( "%s 您自杀！", short_time(time()) );
                who->log_legend(result);         
                who->remove_from_scene();
                who->before_destruct();         
                if (who->get_fam_name()!="" && who->get_fam_name()!=0)
                        "/sys/sys/count"->add_family(who->get_fam_name(), -1);
                if( npc = who->get("soldier") )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                        who->delete("soldier");
                }

                if( arrayp( inv = who->get("zombie") ) && (size = sizeof(inv) ) )
                {                       
                        for( i = 0; i < size; i ++ ) if( inv[i] )
                        {
                                inv[i]->remove_from_scene();
                                destruct(inv[i]);                               
                        }
                        who->delete("zombie");
                }         
                time = gone_time( who->get_login_time() );
                who->set_game_time( who->get_game_time() + time );              
	        if (MAIN_D->get_host_type()==4||MAIN_D->get_host_type()==0)
	        {
	                obj = new ("/inh/user/list");
	                id = who->get_id();
	                obj->set_owner(who->get_real_id());
	                if (who->get_real_id()==id ) order = "1";
	                else order = id[<1..<1];
	                obj->delete_save_2(order);
	                obj->save();
	                name1 = obj->get_save_file();
	                name2 = name1[0..<4]+"txt";
	                rename(name1, name2);
	                destruct(obj);
	                
		}                
                // 自杀档案
                db_user_fee( who, sprintf( MAIN_D->get_php_ip()+":80\n"
                        "GET /xq2/delete.php?id=%s&start=%d&end=%d&time=%d&count=%d&region=%d&host=%d&ip=%s\r\n", 
                        rawurlencode( who->get_id() ), who->get_login_time(), who->get_login_time()+time, time, who->get_feetime(), MAIN_D->get_region(), MAIN_D->get_host(), get_ip_name(who) ) );    // 扣费！                
                if (MAIN_D->get_host_type()!=0)
                	db_user_delete(who, who->get_id());             
                destruct(who);          
                break;      
	case 20:                       
		who->set_save("suicide", 0);
		send_user( who, "%c%s", '!', "你取消了自杀的决定。");
		break;
        }
}