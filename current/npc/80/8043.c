
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;
string *TalkTable = ({ 
        "这年头兵荒马乱的，想找个合适的保镖都不容易……",
        "想找京都镖局护送一批货物，可是他老人家竟然没空……",
        "想找京都镖局护送亲友返乡，可是他老人家竟然没空……",
        "周国的京都镖局尉迟老镖头武艺高强，生性豪爽，真是一条好汉！",
});
void do_welcome(string arg);

// 函数：获取人物造型
int get_char_picid() { return 5805; }

// 函数：构造处理
void create()
{
        set_name("王满");
        set_city_name("楚国");

	set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
	set("mpLegend2",([10:({32*37+16,}),]));
        setup();
}
// 函数：对话处理
void do_look( object who ) 
{
	string tmp="";
	if ( who->get("escort.finish") == 1 )
	{
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}
        if(     who->get_quest("escort.flag")    // 运镖任务
        &&      who->get_quest("escort.leader") == 1    // 队长完成
        &&      who->get_quest("escort.name") == get_name() 
        && 	who->get_quest("escort.city")+"国" == get_city_name() )    // 找对人了
        {
		TASK_ESCORT_D->do_look_2( who, this_object() ); 
		return ;
	}        

        tmp += CHAIN_D->get_chain_menu(who,this_object());
	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
		tmp += sprintf(ESC HIY "收购珠宝\ntalk %x# welcome.1\n",getoid(this_object()));

	send_user(who,"%c%s",':',sprintf( "%s：\n    %s\n", get_name(), TalkTable[ random(sizeof(TalkTable))] ) 
			+ tmp +
			ESC"离开"
			);

}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i,amount,size;
        object who, obj, item,*inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
	 	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
			send_user(who,"%c%s",':',sprintf("%s:\n    既然是家传宝玉，不管他出多高的价格，我都不会卖的！\n"ESC"完成任务\ntalk %x# welcome.2\n"ESC"离开",me->get_name(),getoid(me)));
        	break;
        case 2:
        	if ( who->get_level() >= 10 && who->get_legend(TASK_37,15) && !who->get_legend(TASK_37,16) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;        		
			TASK_LEGEND_D->give_item(who,"item/final/33/1701",2);
        		TASK_LEGEND_D->task_finish(who);
        		who->set_legend(TASK_37,16);
			who->add_exp(300);
			who->add_potential(30);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"收购珠宝 经验 300 潜能 30 金钱 1000 烤地瓜 2");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_CHUGUO,42,"" );
        	}
        	break;
 
        }
}