
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>

inherit OFFICER;
string *TalkTable = ({ 
        "这年头兵荒马乱的，想找个合适的保镖都不容易……",
        "想找京都镖局护送一批货物，可是他老人家竟然没空……",
        "想找京都镖局护送亲友返乡，可是他老人家竟然没空……",
        "周国的京都镖局尉迟老镖头武艺高强，生性豪爽，真是一条好汉！",
});
void do_task_start();
void do_task_cancel();
void do_welcome(string arg);

// 函数：获取人物造型
int get_char_picid() { return 5302; }

// 函数：构造处理
void create()
{
        set_name("韩管家");
        set_city_name("韩国");


	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));

        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string tmp="";
	
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长完成
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"国" == get_city_name() )    // 找对人了
        {
		TASK_ESCORT_D->do_look_2( who, me ); 
		return ;
	}        
	

        tmp += CHAIN_D->get_chain_menu(who,me);
	send_user(who,"%c%s",':',sprintf( "%s：\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"离开"
			);

}