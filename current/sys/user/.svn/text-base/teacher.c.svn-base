#include <ansi.h>
#include <cmd.h>
#include <task.h>
static string *nTudi = ({"baishi.tudi","baishi.tudi1","baishi.tudi2","baishi.tudi3"});

void baishi(object me ,object who,object user);
object check_baishi(object me ,object who);
object check_chushi(object me ,object who);
void chushi(object me ,object who,object user);
void dissolve1(object me ,object who);
void dissolve2(object me ,object who);
void query_shifu(object me,object who);
void dissolve1_list(object me,object who);
void dissolve2_list(object me,object who);
void dissolve1_tudi(object me ,object who,int id);
void dissolve2_tudi(object me ,object who,int id);
void dissolve1_shifu(object me ,object who);
void dissolve2_shifu(object me ,object who);
void query_tudi(object me,object who,int id);
void query_tudi_list(object me,object who);

// 函数：生成二进制码
void SAVE_BINARY() { }
//判断是否师傅
int is_shifu(object who)
{
	int i,size;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( mapp(who->get_save_2(nTudi[i])) )
			return 1;
	}	
	return 0;
}
//判断是否徒弟
int is_tudi(object who)
{
	return mapp(who->get_save_2("baishi.shifu"));
}
void do_look(object who,object me)
{
	int id;
	string tmp="";
	id = getoid(me);
	if ( is_shifu(who) )
	{
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_1") != 1)
			tmp = sprintf(ESC HIY "拜访\ntalk %x# welcome.21\n",id);
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    师者，传道授业解惑也！为师者只有立师志、修师德、练师功、树师表,才能切实担负起育才的重任。有朝一日，你若为人师，一定要悉心教导你的徒弟，使他早日成材！\n"
			+ tmp
			+ sprintf(ESC"了解拜师\ntalk %x# welcome.1\n",id)
			+ sprintf(ESC"我带徒弟来举行拜师仪式\ntalk %x# welcome.2\n",id)
			+ sprintf(ESC"我带徒弟来举行出师仪式\ntalk %x# welcome.3\n",id)
			+ sprintf(ESC"我想查询一下我的教育记录\ntalk %x# welcome.4\n",id)
			+ sprintf(ESC"我想来解除师徒关系\ntalk %x# welcome.5\n",id)
			+ sprintf(ESC"查询徒弟在线时间记录\ntalk %x# welcome.6\n",id)
			+ sprintf(ESC"领取师徒奖励\ntalk %x# welcome.19\n",id)
			+ESC"离开"
			 );	
	}
	else if ( is_tudi(who) )
	{
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_1") != 1)
			tmp = sprintf(ESC HIY "拜访\ntalk %x# welcome.21\n",id);
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    师者，传道授业解惑也！为师者只有立师志、修师德、练师功、树师表,才能切实担负起育才的重任。有朝一日，你若为人师，一定要悉心教导你的徒弟，使他早日成材！\n"
			+ tmp
			+ sprintf(ESC"了解拜师\ntalk %x# welcome.1\n",id)
			+ sprintf(ESC"我想来解除师徒关系\ntalk %x# welcome.5\n",id)
			+ sprintf(ESC"查询师傅在线时间记录\ntalk %x# welcome.6\n",id)
			+ sprintf(ESC"领取师徒奖励\ntalk %x# welcome.19\n",id)
			+ESC"离开"
			 );
	}
	else
	{
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_1") != 1)
			tmp = sprintf(ESC HIY "拜访\ntalk %x# welcome.21\n",id);
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    师者，传道授业解惑也！为师者只有立师志、修师德、练师功、树师表,才能切实担负起育才的重任。有朝一日，你若为人师，一定要悉心教导你的徒弟，使他早日成材！\n"
			+ tmp
			+ sprintf(ESC"了解拜师\ntalk %x# welcome.1\n",id)
			+ sprintf(ESC"我带徒弟来举行拜师仪式\ntalk %x# welcome.2\n",id)
			+ sprintf(ESC"我带徒弟来举行出师仪式\ntalk %x# welcome.3\n",id)
			+ sprintf(ESC"我想查询一下我的教育记录\ntalk %x# welcome.4\n",id)
			+ sprintf(ESC"我要寻求师傅\ntalk %x# welcome.14\n",id)
			+ sprintf(ESC"领取师徒奖励\ntalk %x# welcome.19\n",id)
			+ESC"离开"
			 );
	}
}


void do_welcome( object me, object who,string arg )
{
        int flag,i,size,id,exp,pot,max,exp1,pot1;
        string *name,tmp,*nTmp, username;
        object user;
        if ( !arg )
        	return ;
        nTmp = explode(arg,".");
        flag = to_int(nTmp[0]);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
	case 1:
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    拜师需要二人处于组队状态，由师傅当队长，二者一定要在老夫的视线范围之内。师傅所需等级大于等于40级；徒弟所需等级小于等于30级。拜师之后，徒弟须满40级方可出师；出师的时候也须由师傅带着徒弟来老夫这里举行出师仪式。徒弟出师之日，老夫会给予师傅和徒弟丰厚的奖励以表彰师傅的辛勤教导和徒弟的勤奋好学～！\n");
		break;
	case 2:
		if ( !objectp(user=check_baishi(me,who)) )
			return ;
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s\n    你现在可以收%s作为你的徒弟，老夫希望你能悉心教导你的徒弟，尽到为师之责！\n",me->get_name(),user->get_name())
			+ sprintf(ESC"确定\ntalk %x# welcome.7\n"ESC"离开",getoid(me)));
		who->set("baishi.tudi",user);
		break;	
	case 3:
		if ( !objectp(user=check_chushi(me,who)) )
			return ;
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s\n    由于你悉心的教导，你的徒弟现在已经能独立解决自己所遇到的困难。恭喜！你的徒弟现在可以出师啦！\n",me->get_name())
			+ sprintf(ESC"确定\ntalk %x# welcome.8\n"ESC"离开",getoid(me)));

		break;
	case 4:
		name = who->get_apprentice();
		if ( (size=sizeof(name)) == 0 )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你没有教育过徒弟！");
			return;
		}
		tmp=name[0];
		for(i=1;i<size;i++)
		{
			tmp += "、"+name[i];
		}
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你所教育过的徒弟有"+tmp+"。");
		break;
	case 5:
		if ( is_tudi(who) )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+":\n    师徒之情，来之不易啊！你真的想解除师徒关系吗？倘若连续7天你的师傅没有来看望你，我会免费替你解除师徒关系。除此之外，你如果想强行解除师徒关系，就必须交纳200000金手续费。\n"
				+ sprintf(ESC"和平解除师徒关系\ntalk %x# welcome.9\n",getoid(me))
				+ sprintf(ESC"强行解除师徒关系\ntalk %x# welcome.10\n",getoid(me))
				+ESC"离开");
		else if ( is_shifu(who) )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+":\n    师徒之情，来之不易啊！你真的想解除师徒关系吗？倘若连续7天你的徒弟没有来看望你，我会免费替你解除师徒关系。除此之外，你如果想解除师徒关系，就必须交纳500000金手续费。\n"
				+ sprintf(ESC"和平解除师徒关系\ntalk %x# welcome.9\n",getoid(me))
				+ sprintf(ESC"强行解除师徒关系\ntalk %x# welcome.10\n",getoid(me))
				+ESC"离开");
		
		break;
	case 6:
		if ( is_tudi(who) )
			query_shifu(me,who);
		else
			query_tudi_list(me,who);
		break;
	case 7:
		if ( !objectp(user=check_baishi(me,who)) )
			return ;
		send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s:\n    你愿意做%s的徒弟吗？\n",me->get_name(),who->get_name())
			+ sprintf(ESC"确定\ntalk %x# welcome.13\n"ESC"离开",getoid(me)));
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请等待对方确认。");
		user->set("baishi.shifu",who);
		break;
	case 8:
		if ( !objectp(user=check_chushi(me,who)) )
			return ;
		chushi(me,who,user);
		break;
	case 9:		//和平解除
		if ( who->get_save_2("baishi.shifu") )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+":\n    你是否愿意和你的师傅和平解除师徒关系～！\n"
				+ sprintf(ESC"确定\ntalk %x# welcome.11\n",getoid(me))
				+ESC"离开");
		else 
			dissolve1_list(me,who);
		break;
	case 10:	//强行解除
		if ( is_tudi(who) )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+":\n    你是否愿意和你的师傅强行解除师徒关系～！\n"
				+ sprintf(ESC"确定\ntalk %x# welcome.12\n",getoid(me))
				+ESC"离开");
		else 
			dissolve2_list(me,who);
		break;
	case 11:
		dissolve1_shifu(me,who);
		break;
	case 12:
		dissolve2_shifu(me,who);
		break;
	case 13:
		user = who;
		who = user->get("baishi.shifu");
		if ( !objectp(who) )
			return ;
		if ( user != who->get("baishi.tudi") )
			return ;
		who->delete("baishi.tudi");
		user->delete("baishi.shifu");
		if ( !objectp(user=check_baishi(me,who)) )
			return ;
		baishi(me,who,user);
		break;
	case 14:
		if ( is_tudi(who) )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已经拜师了，不需要另外的师傅来教导！\n");
		else if ( who->get_level() > 30 )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已经能独立思考及解决自己所面对的困难，以老夫来看，你不需要师傅来教导！\n");
		else
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    老夫见你不谙世事，可以帮你寻求一名师傅。至于能否寻到，那要看你的造化！\n" +
				sprintf(ESC"发出寻师信息\ntalk %x# welcome.15\n"ESC"离开",id)
			);
		
		break;
	case 15:		//发寻师信息
		if ( gone_time(who->get("baishi.shout")) < 120 )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请过一会儿，再来发出请求信息～！\n");
			return;
		}
		who->set("baishi.shout",time());
		username = sprintf("%c+%d,%s=%d%c-", '\t', 0xffffff, who->get_name(), who->get_number(), '\t');
		CHAT_D->sys_channel(0,sprintf(HIR"%s（%d）天资聪慧、初入战国，想寻求一名师傅来教导他。有意者请与其本人联络！",username,who->get_number()));
		break;
	case 16:
		dissolve1_tudi(me,who,to_int(nTmp[1]));
		break;
	case 17:
		dissolve2_tudi(me,who,to_int(nTmp[1]));
		break;
	case 18:
		query_tudi(me,who,to_int(nTmp[1]));
		break;
	case 19:
		exp = who->get_save_2("shitu.exp");
		pot = who->get_save_2("shitu.pot");
		if ( !exp && !pot )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你不符合领取奖励条件！\n");
			return ;	
		}
		if( who->get_online_rate() != 100 )
		{
			send_user(who,"%c%s",'!',"你现在是非健康游戏时间，不能领取！");
			return;
		}
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+sprintf(":\n    你现在有%d点经验和%d点潜能的奖励可以领取。是否领取？\n",exp,pot)
			+ sprintf(ESC"领取奖励\ntalk %x# welcome.20\n",getoid(me))
			+ESC"离开");		
		break;
	case 20:
		exp = who->get_save_2("shitu.exp");
		pot = who->get_save_2("shitu.pot");
		if ( !exp && !pot )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你不符合领取奖励条件！\n");
			return ;	
		}
		if( who->get_online_rate() != 100 )
		{
			send_user(who,"%c%s",'!',"你现在是非健康游戏时间，不能领取！");
			return;
		}
		max = USER_EXP_D->get_upgrade_exp_limit(who);	//经验上限
		if ( exp && (exp1=max - who->get_upgrade_exp()) > 0 )
		{
			if ( exp1 <= exp )
			{
				send_user(who,"%c%s",'!',"你的经验已达到上限，希望你尽快处理，否则你将无法领取相应经验奖励！");
				exp = exp1;
			}
			else
				exp1 = 0;
			who->add_save_2("shitu.exp",-exp);
			who->add_exp(exp);	
		        who->add_log("&baishi", exp);
		}
		else if ( exp && exp1 <= 0 )
		{
			send_user(who,"%c%s",'!',"你的经验已达到上限，希望你尽快处理，否则你将无法领取相应经验奖励！");
			exp = 0;	
		}
		max = who->get_max_potential();		//最大潜能
		if ( pot && (pot1=max - who->get_potential()) > 0 )
		{
			if ( pot1 <= pot )
			{
				send_user(who,"%c%s",'!',"你的潜能已达到上限，希望你尽快处理，否则你将无法领取相应潜能奖励！");
				pot = pot1;
			}
			else
				pot1 = 0;
			who->add_save_2("shitu.pot",-pot);
			who->add_potential(pot);	
		        who->add_log("&potential", pot);
		}
		else if ( pot && pot1 <= 0 )
		{
			send_user(who,"%c%s",'!',"你的潜能已达到上限，希望你尽快处理，否则你将无法领取相应潜能奖励！");
			pot = 0;
		}
		if ( exp && pot )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+sprintf(":\n    你领取了%d点经验和%d点潜能的奖励\n",exp,pot)
				+ESC"离开");
		else if ( exp )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+sprintf(":\n    你领取了%d点经验的奖励\n",exp)
				+ESC"离开");
		else if ( pot )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				me->get_name()+sprintf(":\n    你领取了%d点潜能的奖励\n",pot)
				+ESC"离开");
		
		break;
        case 21:
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_1") != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    大王叫你来拜访我吗？你可以看看现在和将来在我这会有什么需要的，呵呵。年轻人，有朝气，真好啊。\n", me->get_name()));
			who->set_save("baifang_ms_1",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,21);
		}
		if ( who->get_save("baifang_ms_1") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_3") == 1 && who->get_save("baifang_ms_4") == 1 && who->get_save("baifang_ms_5") == 1 )
		{
			who->set_legend(TASK_2_00,24);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,21,"访问周国名士(完成)" );
		}
        	break;
	}
}
//拜师检查
object check_baishi(object me ,object who)
{
	int i,size;
	object *team,user;
	string leader;
	
	if ( who->get_level() < 40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    老夫见你的品德修为目前还不到火候，你还是再磨练几年再来授学为师吧！");
		return 0;
	}
	if ( who->get_save_2("baishi.shifu") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你还没出师，怎么能做师傅呢！");
		return 0;
	}
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i]) ) )
			break;
	}
	if ( i >= size )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的徒弟还没有出师，你不能再次收徒！作为师傅你一定要尽职尽责！");
		return 0;
	}
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你一人前来探访老夫有何贵干？是想和老夫探讨为师之道还是儒学之道？");
		return 0;
	}
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    这么多人来找老夫所为何事？老夫最近在思索一个深奥的问题，倘若不是为学问之事而来，还望各位离开！");
		return;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    拜师需要二人处于组队状态，由师傅当队长，二者一定要在老夫的视线范围之内。");
		return 0;
	}
	team -= ({ who });
	user = team[0];

	if ( user->get_level() > 30 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你所想收的徒弟，他已经能独立思考和解决其所面对的困难，目前他不需要你的教导！");
		return 0;
	}
	if ( user->get_save_2("baishi.shifu") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你所想收的徒弟虽然筋骨精奇，但是可惜已经另有明师！");
		return 0;
	}
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你将要收的徒弟呢？他在哪呢？拜师仪式哪有徒弟不在场的？快去将你的徒弟寻来再说。");
		return 0;
	}
	return user;	
}
//拜师
void baishi(object me ,object who,object user)
{
	int i,size;
	string cTudi;
	
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i]) ) )
			break;
	}
	if ( i >= size )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的徒弟还没有出师，你不能再次收徒！作为师傅你一定要尽职尽责！");
		return ;
	}
	cTudi = nTudi[i];
	who->set_save_2(cTudi+".name",user->get_name());
	who->set_save_2(cTudi+".id",user->get_number());
	who->set_save_2(cTudi+".account",user->get_id());
	who->set_save_2(cTudi+".level",user->get_level());
	
	user->set_save_2("baishi.shifu.name",who->get_name());
	user->set_save_2("baishi.shifu.id",who->get_number());
	user->set_save_2("baishi.shifu.account",who->get_id());
	user->set_save_2("baishi.shifu.level",who->get_level());
	
	who->add_title("B001");	
	user->add_title("B002");
	
	CHAT_D->chat_channel(0,sprintf(HIR"%s"HIY"收"HIR"%s"HIY"为徒，希望"HIR"%s"HIY"以后能悉心教导徒弟！",who->get_name(),user->get_name(),who->get_name()));	
	log_file("baishi.txt",sprintf("%s %s(%d) %s(%d) 拜师\n",short_time(),who->get_name(),who->get_number(),user->get_name(),user->get_number()));
	who->log_legend( sprintf("您收%s(%d)为徒弟。", user->get_name(),user->get_number()) );
	user->log_legend( sprintf("您拜%s(%d)为师傅。", who->get_name(),who->get_number()) );
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    恭喜你收了一位高徒。");
}
//出师检查
object check_chushi(object me ,object who)
{
	int i,size;
	object *team,user;
	string leader,cTudi;
	
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你一人前来探访老夫有何贵干？是想和老夫探讨为师之道还是儒学之道？");
		return 0;
	}
	team -= ({0});
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    这么多人来找老夫所为何事？老夫最近在思索一个深奥的问题，倘若不是为学问之事而来，还望各位离开！");
		return;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    出师需要二人处于组队状态，由师傅当队长，二者一定要在老夫的视线范围之内。");
		return 0;
	}
	team -= ({ who });
	user = team[0];
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
//		原来的代码
//		if ( !mapp(who->get_save_2(nTudi[i])) || who->get_save_2(nTudi[i]+".id") != user->get_number() )
//			continue;

		//修改上面的代码，以便修正以前的bug导致师父身上缺少徒弟数据不能出师的问题。
		if ( !mapp(who->get_save_2(nTudi[i])) || who->get_save_2(nTudi[i]+".id") != user->get_number() )
		{
			if (user->get_save_2("baishi.shifu.account")==who->get_id()
			&&  user->get_save_2("baishi.shifu.name")==who->get_name()
			&&  user->get_save_2("baishi.shifu.id")==who->get_number() )
			{
				break;
			}
			else
				continue;
		}
		//修改完毕。
		break;
	}
	if ( i >= size )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你将要出师的徒弟呢？他在哪呢？出师仪式哪有徒弟不在场的？快去将你的徒弟寻来再说。");
		return 0;
	}
	if ( user->get_level() < 40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你所教导的徒弟目前还不够出师的资格。为师者，不能浮躁，一定要悉心教导啊！");
		return 0;
	}
	if ( user->get_save_2("baishi.shifu.id") != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    对方并不是你的徒弟！");
		return 0;
	}
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的徒弟呢？他在哪呢？出师仪式哪有徒弟不在场的？快去将你的徒弟寻来再说。");
		return 0;
	}
	if ( user->get_online_rate() != 100 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你所教导的徒弟目前处于非健康游戏时间，不能出师");
		return 0;
	}
	if ( who->get_online_rate() != 100 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你目前处于非健康游戏时间，不能出师");
		return 0;
	}
	return user;	
}
//出师
void chushi(object me ,object who,object user)
{
	int i,level,size,j,size1,size2,bonus_exp;
	string fam_name1,fam_name2,tmp1,tmp2,cTudi;
	int *nSkill=({});
	object fileobj;

	if (user->get_save_2("baishi.shifu.account")!=who->get_id()
	||  user->get_save_2("baishi.shifu.name")!=who->get_name()
	||  user->get_save_2("baishi.shifu.id")!=who->get_number() )
		return;

	j = -1;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) )
			continue;
		if ( who->get_save_2(nTudi[i]+".id") != user->get_number() )
			continue;
		j = i;
		break;
	}
	
	(j>=0)?cTudi = nTudi[j]:cTudi = "";
		
	if ( user->get_save_2("baishi.shifu.level") )	
		bonus_exp = 170000;
	else
		bonus_exp = 400000;		//新出师奖励规则之前拜师的
	if (cTudi!="")	who->delete_save_2(cTudi);
		
	user->set_save_2("chushi",user->get_save_2("baishi.shifu"));
	user->delete_save_2("baishi");

	who->delete_title("B001");
	user->delete_title("B002");
	who->add_title("B003");	
	size1 = sizeof(who->get_apprentice());
	who->add_apprentice(user->get_name());
	size2 = sizeof(who->get_apprentice());
	if ( size1==9 && size2==10 )
	{
		who->add_title("B004");
		MAILBOX->sys_mail(who->get_id(),who->get_number(),"由于辛勤耕耘，所教之徒遍布天下，周王特赋予你“桃李天下”的称谓奖励！");
	}
		
	//奖励
	who->add_bonus(500);
	who->add_exp(bonus_exp);
	fam_name1 = who->get_fam_name();
	nSkill = SKILL->get_bonus_skill(who);	//可以加的技能
	if ( sizeof(nSkill) >= 2 )
	{
		i = nSkill[random(sizeof(nSkill))];
		nSkill -= ({ i });
		fileobj = load_object(SKILL->get_skill_file(i));
		if (!fileobj) return;	
		tmp1 = fileobj->get_name();
		who->set_skill(i,who->get_skill(i)+1);
		i = nSkill[random(sizeof(nSkill))];
		who->set_skill(i,who->get_skill(i)+1);
		fileobj = load_object(SKILL->get_skill_file(i));
		if (!fileobj) return;	
		tmp2 = fileobj->get_name();
		send_user(who,"%c%s",';',sprintf("您获得了%d功德点、%d经验值、%s技能提升了一级、%s技能提升了一级。",50,bonus_exp,tmp1,tmp2));
	}
	if ( sizeof(nSkill) == 1 )
	{
		i = nSkill[random(sizeof(nSkill))];
		nSkill -= ({ i });
		fileobj = load_object(SKILL->get_skill_file(i));
		if (!fileobj) return;	
		tmp1 = fileobj->get_name();
		who->set_skill(i,who->get_skill(i)+1);
		send_user(who,"%c%s",';',sprintf("您获得了%d功德点、%d经验值、%s技能提升了一级。",50,bonus_exp,tmp1,));
	}
	else
		send_user(who,"%c%s",';',sprintf("您获得了%d功德点、%d经验值。",50,bonus_exp,));
	user->add_exp(200000);
	fam_name1 = user->get_fam_name();
	nSkill = SKILL->get_bonus_skill(user);
	tmp1 = "";
	if ( sizeof(nSkill) >= 1 )
	{
		i = nSkill[random(sizeof(nSkill))];
		fileobj = load_object(SKILL->get_skill_file(i));
		if (!fileobj) return;	
		tmp1 = fileobj->get_name();
		if ( i )
			user->set_skill(i,user->get_skill(i)+1);
		send_user(user,"%c%s",';',sprintf("您获得了%d经验值、%s技能提升了一级。",200000,tmp1));
	}
	else
		send_user(user,"%c%s",';',sprintf("您获得了%d经验值。",200000));
	log_file("baishi.txt",sprintf("%s %s(%d) %s(%d) 出师\n",short_time(),who->get_name(),who->get_number(),user->get_name(),user->get_number()));
	who->log_legend( sprintf("您的徒弟%s(%d)出师了。", user->get_name(),user->get_number()) );
	user->log_legend( sprintf("您从师傅%s(%d)那里出师了。", who->get_name(),who->get_number()) );
	
}
//查询师傅
void query_shifu(object me,object who)
{
	int iFlag,id,iTime,i,size;
	string tmp;
	string account;
	object user,user1;
	mapping mpTmp;
	
	if ( gone_time(who->get("baishi.query")) < 3 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请过一会儿再来查询～！\n");
		return;
	}	
	who->set("baishi.query",time());
	if ( !(mpTmp = who->get_save_2("baishi.shifu")) )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你想和老夫探讨为师之道还是儒学之道？");
		return ;		
	}
	id = mpTmp["id"];
	account = mpTmp["account"];	
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	else
		iFlag = 1;
        if( objectp(user) ) 
        {
		for(i=0,size=sizeof(nTudi);i<size;i++)
		{
			if ( !mapp(user->get_save_2(nTudi[i])) )
				continue; 
			if ( user->get_save_2(nTudi[i]+".id") != who->get_number() )
				continue;
			break;
		}
        	if ( i >= size )
        		iFlag = -1 ;
         }
	else
		iFlag = -1;        //不存在
	iTime = gone_time(user->get_quit_time());
	if( objectp(user1) ) 
		destruct(user1);
	if ( iFlag == -1 )
		return ;
	if ( iFlag == 1 )
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的师傅现在游戏中！");
	else
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+sprintf(":\n    你的师傅%d天没看你了～！",iTime/(3600*24)+1));

}
//徒弟和平解除师徒关系
void dissolve1_shifu(object me ,object who)
{
	int iFlag,iTime,id,i,size,j,count;
	string account,tmp,name;
	mapping mpTmp;
	object user,user1;
	
	mpTmp = who->get_save_2("baishi.shifu");
	if ( !mpTmp )
		return ;
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
        if( objectp(user) ) 
        {
		j = -1 ;
		for(i=0,size=sizeof(nTudi);i<size;i++)
		{
			if ( !mapp(user->get_save_2(nTudi[i])) ) 
				continue;
			count++;
			if ( user->get_save_2(nTudi[i]+".id") != who->get_number() )
				continue;
			j = i;
		}
		if ( j == -1 )	//对方没有这样的徒弟
			iTime = -1;
		else if ( user1 )	//对方不在线
			iTime = gone_time(user1->get_quit_time()); 
        }
        else
        	iTime = -1;		
        if ( iTime != -1 && iTime < 3600*24*6 )
        {
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+sprintf(":\n    你的师傅连续不在线时间小于7天，你不能和你的师傅和平解除师徒关系～！",tmp,tmp));
		if( objectp(user1) ) 
			destruct(user1);
        	return ;
        }
	who->delete_title("B002");
	who->delete_save_2("baishi");
	who->log_legend( sprintf("您和师傅%s(%d)解除师徒关系。", name,id) );
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已将师徒关系解除～！");
	if ( j != -1 )	//清除师傅中的徒弟信息
	{
		if ( count == 1 )
		{
			user->delete_title("B001");
			user->delete_save_2("baishi");
		}
		else
			user->delete_save_2(nTudi[j]);
		MAILBOX->sys_mail(account,id,"您的徒弟"+ who->get_name()+"已经和您和平解除师徒关系～！");
		user->log_legend( sprintf("您的徒弟%s(%d)和您解除师徒关系。", who->get_name(),who->get_number()) );
	}
	if( objectp(user1) ) 
	{
		user1->save();
		destruct(user1);
	}
	log_file("baishi.txt",sprintf("%s 徒弟 %s(%d) 与 师傅 %s(%d) 和平解除师徒关系\n",short_time(),who->get_name(),who->get_number(),name,id));
}
//师傅和平解除指定ID的徒弟的师徒关系
void dissolve1_tudi(object me ,object who,int id)
{
	int iFlag,iTime,i,j,count,size;
	string account,tmp,titlecode,name;
	mapping mpTmp;
	object user,user1;
	
	j = -1;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) ) 
			continue;
		count++;
		if ( who->get_save_2(nTudi[i]+".id") != id )
			continue;
		j = i;
	}
	if ( j == -1 )
		return;
	mpTmp = who->get_save_2(nTudi[j]);
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
		iTime = gone_time(user1->get_quit_time());
	}
        if( objectp(user) ) 
        {
        	if ( user->get_save_2("baishi.shifu.id") != who->get_number() )
        		iTime = -1 ;
        	else if ( user1 )	//对方不在线
        		iTime = gone_time(user->get_quit_time());        	
        }
	else
		iTime = -1;        //不存在
        if ( iTime != -1 && iTime < 3600*24*6 )
        {
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的徒弟"+ user->get_name() +"连续不在线时间小于7天，你不能和你的徒弟和平解除师徒关系～！");
		if( objectp(user1) ) 
			destruct(user1);
        	return ;
        }
	if ( count == 1 )
	{
		who->delete_title("B001");
		who->delete_save_2("baishi");
	}
	else
		who->delete_save_2(nTudi[j]);
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已将师徒关系解除～！");
	who->log_legend( sprintf("您和%s(%d)解除师徒关系。", name,id) );
	if ( user )
	{
		user->delete_title("B002");
		user->delete_save_2("baishi");
		MAILBOX->sys_mail(account,id,"您的师傅"+ who->get_name()+"已经和您和平解除师徒关系～！");
		user->log_legend( sprintf("您的徒弟%s(%d)和您解除师徒关系。", who->get_name(),who->get_number()) );
	}
	if( objectp(user1) ) 
	{
		user1->save();
		destruct(user1);
	}
	log_file("baishi.txt",sprintf("%s 师傅 %s(%d) 与 徒弟 %s(%d) 和平解除师徒关系\n",short_time(),who->get_name(),who->get_number(),name,id));
}
//徒弟强行解除师徒关系
void dissolve2_shifu(object me ,object who)
{
	int iFlag,iTime,id,i,size,j,count,fee;
	string account,tmp,name;
	mapping mpTmp;
	object user,user1;
	
	mpTmp = who->get_save_2("baishi.shifu");
	if ( !mpTmp )
		return ;
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	j = -1;
	if ( user )	//清除师傅中的徒弟信息
	{
		for(i=0,size=sizeof(nTudi);i<size;i++)
		{
			if ( !mapp(user->get_save_2(nTudi[i])) ) 
				continue;
			count++;
			if ( user->get_save_2(nTudi[i]+".id") != who->get_number() )
				continue;
			j = i;
		}
	}
	if ( j != -1 )	//对方没有解除关系
	{
		fee = who->get_cash()-200000;
		if ( fee < 0 )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的金钱不足，师徒关系无法解除！");
			if( objectp(user1) ) 
				destruct(user1);
			return ;
		}		
		who->add_cash(-20000);
	}
	who->delete_title("B002");
	who->delete_save_2("baishi");
	who->log_legend( sprintf("您和师傅%s(%d)解除师徒关系。", name,id) );
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已将师徒关系解除～！");
	if ( j != -1 )	//清除师傅中的徒弟信息
	{
		if ( count == 1 )
		{
			user->delete_title("B001");
			user->delete_save_2("baishi");
		}
		else
			user->delete_save_2(nTudi[j]);
		MAILBOX->sys_mail(account,id,"您的徒弟"+ who->get_name()+"已经和您强行解除师徒关系～！");
		user->log_legend( sprintf("您的徒弟%s(%d)和您解除师徒关系。", who->get_name(),who->get_number()) );
	}
	if( objectp(user1) ) 
	{
		user1->save();
		destruct(user1);
	}
	log_file("baishi.txt",sprintf("%s 徒弟 %s(%d) 与 师傅 %s(%d) 强行解除师徒关系\n",short_time(),who->get_name(),who->get_number(),name,id));
}
//师傅强行解除指定ID的徒弟的师徒关系
void dissolve2_tudi(object me ,object who,int id)
{
	int iFlag,iTime,i,j,count,size,fee;
	string account,tmp,titlecode,name;
	mapping mpTmp;
	object user,user1;
	
	j = -1;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) )
			continue; 
		count++;
		if ( who->get_save_2(nTudi[i]+".id") != id )
			continue;
		j = i;
	}
	if ( j == -1 )
		return;
	mpTmp = who->get_save_2(nTudi[j]);
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	if ( objectp(user) && user->get_save_2("baishi.shifu.id") == who->get_number() )	//对方没有解除关系
	{
		fee = who->get_cash()-500000;
		if ( fee < 0 )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的金钱不足，师徒关系无法解除！");
			if( objectp(user1) ) 
				destruct(user1);
			return ;
		}		
		who->add_cash(-50000);
	}
	if ( count == 1 )
	{
		who->delete_title("B001");
		who->delete_save_2("baishi");
	}
	else
		who->delete_save_2(nTudi[j]);
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已将师徒关系解除～！");
	who->log_legend( sprintf("您和%s(%d)解除师徒关系。", name,id) );
	if ( user )
	{
		user->delete_title("B002");
		user->delete_save_2("baishi");
		MAILBOX->sys_mail(account,id,"您的师傅"+ who->get_name()+"已经和您强行解除师徒关系～！");
		user->log_legend( sprintf("您的师傅%s(%d)和您解除师徒关系。", who->get_name(),who->get_number()) );
	}
	if( objectp(user1) ) 
	{
		user1->save();
		destruct(user1);
	}
	log_file("baishi.txt",sprintf("%s 师傅 %s(%d) 与 徒弟 %s(%d) 强行解除师徒关系\n",short_time(),who->get_name(),who->get_number(),name,id));
}
//和平解除徒弟列表
void dissolve1_list(object me,object who)
{
	int i,size,id;
	string result;
	mapping mpTmp;
	
	id = getoid(me);
	result = sprintf("%s\n    请选择你要与之和平解除师徒关系的徒弟：\n",me->get_name());
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(mpTmp=who->get_save_2(nTudi[i])) ) 
			continue;
		result += sprintf(ESC"%s\ntalk %x# welcome.16.%d\n",mpTmp["name"],id,mpTmp["id"]);
	}
	result += ESC"离开";
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),result);
}

//强行解除徒弟列表
void dissolve2_list(object me,object who)
{
	int i,size,id;
	string result;
	mapping mpTmp;
	
	id = getoid(me);
	result = sprintf("%s\n    请选择你要与之强行解除师徒关系的徒弟：\n",me->get_name());
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(mpTmp=who->get_save_2(nTudi[i])) ) 
			continue;
		result += sprintf(ESC"%s\ntalk %x# welcome.17.%d\n",mpTmp["name"],id,mpTmp["id"]);
	}
	result += ESC"离开";
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),result);
}
//查询徒弟列表
void query_tudi_list(object me,object who)
{
	int i,size,id;
	string result;
	mapping mpTmp;
	
	id = getoid(me);
	result = sprintf("%s\n    请选择你要查询的徒弟：\n",me->get_name());
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(mpTmp=who->get_save_2(nTudi[i])) ) 
			continue;
		result += sprintf(ESC"%s\ntalk %x# welcome.18.%d\n",mpTmp["name"],id,mpTmp["id"]);
	}
	result += ESC"离开";
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),result);
}
//查询徒弟
void query_tudi(object me,object who,int id)
{
	int iFlag,iTime,i,size,j;
	string tmp;
	string account,name;
	object user,user1;
	mapping mpTmp;

	if ( gone_time(who->get("baishi.query")) < 3 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请过一会儿再来查询～！\n");
		return;
	}	
	who->set("baishi.query",time());
	j = -1;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) )
			continue; 
		if ( who->get_save_2(nTudi[i]+".id") != id )
			continue;
		j = i;
	}
	if ( j == -1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你想和老夫探讨为师之道还是儒学之道？");
		return ;		
	}
	mpTmp = who->get_save_2(nTudi[j]);
	id = mpTmp["id"];
	account = mpTmp["account"];	
	name = mpTmp["name"];	
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	else
		iFlag = 1;
        if( !objectp(user) ) 
		return ;        //不存在
	iTime = gone_time(user->get_quit_time());
	if( objectp(user1) ) 
		destruct(user1);
	if ( iFlag == -1 )
		return ;
	if ( iFlag == 1 )
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+sprintf(":\n    你的徒弟%s现在游戏中！",name));
	else
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+sprintf(":\n    你的徒弟%s已经有%d天没看你了～！",name,iTime/(3600*24)+1));

}
//徒弟升级，师傅用友好度换的经验
void add_friend_bonus(object user, object who, int level)
{
	int i,j,size,exp,*nTmp;
	string cTudi,cTmp;
	
	if ( level == 10 )
		exp = 200000;
	else if ( level == 20 )
		exp = 500000;
	else if ( level == 30 )
		exp = 1000000;
	else if ( level == 40 )
		exp = 2000000;		
	else
		return ;	
	j = -1;
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) )
			continue;
		if ( who->get_save_2(nTudi[i]+".id") != user->get_number() )
			continue;
		j = i;
		break;
	}
	if ( j == -1 )
		return;	
	cTudi = nTudi[j];
	nTmp = who->get_save_2(cTudi+".friend_bonus");
	if ( sizeof(nTmp) == 0 )
		nTmp = ({});
	if ( member_array(level,nTmp) == -1 )
		nTmp += ({ level });
	who->set_save_2(cTudi+".friend_bonus",nTmp);
	nTmp = user->get_save_2("baishi.shifu.friend_bonus");
	if ( sizeof(nTmp) == 0 )
		nTmp = ({});
	if ( member_array(level,nTmp) == -1 )
		nTmp += ({ level });
	user->set_save_2("baishi.shifu.friend_bonus",nTmp);
	MAILBOX->sys_mail(who->get_id(),who->get_number(),sprintf(BLK"由于你的徒弟"HIR"%s"BLK"勤奋好学，实力更进一层，新手村的老村长（150，98）特别嘉奖"HIR"%d经验"BLK"给你，还望你前去办理领取手续，徒弟出师之前若不领取奖励，则出师后奖励将不在给予！",user->get_name(),exp));
	cTmp = who->get_name();
	CHAT_D->sys_channel(0,sprintf(HIG"由于%s（%d）的徒弟勤奋好学，实力更进一层，新手村的老村长（150，98）特别奖励%s玩家%d经验！",cTmp,who->get_number(),cTmp,exp));
}

//徒弟升级的奖励
int add_shifu_exp(object who, int exp)
{
	int id,max,exp1,pot,level,level1,flag,iSave;
	string account,name;
	mapping mpTmp;
	object user,user1;
	
	if ( mapp(mpTmp=who->get_save_2("baishi.shifu")) )	//出师前升级
		flag = 1;
	else if ( mapp(mpTmp=who->get_save_2("chushi")) )	//出师后升级
		flag = 2;
	else
		return 0;
	id = mpTmp["id"];
	account = mpTmp["account"];
	name = mpTmp["name"];
	if( !objectp(user = find_player( sprintf( "%d", id ))) && user_exist(account) )
	{
		user1 = new( USER );
		user1->set_id(account);
		user1->restore();
		user = user1;
	}
	if ( !user )
		return 0;
	if ( flag == 2 )	//出师后
	{
		exp /= 100;
		iSave = 1;
		user->add_save_2("shitu.exp",exp);
		MAILBOX->sys_mail(account,id,sprintf(BLK"你的徒弟"HIR"%s"BLK"勤学苦练，实力又增进一层。因此你得到了%d点经验的奖励！奖励领取人：孟子（坐标136，144），地点：新手村。孔夫子（坐标136，144），地点：周国。",who->get_name(),exp));
	}
	else if ( flag == 1 )	//出师前
	{
		level = who->get_level();
		level1 = mpTmp["level"];;	//新的拜师规则下才有这个值
		if ( level == 5 )
			pot = 500;
		else if ( level == 10 )
		{
			exp1 = 50000;	
			pot = 1000;	
		}
		else if ( level == 15 )
			pot = 1500;
		else if ( level == 20 )
		{
			exp1 = 80000;
			pot = 2000;
		}
		else if ( level == 25 )
			pot = 2500;
		else if ( level == 30 )
		{
			exp1 = 100000;
			pot = 3000;
		}
		else if ( level == 35 )
			pot = 5000;
		else if ( level == 40 )
			pot = 7000;
		if ( level1 && exp1 )	//奖励给师傅(新规则)
		{
			iSave = 1;
			user->add_save_2("shitu.exp",exp1);
			MAILBOX->sys_mail(account,id,sprintf(BLK"由于你教导徒弟"HIR"%s"NOR"有方，因此你得到了%d点经验的奖励！奖励领取人：孟子（坐标136，144），地点：新手村。孔夫子（坐标136，144），地点：周国。",who->get_name(),exp1));
		}
		if ( pot ) //奖励给徒弟
		{
			who->add_save_2("shitu.pot",pot);
			MAILBOX->sys_mail(who->get_id(),who->get_number(),sprintf(BLK"由于你勤学苦练，获得了周王的青睐。因此你得到了%d点潜能的奖励！奖励领取人：孟子（坐标136，144），地点：新手村。孔夫子（坐标136，144），地点：周国。",pot));
		}
		if ( level == 10 || level == 20 || level == 30 || level == 40 )	//师傅用友好度换经验
		{
			add_friend_bonus(who,user,level);
			iSave = 1;			
		}
	}
	if ( user1 )
	{
		if ( iSave )
			user1->save();
		destruct(user1);
	}
	return exp;
}
//领取奖励的列表
void friend_bonus_list1(object me,object who)
{
	int i,size;
	string cTmp="";
	
	for(i=0,size=sizeof(nTudi);i<size;i++)
	{
		if ( !mapp(who->get_save_2(nTudi[i])) )
			continue;
		if ( !who->get_save_2(nTudi[i]+".friend_bonus")  )
			continue;
		cTmp += sprintf(ESC"换取%s的奖励\ntalk %x# welcome.%d\n",who->get_save_2(nTudi[i]+".name"),getoid(me),1000+31+i);
	}
	if ( sizeof(cTmp) )
		cTmp = me->get_name()+":\n    你确认要用和你徒弟的友好度换取特别奖励吗？那好吧！\n" + cTmp+ESC"离开";
	else
		cTmp = me->get_name()+":\n    你不符合领取特别奖励条件！\n" + ESC"离开";
	send_user(who,"%c%s",':',cTmp);
	
}
//等级奖励列表
void friend_bonus_list2(object me,object who,int which)
{
	int i,size,*nTmp,level;
	string cTmp="",cTudi;
		
	cTudi = nTudi[which-1031];
	nTmp = who->get_save_2(cTudi+".friend_bonus");
	if ( (size=sizeof(nTmp)) == 0 )
		return ;
	which -= 1030;
	for(i=0;i<size;i++)
	{
		level = nTmp[i];
		if ( level == 10 )
			cTmp += sprintf(ESC"徒弟10级特别奖励（消耗100点友好度）\ntalk %x# welcome.%d\n",getoid(me),1000+which*100+level);
		else if ( level == 20 )
			cTmp += sprintf(ESC"徒弟20级特别奖励（消耗800点友好度）\ntalk %x# welcome.%d\n",getoid(me),1000+which*100+level);
		else if ( level == 30 )
			cTmp += sprintf(ESC"徒弟30级特别奖励（消耗1500点友好度）\ntalk %x# welcome.%d\n",getoid(me),1000+which*100+level);
		else if ( level == 40 )
			cTmp += sprintf(ESC"徒弟40级特别奖励（消耗2000点友好度）\ntalk %x# welcome.%d\n",getoid(me),1000+which*100+level);
	}
	if ( sizeof(cTmp) )
		cTmp = me->get_name()+":\n    你确认要用和你徒弟的友好度换取特别奖励吗？那好吧！\n" + cTmp+ESC"离开";
	else
		cTmp = me->get_name()+":\n    你不符合领取特别奖励条件！\n" + ESC"离开";	
	send_user(who,"%c%s",':',cTmp);
}
//获取友好度奖励
int get_friend_bonus(object me,object who,int flag)
{
	int which,*nTmp,level,exp,degree,id;
	string cTudi;
	
	which = flag % 1000 / 100 - 1;
	if ( which < 0 || which >= sizeof(nTudi) )
		return ;
	level = flag % 100;
	cTudi = nTudi[which];
	nTmp = who->get_save_2(cTudi+".friend_bonus");
	if ( sizeof(nTmp) == 0 || member_array(level,nTmp) == -1 )
		return ;
	if ( level == 10 )
	{
		exp = 200000;
		degree = 100;	
	}
	else if ( level == 20 )
	{
		exp = 500000;
		degree = 800;	
	}
	else if ( level == 30 )
	{
		exp = 1000000;
		degree = 1500;	
	}
	else if ( level == 40 )
	{
		exp = 2000000;
		degree = 2000;	
	}
	else
		return ;
	if ( who->get_friend_degree(who->get_save_2(cTudi+".id")) < degree )
	{
		send_user(who,"%c%s",':',me->get_name()+sprintf(":\n    你与该徒弟的友好度不足%d，不能领取！\n",degree) + ESC"离开");
		return ;
	}
	who->add_friend_degree(who->get_save_2(cTudi+".id"),-degree);
	who->add_exp(exp);
	nTmp -= ({ level });
	if ( sizeof(nTmp) == 0 )
		who->delete_save_2(cTudi+".friend_bonus");
	else
		who->set_save_2(cTudi+".friend_bonus",nTmp);
	send_user(who,"%c%s",'!',"你领取了特别奖励");
}
