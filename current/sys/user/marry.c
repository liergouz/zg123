#include <ansi.h>
#include <item.h>
#include <time.h>
#include <equip.h>
#include <task.h>

inherit DBASE_F;
inherit SAVE_F;
#define EBA		"npc/task/8300"
int iMarry;
int iDivorce1,iDivorce2,i214,iStart214,iFinish214,close_val,open_val;
static int host_type;

object check_marry(object me ,object who);
object check_divorce(object me ,object who);
void marry(object npc,object who,object user);
void force_divorce(object me,object who);
void divorce(object me,object who,object user);
object check_task(object me ,object who);
void accept_task(object me,object who,object user);
void task_bonus(object me,object who);
void init_npc(object npc);
void force_divorce_time(object me, object who);

// 函数：生成二进制码
void SAVE_BINARY() { }
string get_save_file()	{ return "data/marry"SAVE_EXTENSION;}

void create()
{
	restore();	
	host_type = MAIN_D->get_host_type();
	iStart214=mktime(2007,2,14,0,0,0);
	iFinish214=mktime(2007,2,14,23,59,59);
}

void do_look(object me,object who)
{
	int id;
	string result = "";
	object item;
	i214=time();
	id = getoid(me);
        if ( !close_val && who->get_level()>=10 && who->get_quest("valentine.flag") == 0 && ((i214>iStart214 && i214<iFinish214) || open_val )&& who->get_gender()==1 && !objectp( item = present("月老给的包裹", who, 1, MAX_CARRY) ))
		result = sprintf(ESC HIY "情人节活动\ntalk %x# welcome.214\n",getoid(me));
        if ( who->get_quest("valentine.flag") == 3 && objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
		result = sprintf(ESC HIY "求索\ntalk %x# welcome.217\n",getoid(me));
        if ( who->get_quest("valentine.flag") == 4 && !objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
		result = sprintf(ESC HIY "爱情之花\ntalk %x# welcome.219\n",getoid(me));
	if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_4") != 1)
		result = sprintf(ESC HIY "拜访\ntalk %x# welcome.15\n",getoid(me));
        if ( who->get_save_2("qixi.flag") == 1 && i214 < "sys/party/qixi"->get_qixi_time() )
		result = sprintf(ESC HIY "七夕天赐奇缘\ntalk %x# qixi.16\n",getoid(me));

	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
		me->get_name()+":\n    有缘千里来相聚, 无缘对面手难牵～！你找本老有何贵干？你是不是遇到了你心目中的另一半呢？呵呵……那本老就和你谈谈吧！\n"
		+ result
		+ sprintf(ESC"我想了解结婚\ntalk %x# welcome.1\n",id)
		+ sprintf(ESC"我想了解离婚\ntalk %x# welcome.2\n",id)
		+ sprintf(ESC"我们想结婚，请月老为我们证婚\ntalk %x# welcome.3\n",id)
		+ sprintf(ESC"我们是来办理离婚的\ntalk %x# welcome.4\n",id)
//+ sprintf(ESC"强制离婚过去3天\ntalk %x# welcome.13\n",id)
//+ sprintf(ESC"强制离婚过去10天\ntalk %x# welcome.14\n",id)
		+ESC"离开"
		 );
}

void do_welcome( object me, object who,string arg )
{
        int flag,i,size,p;
        string *name,tmp,name214_1;
        object user,item,item214_1;
	i214=time();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    办理结婚时，你须和你的爱人组队前来，双方等级必须大于等于40级，人员必须是男女角色各一名，此外作为申请方须交纳结婚费用1000000金。");
		break;
	case 2:
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    婚分为协商离婚和强制离婚。协商离婚：你须和你的爱人组队前来，此时系统会征求双方意愿，当双方同意离婚时，即双方解除婚姻关系。强制离婚：夫妻任何一方均可单独申请强制离婚，系统会扣除申请者1000000金费用。");
		break;
	case 3:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user( who, "%c%%s", ':', "婚姻系统尚未开放！");
			return;
		}
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    你确定要结婚吗？请先将你的道具栏预留一部分空间，我会有喜糖赠送的哦～！\n"
			+ sprintf(ESC"确定\ntalk %x# welcome.5\n",getoid(me))
			+ESC"离开"
			);		
		who->delete("marry.wait");
		break;
	case 4:
		if ( !who->get_save_2("marry") )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    没结婚就不要胡闹了～");
			return ;
		}
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    你觉得你们的缘分真的结束了吗？这段姻缘真的无法挽救了吗？与其在一起是一种痛苦还不如分开算了！\n"
			+ sprintf(ESC"协商离婚\ntalk %x# welcome.7\n",getoid(me))
			+ sprintf(ESC"强制离婚\ntalk %x# welcome.8\n",getoid(me))
			+ESC"离开"
			);		
		
		break;
	case 5:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user( who, "%c%%s", ':', "婚姻系统尚未开放！");
			return;
		}	
		if ( !objectp(user=check_marry(me,who)) )
			return ;
		send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s\n    你愿意%s%s吗？（请先将你的道具栏预留一部分空间，我会有喜糖赠送的哦～）\n",me->get_name(),user->get_gender()==1?"娶":"嫁给",who->get_name())
			+ sprintf(ESC"确定\ntalk %x# welcome.6\n"ESC"离开",getoid(me)));
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请等待对方的回答。");
		who->set("marry.waitfor",user);	
		user->set("marry.reply",who);	
		break;
	case 6:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user( who, "%c%%s", ':', "婚姻系统尚未开放！");
			return;
		}	
		user = who;
		if( !objectp(who=user->get("marry.reply")) )
			return ;
		if ( user != who->get("marry.waitfor") )
			return ;
		who->delete("marry.waitfor");	
		user->delete("marry.reply");
		if ( !objectp(user=check_marry(me,who)) )
			return ;
		marry(me,who,user);
		break;	
	case 7:
		if ( !objectp(user=check_divorce(me,who)) )
			return ;
		send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s\n    %s要跟你协议离婚，你愿意吗？\n",me->get_name(),who->get_name())
			+ sprintf(ESC"确定\ntalk %x# welcome.9\n"ESC"离开",getoid(me)));
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请等待对方的回答。");
		who->set("divorce.waitfor",user);	
		user->set("divorce.reply",who);	
		
		break;
	case 8:
		if ( !who->get_save_2("marry") )
			return ;
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    你确定要强制离婚吗？\n"
			+ sprintf(ESC"确定\ntalk %x# welcome.10\n",getoid(me))
			+ESC"离开"
			);		
		break;
	case 9:
		user = who;
		if( !objectp(who=who->get("divorce.reply")) )
			return ;
		if ( user != who->get("divorce.waitfor") )
			return ;
		who->delete("divorce.waitfor");	
		user->delete("divorce.reply");
		if ( !objectp(user=check_divorce(me,who)) )
			return ;
		divorce(me,who,user);
		break;
	case 10:
		force_divorce_time(me,who);
		break;
	case 11:
		force_divorce(me,who);
		break;		
//case 13:
//	who->set_save_2("marry.divorcetime",time()-3600*24*3);
//	break;		
//case 14:
//	who->set_save_2("marry.divorcetime",time()-3600*24*10);
//	break;		
        case 15:
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_4") != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    大王叫你来拜访我吗？你可以看看现在和将来在我这会有什么需要的，呵呵。年轻人，有朝气，真好啊。\n", me->get_name()));
			who->set_save("baifang_ms_4",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,21);
		}
		if ( who->get_save("baifang_ms_1") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_3") == 1 && who->get_save("baifang_ms_4") == 1 && who->get_save("baifang_ms_5") == 1 )
		{
			who->set_legend(TASK_2_00,24);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,21,"访问周国名士(完成)" );
		}
        	break;
	case 214:
		if ( !close_val && who->get_level()>=10 && who->get_quest("valentine.flag") == 0 && ((i214>iStart214 && i214<iFinish214) || open_val )&& who->get_gender()==1 && !objectp( item = present("月老给的包裹", who, 1, MAX_CARRY) ))
			{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    2月14是一个很神奇的日子，据说在这期间内，心怀爱意的小伙子凭借自己的诚心和实力，就有可能得到不同寓意的玫瑰。\n"
			                ESC "神秘的种子\ntalk %x# welcome.215\n"
			                ESC "离开", me->get_name(), getoid(me) ) );
			}
		break;

	case 215:
	        if ( !close_val && who->get_level()>=10 && who->get_quest("valentine.flag") == 0 && ((i214>iStart214 && i214<iFinish214) || open_val )&& who->get_gender()==1 && !objectp( item = present("月老给的包裹", who, 1, MAX_CARRY) ))
			{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    既然如此，那你就去找唐老爷子求取传说中神秘的种子吧！顺便帮我把这个包裹带给唐老爷子，记住这个包裹可是千万不能打开的喔！\n"
			                ESC "接受任务\ntalk %x# welcome.216\n"
			                ESC "离开", me->get_name(), getoid(me) ) );			
			}				
		break;

	case 216:
	        if ( !close_val && who->get_level()>=10 && who->get_quest("valentine.flag") == 0 && ((i214>iStart214 && i214<iFinish214) || open_val )&& who->get_gender()==1 && !objectp( item = present("月老给的包裹", who, 1, MAX_CARRY) ))
		{
			item214_1 = new ("/item/04/0420");    //情人节包裹
			name214_1 = "/item/04/0411";
                        if (item214_1)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item214_1)  >=1 )
                                {
                                        p =item214_1->move(who, -1);
                                        item214_1->add_to_user(p);
		                        send_user( who, "%c%s", '!', "得到"HIR"包裹"NOR"一个");
					who->set_quest( "valentine.name", name214_1 );
					who->set_quest( "valentine.flag", 1 );
					send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"情人节任务" ); 
					send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,1,"神秘的种子" ); 		                        
					send_user( who, "%c%s", '!', "你领取了情人节任务————神秘的种子！");
                                }       
                                else
                                {
                                	destruct(item214_1); 
                                	send_user( who, "%c%s", '!', "您身上没有空位！");
                                }
                        }  
		}
		break;

	case 217:
	        if ( who->get_quest("valentine.flag") == 3 && objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
			{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    小伙子，事情我已经知道了，你做得很好啊！但是具体如何去做我也不清楚，待我想想谁会比较清楚，然后再告诉你吧！\n"
			                ESC "完成任务\ntalk %x# welcome.218\n"
			                ESC "离开", me->get_name(), getoid(me) ) );
			}
		break;

	case 218:
	        if ( who->get_quest("valentine.flag") == 3 && objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
		{
     		if( !objectp( item214_1 = present("神秘的种子", who, 1, MAX_CARRY) ) )
		     	{
		     		send_user( who, "%c%s", '!', "您身上没有神秘的种子");
		                return;
		        }          
		     	item214_1->remove_from_user();
		     	destruct(item214_1);  
		     	who->add_exp(500);
		     	who->set_quest( "valentine.flag", 4 );

		        send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_VALENTINE,3,0,"" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,3,"" ); 
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
		}				
		break;
	case 219:
	        if ( who->get_quest("valentine.flag") == 4 && !objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
			{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    我想起来了！据说新手村有一个智慧老人知百事，通天下，你不妨去问问他，或许他知道要怎么做才能让这种子开花。你拿着这种子去找他吧，这样他能知道得更清楚点。\n"
			                ESC "接受任务\ntalk %x# welcome.220\n"
			                ESC "离开", me->get_name(), getoid(me) ) );			
			}				
		break;
	case 220:
	        if ( who->get_quest("valentine.flag") == 4 && !objectp( item = present("神秘的种子", who, 1, MAX_CARRY) ))
		{
		item214_1 = new ("/item/04/0421");    //神秘的种子
		name214_1 = "/item/04/0414";
                        if (item214_1)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item214_1)  >=1 )
                                {
                                        p =item214_1->move(who, -1);
                                        item214_1->add_to_user(p);
		                        send_user( who, "%c%s", '!', "得到"HIR"神秘的种子"NOR"一袋");
					who->set_quest( "valentine.name", name214_1 );
					send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"情人节任务" ); 
					send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,4,"爱情之花" ); 		                        
					send_user( who, "%c%s", '!', "你领取了情人节任务————爱情之花！");
                                }       
                                else
                                {
                                	destruct(item214_1); 
                                	send_user( who, "%c%s", '!', "您身上没有空位！");
                                }
                        }  
		}
		break;
	}
}

object check_marry(object me ,object who)
{
	object *team,user;
	string leader;

	
	if ( who->get_save_2("marry") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你有婚姻在身，因此不能在老夫这里办理婚姻手续。");
		return 0;
	}
	if ( who->get_level() < 40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    年纪如此之小，怎么可以结婚呢？还是多等等再说吧～！（结婚要求双方等级≥40级）");
		return 0;
	}
	
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    呵呵……你是不是和老夫开玩笑，一个人怎么可以结婚呢？");
		return 0;
	}
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    到底哪个才是你的爱人呢？千万不要弄错了哦！");
		return;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    想结婚吗？请跟你的爱人组队过来找我吧。");
		return ;
	}
	team -= ({ who });
	user = team[0];
	if ( user->get_gender() == who->get_gender() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已经不是小孩子了，怎么能出这种差错呢？如果你还没了解结婚，老夫建议你仔细阅读下老夫前面所说的结婚须知。");
		return ;
	}
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    想结婚吗？请跟你的爱人组队过来找我吧。");
		return ;
	}
	
	if ( user->get_save_2("marry") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    对方有婚姻在身，因此不能在老夫这里办理婚姻手续。");
		return ;
	}
	if ( user->get_level() < 40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    年纪如此之小，怎么可以结婚呢？还是多等等再说吧～！（结婚要求双方等级≥40级）");
		return 0;
	}	
	return user;	
}
//协议离婚检查
object check_divorce(object me,object who)
{
	object user;
	if ( !who->get_save_2("marry") )
	{
		return 0;
	}
	user = find_player(sprintf("%d",who->get_save_2("marry.id")));	
	if ( !user )
		return 0;
	if ( user->get_leader() != sprintf("%d",who->get_number()) )
		return 0;
	if ( !user->get_save_2("marry") )
		return 0;
	if ( user->get_save_2("marry.id") != who->get_number() )
		return 0;
	if (!inside_screen_2(who, user))
		return 0;
	return user;
}

//结婚
void marry(object npc,object who,object user)
{
	int iTime,p;
	string cSpecial;
	object item;
	mixed mxTime;
	
	if ( who->get_cash() < 1000000 )
	{
		send_user(who,"%c%s",':',"你身上的现金不够1000000！");
		return ;			
	}
	iTime = time();
	mxTime = localtime(iTime);
	cSpecial = sprintf("%s|%s|%d|%d|%d",who->get_name(),user->get_name(),mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY]);
	who->add_cash(-1000000);
	who->log_money("结婚", -1000000);
	"/sys/sys/count"->add_use("结婚", 1000000);
	
	who->set_save_2("marry.name",user->get_name());
	who->set_save_2("marry.account",user->get_id());
	who->set_save_2("marry.id",user->get_number());
	who->set_save_2("marry.time",iTime);
	if ( who->get_gender() == 1 )
		who->add_title("M001");
	else
		who->add_title("M002");
		
	user->set_save_2("marry.name",who->get_name());
	user->set_save_2("marry.account",who->get_id());
	user->set_save_2("marry.id",who->get_number());
	user->set_save_2("marry.time",iTime);	
	if ( user->get_gender() == 1 )
		user->add_title("M001");
	else
		user->add_title("M002");
	
	item = new("item/08/0005");
	item->set_amount(10);
	item->set("special",cSpecial);
	p = item->move(who,-1);
	if ( !p )
	{
		send_user(who,"%c%s",'!',"你身上携带的东西太多了，不能得到喜糖！");
		destruct(item);
	}
	else
	{
		send_user(who,"%c%s",'!',"你得到了10颗喜糖！");
		item->add_to_user(p);	
	}
	
	item = new("item/08/0005");
	item->set_amount(10);
	item->set("special",cSpecial);
	p = item->move(user,-1);
	if ( !p )
	{
		send_user(user,"%c%s",'!',"你身上携带的东西太多了，不能得到喜糖！");
		destruct(item);
	}
	else
	{
		send_user(user,"%c%s",'!',"你得到了10颗喜糖！");
		item->add_to_user(p);	
	}	
	iMarry++;
	save();
	send_user( who, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name()+":\n    祝福你们白头偕老、永结同心！");
	send_user( user, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name()+":\n    祝福你们白头偕老、永结同心！");
	CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG"与"HIY"%s"HIG"喜结连理，成为本服第%d对新人！让我们祝福他们白头偕老、永结同心！",who->get_name(),user->get_name(),iMarry));
	who->log_legend( sprintf("您和%s(%d)结婚。", user->get_name(),user->get_number()) );
	user->log_legend( sprintf("您和%s(%d)结婚。", who->get_name(),who->get_number()) );
	log_file("marry.txt",sprintf("%s %s(%s %d) %s(%s %d) 结婚 %d\n",short_time(),who->get_name(),who->get_id(),who->get_number(),user->get_name(),user->get_id(),user->get_number(),iMarry));
}
//协议离婚
void divorce(object me,object who,object user)
{
	object item;
	
	who->delete_save_2("marry");
	if ( who->get_gender() == 1)
		who->delete_title("M001");
	else
		who->delete_title("M002");
	
	item = who->get_equip(HAND_TYPE);//去掉同心锁
	if ( !item || item->get_name() != "同心锁" )
	{
		item = present("同心锁",who,0,MAX_CARRY*4);
		if ( item && item->get_item_type() == ITEM_TYPE_TALISMAN )
		{
			item->remove_from_user();
			destruct(item);	
		}
	}
	else
	{
		item->remove_from_user();
		destruct(item);	
	}
	
	user->delete_save_2("marry");
	if ( user->get_gender() == 1)
		user->delete_title("M001");
	else
		user->delete_title("M002");
	
	item = user->get_equip(HAND_TYPE);//去掉同心锁
	if ( !item || item->get_name() != "同心锁" )
	{
		item = present("同心锁",user,0,MAX_CARRY*4);
		if ( item && item->get_item_type() == ITEM_TYPE_TALISMAN )
		{
			item->remove_from_user();
			destruct(item);	
		}
	}
	else
	{
		item->remove_from_user();
		destruct(item);	
	}
			
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    离婚成功！");
	send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    离婚成功！");
	iDivorce1++;
	save();
	log_file("marry.txt",sprintf("%s %s(%s %d) %s(%s %d) 协议离婚 %d\n",short_time(),who->get_name(),who->get_id(),who->get_number(),user->get_name(),user->get_id(),user->get_number(),iDivorce1));
	who->log_legend( sprintf("您和%s(%d)离婚。", user->get_name(),user->get_number()) );
	user->log_legend( sprintf("您和%s(%d)离婚。", who->get_name(),who->get_number()) );

}
//设置强制离婚确认时间
void force_divorce_time(object me, object who)
{
	int iTime;
	if ( !mapp(who->get_save_2("marry")) )
		return ;	
	iTime = who->get_save_2("marry.divorcetime");
	if ( !iTime || gone_time(iTime) > 3600*24*10 )
	{
		who->set_save_2("marry.divorcetime",time());
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    婚姻乃人生大事，不可草率～！你真的觉得你们婚姻到头了吗？你真的看破红尘了吗？我建议你还是多想想几天～！我给你三天的考虑时间！你若心意已决，三天后再来找我办理离婚手续吧～！");
		log_file("marry.txt",sprintf("%s %s(%s %d)  申请强行离婚\n",short_time(),who->get_name(),who->get_id(),who->get_number()));
		return;			
	}
	else if ( is_god(who) || (iTime && gone_time(iTime) > 3600*24*3 && gone_time(iTime) < 3600*24*10) )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    经过几天的考虑，看来你也没回心转意。你确定要强制离婚吗？\n"
			+ sprintf(ESC"确定\ntalk %x# welcome.11\n",getoid(me))
			+ESC"离开"
			);
		return ;		
	}
	else if ( iTime && gone_time(iTime) < 3600*24*3 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    我给你三天的考虑时间还没到呢！你还是在多想想吧～！");
		return;	
	}

}
//强制离婚
void force_divorce(object me,object who)
{
	int flag,id;
	string account,cName;
	object user,item;
	mapping mpTmp;

	mpTmp = who->get_save_2("marry");
	if ( !mapp(mpTmp) )
		return ;	
		
	account = mpTmp["account"];
	cName = mpTmp["name"];
	id = mpTmp["id"];
	user = find_player(sprintf("%d",id));
	if ( !user )
	{
		if( !user_exist(mpTmp["account"]) )
                {
                	flag = -1 ;
                }
                else
                {
			user = new( USER );
	                user->set_id(account);
	                if( !user->restore() ) 
                		destruct(user);
			else
				flag = 1;	//restore的
                }
                	
	}
	if ( user && user->get_number() == id )	//结婚的对象存在
	{
		if ( who->get_cash() < 1000000 )
		{
			send_user(who,"%c%s",'!',"你身上的现金不够1000000！");
			if ( flag == 1 )
				destruct(user);
			return ;			
		}
		who->add_cash(-1000000);
		who->log_money("离婚", -1000000);
		"/sys/sys/count"->add_use("离婚", 1000000);
	}
	who->delete_save_2("marry");
	if ( who->get_gender() == 1)
		who->delete_title("M001");
	else
		who->delete_title("M002");
	
	item = who->get_equip(HAND_TYPE);//去掉同心锁
	if ( !item || item->get_name() != "同心锁" )
	{
		item = present("同心锁",who,0,MAX_CARRY*4);
		if ( item && item->get_item_type() == ITEM_TYPE_TALISMAN )
		{
			item->remove_from_user();
			destruct(item);	
		}
	}
	else
	{
		item->remove_from_user();
		destruct(item);	
	}
	
	if ( user && user->get_number() == id )	//结婚的对象存在
	{
		user->delete_save_2("marry");
		if ( flag == 0 )	//去掉同心锁
		{
			if ( user->get_gender() == 1 )
				user->delete_title("M001");
			else
				user->delete_title("M002");

			item = user->get_equip(HAND_TYPE);
			if ( !item || item->get_name() != "同心锁" )
			{
				item = present("同心锁",user,0,MAX_CARRY*4);
				if ( item && item->get_item_type() == ITEM_TYPE_TALISMAN )
				{
					item->remove_from_user();
					destruct(item);	
				}
			}
			else
			{
				item->remove_from_user();
				destruct(item);	
			}		
		}
		user->log_legend( sprintf("%s(%d)和你强制离婚。", who->get_name(),who->get_number()) );
		if ( flag == 1 )
			user->save();
	}
	if ( flag == 1 )
		destruct(user);
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    离婚成功！");
	MAILBOX->sys_mail(account,id,sprintf("%s已经和你强行离婚了！",who->get_name()));
	iDivorce2++;
	save();
	log_file("marry.txt",sprintf("%s %s(%s %d) %s(%s %d) 强行离婚 %d\n",short_time(),who->get_name(),who->get_id(),who->get_number(),cName,account,id,iDivorce2));
	who->log_legend( sprintf("您和%s(%d)强制离婚。", cName,id) );
	
}
//红娘的对话
void do_look1(object me,object who)
{
	int id;
	string cmd,result;
	object item;
	i214=time();
	cmd="";	
	result ="";
	id = getoid(me);
        if ( !close_val && ((i214>iStart214 && i214<iFinish214) || open_val) && who->get_level()>=10 && who->get_gender()!=1 && who->get_quest("valentine.type") != 1 && who->get_quest("valentine.flag") == 0 )
		result = sprintf(ESC HIY "情人节活动\ntalk %x# welcome.214\n",getoid(me));
        if ( who->get_quest("valentine.flag") == 7 && objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		result = sprintf(ESC HIY "巧克力豆\ntalk %x# welcome.217\n",getoid(me));
        if ( who->get_quest("valentine.flag") == 8 && !objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		result = sprintf(ESC HIY "情人节巧克力\ntalk %x# welcome.219\n",getoid(me));
	if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_5") != 1)
		result = sprintf(ESC HIY "拜访\ntalk %x# welcome.11\n",getoid(me));
	if ( who->get_save_2("marrytask") )
		cmd = sprintf(ESC"教训%s\ntalk %x# welcome.9\n",who->get_save_2("marrytask.name"),id);
	else if ( who->get_save_2("marry") )
		cmd = sprintf(ESC"我们来领取夫妻任务\ntalk %x# welcome.2\n",id);	
		
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
		me->get_name()+":\n    你找本姑娘有何贵干？我可只为有缘人牵线搭桥的哦～！\n"
		+ sprintf(ESC"我想了解夫妻任务\ntalk %x# welcome.1\n",id)
		+ cmd +result
		+ESC"离开"
		 );
		
}

void do_welcome1( object me, object who,string arg )
{
        int flag,i,p,size;
        string *name,tmp;
        object user,item,item214_1;
	i214=time();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    夫妻任务只为结婚玩家设置，领取夫妻任务玩家要求必须是夫妻双方且只有夫妻双方，双方要处于组队状态。当你们完成任务后来我这里交还任务，我会送给你们夫妻双方一人一个法宝——同心锁哦！就算任务失败也不用担心，可以取消任务任务重新再来，不过中间要间隔二个小时！");
		break;
	case 2:
		if ( !who->get_save_2("marry") )	
			return ;
		if ( who->get_save_2("marry.task") )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已经帮助过我了，不好意思再次麻烦你！");
			return ;
		}
		if ( gone_time(who->get_save("marrytask.time")) < 7200 )
		{
			item = who->get_equip(HAND_TYPE);
			if (item && item->get_item_number()==10001078)
			{
	                        send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
	                        	ESC "%c\n"ESC"use %x# marry\n"
	                                , 1, getoid(item) ) );			
				return;
			}			
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    可惜，刚刚有人先你一步，帮助我去教训那恶霸了，现在很太平，没有作恶的恶霸，你过段时间再来吧！");
			return ;
		}
		if ( who->get_save_2("marrytask") )
		{
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    由于你没有完成上次夫妻任务，所以该任务不能领取。");
			return ;
		}
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n    最近有一个恶霸，自称“天下第一媒”。他限我三天内离开周国，三天后若见我还在说媒，他将会带人来砸我的招牌。你能不能前去将他教训一顿，免得他如此猖狂！\n"
			+ sprintf(ESC"接受\ntalk %x# welcome.3\n",getoid(me))
			+ESC"离开"
			);		
		break;
	case 3:
		if ( !who->get_save_2("marry") )	
			return ;
		if ( !objectp(user=check_task(me,who)) )
			return ;
		send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s\n    %s已经接受了夫妻任务，你是否一同协助？\n",me->get_name(),who->get_name())
			+ sprintf(ESC"接受\ntalk %x# welcome.4\n"ESC"取消\ntalk %x# welcome.5\n",getoid(me),getoid(me)));
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    请等待对方的回答。");
		who->set("marry.task",user);	
		user->set("marry.task",who);	
		break;	
	case 4:
		user = who;
		if( !objectp(who=user->get("marry.task")) )
			return ;
		if ( user != who->get("marry.task") )
			return ;
		who->delete("marry.task");	
		user->delete("marry.task");
		if ( !objectp(user=check_task(me,who)) )
			return ;
		accept_task(me,who,user);
		break;
	case 5:
		user = who;
		if( !objectp(who=user->get("marry.task")) )
			return ;
		if ( user != who->get("marry.task") )
			return ;
		who->delete("marry.task");	
		user->delete("marry.task");
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你的爱人拒绝协助，你将不能获得夫妻任务！");
		break;
	case 9:
		if ( !who->get_save_2("marrytask") )
			return;
		if ( !who->get_save_2("marry") )
		{
			who->delete_save_2("marrytask");
			who->delete_save("marrytask.time");
			return ;
		}			
		if ( !who->get_save_2("marrytask.finish") )
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    希望你们快点将此事办好！");
		else
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
				sprintf("%s\n    非常感谢你们的协助！祝你们夫妻百年好合！\n",me->get_name())
				+ sprintf(ESC"完成任务\ntalk %x# welcome.10\n"ESC"离开",getoid(me)));
		break;
	case 10:
		if ( !who->get_save_2("marrytask") )
			return;
		if ( !who->get_save_2("marrytask.finish") )
			return ;
		task_bonus(me,who);	
		break;	
        case 11:
		if ( who->get_legend(TASK_2_00,23) && !who->get_legend(TASK_2_00,24) && who->get_save("baifang_ms_5") != 1)
		{
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    大王叫你来拜访我吗？你可以看看现在和将来在我这会有什么需要的，呵呵。年轻人，有朝气，真好啊。\n", me->get_name()));
			who->set_save("baifang_ms_5",1);
			USER_TASK_D->send_task_intro(who,2,TID_ZHOUGUO,21);
		}
		if ( who->get_save("baifang_ms_1") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_2") == 1 && who->get_save("baifang_ms_3") == 1 && who->get_save("baifang_ms_4") == 1 && who->get_save("baifang_ms_5") == 1 )
		{
			who->set_legend(TASK_2_00,24);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,21,"访问周国名士(完成)" );
		}
        	break;
	case 214:
	        if ( !close_val && ((i214>iStart214 && i214<iFinish214) || open_val) && who->get_level()>=10 && who->get_gender()!=1 && who->get_quest("valentine.type") != 1 && who->get_quest("valentine.flag") == 0 )
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s：\n    2月14是一个很神奇的日子，据说在这期间内，心怀爱意的小姑娘凭借自己的诚心和实力，就有可能得到不同寓意的巧克力。\n"
		                ESC "情人节的传说\ntalk %x# welcome.215\n"
		                ESC "离开", me->get_name(), getoid(me) ) );
		}
		break;	
	case 215:
	        if ( !close_val && ((i214>iStart214 && i214<iFinish214) || open_val) && who->get_level()>=10 && who->get_gender()!=1 && who->get_quest("valentine.type") != 1 && who->get_quest("valentine.flag") == 0 )
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s：\n    看来你也是一位怀抱着诚意来的姑娘，那么，你去桃花源找到忘情婆婆吧，她会告诉你怎样才能得到巧克力的！\n"
		                ESC "接受任务\ntalk %x# welcome.216\n"
		                ESC "离开", me->get_name(), getoid(me) ) );			
		}
		break;
	case 216:
	        if ( !close_val && ((i214>iStart214 && i214<iFinish214) || open_val) && who->get_level()>=10 && who->get_gender()!=1 && who->get_quest("valentine.type") != 1 && who->get_quest("valentine.flag") == 0 )
		{
			who->set_quest( "valentine.flag", 5 );
			who->set_quest( "valentine.type", 1 );
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"情人节任务" ); 
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,5,"情人节的传说" ); 		                        
			send_user( who, "%c%s", '!', "你领取了情人节任务————情人节的传说！");
		}
		break;
	case 217:
	        if ( who->get_quest("valentine.flag") == 7 && objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s：\n    这果然是上好的巧克力豆，不过我也不太懂巧克力的做法，等我想想谁会做再告诉你吧。\n"
		                ESC "完成任务\ntalk %x# welcome.218\n"
		                ESC "离开", me->get_name(), getoid(me) ) );			
		}
		break;
	case 218:
	        if ( who->get_quest("valentine.flag") == 7 && objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		{
		if( objectp( item214_1 = present("巧克力豆", who, 1, MAX_CARRY) ) )
		{
			item214_1->remove_from_user();
			destruct(item214_1); 
		}          
			who->set_quest( "valentine.flag", 8 );
     	     	     	who->add_exp(500);
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"" ); 
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,7,"" ); 		                        
		}
		break;
	case 219:
	        if ( who->get_quest("valentine.flag") == 8 && !objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s：\n    我想起来了，我记得在新手村外的西北方有一个万丈深渊，这悬崖旁生活着一个巧克力精灵，我想它一定会知道巧克力的做法的，你赶紧起程去吧！\n"
		                ESC "接受任务\ntalk %x# welcome.220\n"
		                ESC "离开", me->get_name(), getoid(me) ) );			
		}
		break;
	case 220:
	        if ( who->get_quest("valentine.flag") == 8 && !objectp( item = present("巧克力豆", who, 1, MAX_CARRY) ))
		{
		item214_1 = new ("/item/04/0425");    //巧克力豆
                        if (item214_1)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item214_1)  >=1 )
                                {
                                        p =item214_1->move(who, -1);
                                        item214_1->add_to_user(p);
		                        send_user( who, "%c%s", '!', "得到"HIR"巧克力豆"NOR"一些");
		                        send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_VALENTINE,"情人节任务" ); 
		                        send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_VALENTINE,8,"情人节巧克力" ); 		                        
		                        send_user( who, "%c%s", '!', "你领取了情人节任务————情人节巧克力！");
                                }       
                                else
                                {
                                	destruct(item214_1); 
                                	send_user( who, "%c%s", '!', "您身上没有空位！");
                                }
                        }  
		}
		break;
	}
}
//检查夫妻任务
object check_task(object me ,object who)
{
	object *team,user;
	string leader;
	
	if ( !who->get_save_2("marry") )
	{
		return 0;
	}
	if ( who->get_save_2("marry.task") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你已经帮助过我了，不好意思再次麻烦你！");
		return ;
	}
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你还是和你爱人一起来吧！");
		return 0;
	}
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    本姑娘只为夫妻二人提供任务的哦！“");
		return;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    本姑娘只为夫妻二人提供任务的哦！");
		return ;
	}
	team -= ({ who });
	user = team[0];
	if ( user->get_save_2("marry.id") != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你们是夫妻吗？我想还是去阅读一下我定的任务须知再来吧！");
		return ;
	}
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    你还是和你爱人一起来吧！");
		return ;
	}
	if ( user->get_save_2("marrytask") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    由于你们队伍中"+user->get_name()+"没有完成上次夫妻任务，所以该任务不能领取。");
		return ;
	}	
	if ( gone_time(user->get_save("marrytask.time")) < 7200 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    可惜，刚刚有人先你一步，帮助我去教训那恶霸了，现在很太平，没有作恶的恶霸，你过段时间再来吧！");
		return ;
	}
	return user;	
}
//红娘任务
void accept_task(object me,object who,object user)
{
	int z,x,y,p,iTime,level;
	string cName;
	object npc,map;

        if( !( p = XY_D->get_city_point( -1, IS_CHAR_BLOCK ) ) ) return;
        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;
        if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
	level = who->get_level() > user->get_level() ?  who->get_level() : user->get_level();
	iTime = time();
	npc = new(EBA);
	if ( !npc )
		return ;
	cName = "恶霸" + NPC_NAME_D->get_thief_name();
	npc->set_name( cName );
	npc->set("marry1",who->get_number());
	npc->set("marry2",user->get_number());
	NPC_ENERGY_D->init_level(npc, level);
	init_npc(npc);
	npc->set_max_seek(8);
	
	npc->add_to_scene(z,x,y);
	
	who->delete_save_2("marrytask");
	who->set_save_2("marrytask.target",sprintf("%x#",getoid(npc)));
	who->set_save_2("marrytask.name",cName);
	who->set_save_2("marrytask.country",map->get_name());
	who->set_save_2("marrytask.x",x);
	who->set_save_2("marrytask.y",y);
	who->set_save_2("marrytask.x1",x+random(20));
	who->set_save_2("marrytask.y1",y+random(20));
	who->set_save_2("marrytask.time",iTime);
	who->set_save("marrytask.time",iTime);

	user->delete_save_2("marrytask");
	user->set_save_2("marrytask.target",sprintf("%x#",getoid(npc)));
	user->set_save_2("marrytask.name",cName);
	user->set_save_2("marrytask.country",map->get_name());
	user->set_save_2("marrytask.x",x);
	user->set_save_2("marrytask.y",y);
	user->set_save_2("marrytask.x1",x+random(20));
	user->set_save_2("marrytask.y1",y+random(20));
	user->set_save_2("marrytask.time",iTime);
	user->set_save("marrytask.time",iTime);

	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    希望你们快点将此事办好！");
	send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n    希望你们快点将此事办好！");
	
	//发送任务提示
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_HONGNIANG,"红娘任务" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_HONGNIANG,1,"教训媒霸" ); 
	send_user( user, "%c%c%c%w%s", 0x51, 1, 1,TID_HONGNIANG,"红娘任务" ); 
	send_user( user, "%c%c%c%w%w%s", 0x51, 1, 2,TID_HONGNIANG,1,"教训媒霸" ); 
}

void task_bonus(object me,object who)
{
	int p;
	object item;
	
	if ( !who->get_save_2("marrytask.finish") )
		return ;
	if ( !who->get_save_2("marry") )
	{
		who->delete_save_2("marrytask");
		who->delete_save("marrytask.time");
		return ;
	}
	item = who->get_equip(HAND_TYPE);//去掉同心锁
	if ( !item || item->get_name() != "同心锁" )
	{
		item = present("同心锁",who,0,MAX_CARRY*4);
		if ( item && item->get_item_type() == ITEM_TYPE_TALISMAN )
		{
			item->remove_from_user();
			destruct(item);	
		}
	}
	else
	{
		item->remove_from_user();
		destruct(item);	
	}
	item = new("item/std/9611");	
	if ( !item )
		return ;
	p = item->move(who,-1);
	if ( !p )
	{
		destruct(item);
		send_user(who,"%c%s",'!',"你携带的东西太多了！");	
		return ;
	}
	item->add_to_user(p);
	who->delete_save_2("marrytask");
	who->delete_save("marrytask.time");
	who->set_save_2("marry.task",time());
	send_user(who,"%c%s",';',"夫妻任务完成，得到同心锁一个");	
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_HONGNIANG,1,"" ); 
}

void init_npc(object npc)
{
	int p,level;
	
	level = npc->get_level();
	p = random(100);
	if ( p < 20)	//低物防高敏型
	{
		npc->set_skill(348,level);
		npc->set_skill(251,level);
		npc->set_skill(241,level);
		npc->set_char_picid(8011);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*17/2);	
                npc->add_sp(npc->get_sp()*2);
                npc->add_ap(npc->get_ap()*4/5);
                npc->add_mp(npc->get_mp()/2);  
                npc->set("marry.type",1);              		
	}
	else if ( p < 40 )	//高物防低法防型
	{
		npc->set_skill(221,level);
		npc->set_skill(231,level);
		npc->set_char_picid(0252);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(npc->get_dp()*3);
                npc->add_max_hp(npc->get_max_hp()*9/2); 	
                npc->add_pp(-1*npc->get_pp()*3/10);                
                npc->add_ap(npc->get_ap()*4/5);                
                npc->add_mp(npc->get_mp()/2);  
                npc->set("marry.type",2);              		
	}
	else if ( p < 60 )	//高法防低物防型
	{
		npc->set_skill(424,level);
		npc->set_skill(423,level);
		npc->set_skill(425,level);
		npc->set_char_picid(8010);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/4);
                npc->add_max_hp(npc->get_max_hp()*9/2); 	
                npc->add_sp(npc->get_sp());  
                npc->add_pp(npc->get_pp()*3/2);                
                npc->add_cp(npc->get_cp());
		npc->add_mp(npc->get_mp()*6);
                npc->set("marry.type",3);              		
	}	
	else if ( p < 70 )	//长血型：拳脚类
	{
		npc->set_skill(317,level);
		npc->set_skill(211,level);
		npc->set_char_picid(8000);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
                npc->add_dp(-1*npc->get_dp()/5);        
                npc->add_max_hp(npc->get_max_hp()*21); 
                npc->add_pp(-1*npc->get_pp()/5);                
                npc->add_cp(npc->get_cp()/2);                 
                npc->add_ap(npc->get_ap()*9/10);  
                npc->set("marry.type",4);              		
	}
	else if ( p < 90 )	//长血高物防高法防型：远程暗器类
	{
		npc->set_skill(261,level);
		npc->set_char_picid(8012);
                npc->set_walk_speed(4);
                npc->set_attack_speed(10);	
		npc->add_dp(npc->get_dp()*9/20);
		npc->add_max_hp(npc->get_max_hp()*11/2); 
 		npc->add_sp(npc->get_sp()*3);
 		npc->add_pp(npc->get_pp()*9/5);
 		npc->add_mp(npc->get_mp());
 		npc->add_ap(npc->get_ap()/2);
                npc->set("marry.type",5);              		
	}
	else 	//强攻型加召唤
	{
		npc->set_skill(414,level);
		npc->set_char_picid(8013);
                npc->set_walk_speed(4);
                npc->set_attack_speed(8);	
                npc->add_dp(npc->get_dp()*9/20);
                npc->add_ap(npc->get_ap()); 
                npc->add_max_hp(npc->get_max_hp()*11/2);                 
                npc->add_sp(npc->get_sp()*3);  
                npc->add_pp(npc->get_pp()*9/20);      
                npc->add_mp(npc->get_mp()*3/2);  
                npc->set("marry.type",6);              		
	}	
}
//设置情人节活动的开启和关闭
int set_valentine(int open,int close)
{
	open_val = open;
	close_val = close;
	return 1;	
}