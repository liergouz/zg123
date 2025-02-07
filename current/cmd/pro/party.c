#include <ansi.h>
#include <time.h>
// 函数：命令处理
int main( object me, string arg )
{
	int i;
	string result,tmp;
	string *exp_str;
	int iTime;
	mixed *mixTime;
        if( !is_gm2(me) && !is_god(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }
	if ( arg && sscanf(arg,"%d.%s",i,tmp) != 2 )
		i = to_int(arg);
	
	switch (i)
	{
	default:
		send_user(me, "%c%c%w%s", ':',3,0,
			"请选择:\n"
			+ sprintf(ESC"下一页\nparty 6666\n")
//			+ sprintf(ESC"情人节\nparty 1\n")
//			+ sprintf(ESC"春节\nparty 4\n")
			+ sprintf(ESC"活动号登录控制\nparty 100\n")
			+ sprintf(ESC"皇城守卫战\nparty 7\n")
//			+ sprintf(ESC"开启战国王者领奖\nparty 11\n")
//			+ sprintf(ESC"宝箱系统\nparty 20\n")
//			+ sprintf(ESC"321世界网游日双倍经验时间\nparty 23\n")
//			+ sprintf(ESC"线上打宝活动操作\nparty 33\n")
//			+ sprintf(ESC"帮派齐心合力奖励\nparty 30\n")
//			+ sprintf(ESC"五一活动\nparty 39\n")
			+ sprintf(ESC"镖王争霸战\nparty 43\n")
//			+ sprintf(ESC"四色球活动操作\nparty 54\n")
//			+ sprintf(ESC"端午节活动操作\nparty 50\n")
//			+ sprintf(ESC"合服补偿\nparty 200\n")
			+ sprintf(ESC"挖宝总动员\nparty 110\n")
			+ sprintf(ESC"惊天大爆装\nparty 120\n")
			+ sprintf(ESC"劫宝飞贼大搜捕\nparty 1220\n")
			+ sprintf(ESC"真假虎王\nparty 130\n")
//			+ sprintf(ESC"门派偷袭战操作(测试)\nparty 125\n")
//			+ sprintf(ESC"黄金卫队长操作(测试)\nparty 127\n")
//			+ sprintf(ESC"七夕活动操作(测试)\nparty 135\n")
			+ sprintf(ESC"古墓探险\nparty 5000\n")
//			+ sprintf(ESC"中秋节活动操作(测试)\nparty 138\n")
			+ sprintf(ESC"国庆节活动操作\nparty 151\n")
			+ sprintf(ESC"重阳节活动操作\nparty 157\n")
			+ sprintf(ESC"合服补偿\nparty 200\n")
			+ ESC"离开"
		);
		break;
	case 6666:
		send_user(me, "%c%c%w%s", ':',3,0,
			"请选择:\n"
			+ sprintf(ESC"上一页\nparty\n")
			+ sprintf(ESC"寻找dodolook\nparty 12\n")
			+ sprintf(ESC"缘分对对碰\nparty 26\n")
			+ sprintf(ESC"新人王奖励\nparty 16\n")
			+ sprintf(ESC"无双攻城战\nparty 7000\n")
			+ ESC"离开"
		);		
		break;
	case 1:
		send_user(me, "%c%c%w%s", ':',3,0,
			"请选择情人节活动的操作:\n"
			+ sprintf(ESC"开启\nparty 2\n")
			+ sprintf(ESC"按预定时间开启\nparty 214\n")
			+ sprintf(ESC"关闭\nparty 3\n")
			+ ESC"离开"
		);
		break;
	case 2:
		"sys/user/marry"->set_valentine(1,0);
		"sys/party/valentine"->set_valentine(1,0);
		send_user(me,"%c%s",'!',"情人节活动开启了!");
		break;	
	case 214:
		"sys/user/marry"->set_valentine(0,0);
		"sys/party/valentine"->set_valentine(0,0);
		"sys/party/valentine"->destruct_chocolate();
		"sys/party/valentine"->check_time();
		send_user(me,"%c%s",'!',"情人节活动按预定时间开启!");
		break;	
	case 3:
		"sys/user/marry"->set_valentine(0,1);
		"sys/party/valentine"->set_valentine(0,1);
		"sys/party/valentine"->destruct_chocolate();
		send_user(me,"%c%s",'!',"情人节活动关闭了!");
		break;	
	case 4:
		send_user(me, "%c%c%w%s", ':',3,0,
			"请选择春节活动的操作:\n"
			+ sprintf(ESC"开启\nparty 5\n")
			+ sprintf(ESC"按预定时间开启\nparty 216\n")
			+ sprintf(ESC"关闭\nparty 6\n")
			+ ESC"离开"
		);
		break;
	case 5:
		"npc/00/0008"->set_newyear(1,0);
		"sys/party/chunjie"->set_newyear(1,0);
		"sys/party/chunjie"->generate_fuwawa();
		send_user(me,"%c%s",'!',"春节活动开启了!");
		break;
	case 7:
		result = "请选择皇城守卫战的操作:\n";
		if ("/sys/sys/count"->get_war_flag1())
			result += ESC"关闭皇城守卫战\nparty 8\n";
		else
			result += ESC"开启皇城守卫战\nparty 8\n";
		result += ESC"立即启动皇城守卫战\nparty 9\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 8:
		if ("/sys/sys/count"->get_war_flag1())
		{
			"/sys/sys/count"->set_war_flag1(0);
			send_user(me,"%c%s",'!',"皇城守卫战关闭!");
		}
		else
		{
			"/sys/sys/count"->set_war_flag1(1);
			send_user(me,"%c%s",'!',"皇城守卫战开启!");
		}		
		break;
	case 9:
		"/sys/party/defence"->start_defence();
		break;		
	case 216:
		"npc/00/0008"->set_newyear(0,0);
		"sys/party/chunjie"->set_newyear(0,0);
		"sys/party/chunjie"->destroy_baozhu();
		"sys/party/chunjie"->destroy_nianshou();
		"sys/party/chunjie"->destroy_fuwawa();
		"sys/party/chunjie"->check_time();		
		send_user(me,"%c%s",'!',"春节活动按预定时间开启!");
		break;
	case 6:
		"npc/00/0008"->set_newyear(0,1);
		"sys/party/chunjie"->set_newyear(0,1);
		"sys/party/chunjie"->destroy_baozhu();
		"sys/party/chunjie"->destroy_nianshou();
		"sys/party/chunjie"->destroy_fuwawa();
		send_user(me,"%c%s",'!',"春节活动关闭了!");
		break;
	case 11:
		"npc/party/0014"->read_renwang();
		send_user(me,"%c%s",'!',"战国王者领奖开启!");
		break;
	case 12:
		result = "请选择寻找dodolook活动的操作:\n";
		result += ESC"开启\nparty 13\n";
		result += ESC"关闭\nparty 14\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 13:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入活动的开始时间和结束时间（比如：20070315-20070430 ）：\n"ESC"party 15.%s\n");		
		break;
	case 14:
		"npc/party/0022"->set_close(me);
		break;
	case 15:
		"npc/party/0022"->set_open(me,tmp);
		break;		
	case 16:
		send_user(me, "%c%c%w%s", ':',3,0,
			"请选择新人王奖励的操作:\n"
			+ sprintf(ESC"开启\nparty 17\n")
			+ sprintf(ESC"关闭\nparty 18\n")
			+ ESC"离开"
		);
		break;
	case 17:
		"npc/party/0023"->set_open();
		send_user( me, "%c%s", '!',"新人王奖励开启！"); 
		break;	
	case 18:
		"npc/party/0023"->set_close();
		send_user( me, "%c%s", '!',"新人王奖励关闭！"); 
		break;
	case 20:
		result = "请选择宝箱系统的操作:\n";
		if ("/sys/item/box"->get_all_stuff())
			result += ESC"关闭宝箱系统\nparty 21\n";
		else
			result += ESC"开启宝箱系统\nparty 22\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 21:
		"/sys/item/box"->del_stuff();
		send_user(me,"%c%s",'!',"宝箱系统关闭!");
		break;		
	case 22:
		"/sys/item/box"->reset_stuff();
		send_user(me,"%c%s",'!',"宝箱系统开启!");
		break;				
	case 23:
		send_user(me, "%c%c%w%s", ':',3,0,
			"321世界网游日双倍经验时间的操作:\n"
			+ sprintf(ESC"开启\nparty 24\n")
			+ sprintf(ESC"关闭\nparty 25\n")
			+ ESC"离开"
			);
		break;
	case 24:
		"npc/party/0026"->set_open(me);
		break;	
	case 25:
		"npc/party/0026"->set_close(me);
		break;	
	case 26:
		result = "请选择缘分对对碰活动的操作:\n";
		result += ESC"开启\nparty 27\n";
		result += ESC"关闭\nparty 28\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 27:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入缘分对对碰活动的开始时间（比如：20070416 ）：\n"ESC"party 29.%s\n");		
		break;
	case 28:
		"npc/party/dodolook"->set_close(me);
		break;
	case 29:
		"npc/party/dodolook"->set_open(me,tmp);
		break;	
	case 30:
		send_user(me, "%c%c%w%s", ':',3,0,
			"帮派齐心合力奖的操作:\n"
			+ sprintf(ESC"开启\nparty 31\n")
			+ sprintf(ESC"关闭\nparty 32\n")
			+ ESC"离开"
		);
		break;
	case 31:
		"npc/org/qgl_amass"->set_open2();
		send_user( me, "%c%s", '!',"帮派齐心合力奖励开启！"); 
		break;	
	case 32:
		"npc/org/qgl_amass"->set_close2();
		send_user( me, "%c%s", '!',"帮派齐心合力奖励关闭！"); 
		break;
	case 33:
		send_user(me, "%c%c%w%s", ':',3,0,
			"线上打宝活动操作:\n"
			+ sprintf(ESC"活动准备状态\nparty 36\n")
			+ sprintf(ESC"直接开启(测试用,不要在正式活动时使用!)\nparty 34\n")
			+ sprintf(ESC"设置开启/结束时间\nparty 37\n")
			+ sprintf(ESC"直接关闭(测试用,不要在正式活动时使用!)\nparty 35\n")
			+ ESC"离开"
		);
		break;
	case 34:
		"npc/org/qgl_amass"->set_open();
		"npc/party/dodolook2"->set_open();
		"sys/npc/npc"->set_open();
		send_user( me, "%c%s", '!',"线上打宝活动已开启！"); 
		break;	
	case 35:
		"npc/org/qgl_amass"->set_close();
		"npc/party/dodolook2"->set_close();
		"sys/npc/npc"->set_close();
		send_user( me, "%c%s", '!',"线上打宝活动已关闭！"); 
		break;
	case 36:
		"npc/org/qgl_amass"->set_prepare();
		"npc/party/dodolook2"->set_prepare();
		"sys/npc/npc"->set_prepare();
		send_user( me, "%c%s", '!',"线上打宝活动正在准备中！"); 
		break;
	case 37:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入线上打宝活动的开始时间和结束时间（比如：20070517-20070721 ）：\n"ESC"party 38.%s\n");
		break;
	case 38:
		"npc/party/dodolook2"->set_open_time(me,tmp);
		"npc/org/qgl_amass"->set_open_time(me,tmp);
		"sys/npc/npc"->set_open_time(me,tmp);
		break;
	case 39:
		result = "请选择五一活动的操作:\n";
		result += ESC"开启\nparty 40\n";
		result += ESC"关闭\nparty 41\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 40:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入五一活动的开始时间和结束时间（比如：20070501-20070508 ）：\n"ESC"party 42.%s\n");		
		break;
	case 41:
		"npc/party/0032"->set_close(me);
		break;
	case 42:
		"npc/party/0032"->set_open(me,tmp);
		break;	
	case 43:
		result = "请选择镖王争霸战的操作:\n";
		result += ESC"开启\nparty 44\n";
		result += ESC"关闭\nparty 45\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 44:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入镖王争霸战的开始时间、结束时间和颁奖时间（比如：200705182000-200705182100-200705182130 ）：\n"ESC"party 46.%s\n");		
		break;
	case 45:
		TASK_ESCORT_D->set_close(me);
		break;
	case 46:
		TASK_ESCORT_D->set_open(me,tmp);
		break;	
	case 47:
		send_user(me, "%c%c%w%s", ':',3,0,
			"四色球(测试)操作:\n"
			+ sprintf(ESC"开始测试\nparty 48\n")
			+ sprintf(ESC"结束测试。注意：活动进行当中应处于此状态\nparty 49\n")
			+ ESC"离开"
		);
		break;
	case 48:
		"sys/npc/npc"->test_start();
		send_user( me, "%c%s", '!',"开始四色球测试，注意测试完后一定要结束！"); 
		break;	
	case 49:
		"sys/npc/npc"->test_finish();
		send_user( me, "%c%s", '!',"结束四色球测试！"); 
		break;
	case 50:
		result = "请选择端午节活动的操作:\n";
		result += ESC"开启\nparty 51\n";
		result += ESC"关闭\nparty 52\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 51:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入端午节活动的开始时间和结束时间（比如：200706190900-200706192300 ）：\n"ESC"party 53.%s\n");
		break;
	case 52:
		"sys/party/duanwujie"->set_close(me);
		"sys/party/duanwujie"->destruct_dongtingzhouzi();
		"sys/party/duanwujie"->destroy_zhongzi();
		break;
	case 53:
		"sys/party/duanwujie"->set_open(me,tmp);
		break;	
	case 54:
		send_user(me, "%c%c%w%s", ':',3,0,
			"四色球活动操作:\n"
			+ sprintf(ESC"四色球(测试)操作\nparty 47\n")
			+ sprintf(ESC"设置四色球活动结束时间\nparty 55\n")
			+ sprintf(ESC"取消设置四色球活动结束时间\nparty 57\n")
			+ ESC"离开"
		);
		break;
	case 55:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入四色球活动结束时间(比如：200707190900)：\n"ESC"party 56.%s\n");
		break;
	case 56:
		"sys/npc/npc"->set_ball_close_time(me,tmp);
		break;	
	case 57:
		"sys/npc/npc"->set_ball_cancel(me);
		break;

	case 100:
		result = "请选择活动号的控制:\n";
		if ("/sys/sys/count"->get_can_gm3())
			result += ESC"禁止活动号登录\nparty 101\n";
		else
			result += ESC"允许活动号登录\nparty 102\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 101:
		"/sys/sys/count"->set_can_gm3(0);
		send_user(me,"%c%s",'!',"现在禁止活动号登录!");
		break;
	case 102:
		"/sys/sys/count"->set_can_gm3(1);
		send_user(me,"%c%s",'!',"现在允许活动号登录!");
		break;	
	case 200:
		result = "请选择合服补偿的控制:\n";
		result += ESC"关闭合服补偿\nparty 201\n";
		result += ESC"开放合服补偿\nparty 202\n";
		result += ESC"离开";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 201:	
		"/sys/sys/count"->set_hefu_time(0);
		send_user(me,"%c%s",'!',"现在关闭合服补偿!");
		break;
	case 202:		
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入合服的次数及合服的结束时间(比如：2 200707190900)：\n"ESC"party 203.%s\n");
		break;			
	case 203:
		"sys/sys/count"->set_hefu_time2(me,tmp);
		break;	
	case 110://挖宝总动员
		result = "请选择挖宝总动员操作：\n";
		result += ESC"开启\nparty 111\n";
		result += ESC"关闭\nparty 112\n";
		result += ESC"离开";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 111:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入挖宝总动员的开始时间和结束时间（比如：200706190900-200706192300 ）：\n"ESC"party 113.%s\n");
		break;
	case 112:
		"sys/party/treasure"->set_close(me);
		break;
	case 113:
		"sys/party/treasure"->set_open(me,tmp);
		break;	
	case 120:
		result = "请选择“惊天大爆装”的操作:\n";
		result+= ESC"开启活动\nparty 121\n";
		result+= ESC"停止活动\nparty 122\n";
		result+= ESC"设置活动时间\nparty 123\n";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 121:
		"sys/party/burst_equips"->turn_on_activity();
		break;
	case 122:
		"sys/party/burst_equips"->turn_off_activity();
		break;
	case 123:
		result = "请输入活动起止时间，例：\"51700-51800\" 表示每周五的 17点-18点为活动开始时间 \n"ESC"party 124.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 124:
		exp_str = explode(tmp,"-");
		if(sizeof(exp_str) != 2) {
			send_user(me,"%c%s",'!',"错误的格式！");
		} else {
			"sys/party/burst_equips"->set_active_time(to_int(exp_str[0]),to_int(exp_str[1]));
		}		
		break;
	case 1220:
		result = "请选择“劫宝飞贼大搜捕”的操作:\n";
		result+= ESC"开启活动\nparty 1221\n";
		result+= ESC"停止活动\nparty 1222\n";
		result+= ESC"设置活动时间\nparty 1223\n";
		result+= ESC"查看活动状态\nparty 1224\n";
		send_user(me,"%c%c%w%s",':',3,0,result);		
		break;
	case 1221:
		"sys/party/feizei"->turn_on_activity();
		send_user(me,"%c%s",';',"成功开启活动！");
		break;
	case 1222:
		"sys/party/feizei"->turn_off_activity();
		send_user(me,"%c%s",';',"成功关闭活动!");
		break;
	case 1223:
		result = "请输入活动起止时间，例：\"1,2,3,4;9,23;2\" 表示每周一，二，三，四 9点到23点开始活动，每隔2个时刷新 \n"ESC"party 1225.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 1224:
		tell_user(me,"sys/party/feizei"->get_active_time());
		break;
	case 1225:
		if("sys/party/feizei"->set_active_time(tmp)) {
			send_user(me,"%c%s",';',sprintf("成功修改活动时间,活动被重置\n%s","sys/party/feizei"->get_active_time()));
		} else {
			send_user(me,"%c%s",';',"您输入的字符格式不符合要求！没有修改成功");
		}
		break;
	case 125:
		send_user(me, "%c%c%w%s", ':',3,0,
			"门派偷袭战活动操作:\n"
			+ sprintf(ESC"开始测试\nparty 126\n")
			+ ESC"离开"
		);
		break;
	case 126:
		"sys/party/sect_surprise"->generate_scum();
		break;		
	case 127:
		send_user(me, "%c%c%w%s", ':',3,0,
			"黄金卫队长活动操作:\n"
			+ sprintf(ESC"开始测试\nparty 128\n")
			+ ESC"离开"
		);
		break;
	case 128:
		"sys/party/gold_warrior"->check_time2();
		break;	
	case 130:
		result = "请选择“真假虎王”的操作:\n";
		result+= ESC"开启活动\nparty 131\n";
		result+= ESC"关闭活动\nparty 132\n";
		result+= ESC"设置活动时间\nparty 133\n";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 131:
		"sys/party/guess_true_tiger"->turn_on_activity();
		break;
	case 132:
		"sys/party/guess_true_tiger"->turn_off_activity();
		break;
	case 133:
		result = "请输入活动起止时间，例：\"50900-60000\" 表示每周五的 9点-24点为活动开始时间 \n"ESC"party 134.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 134:
		exp_str = explode(tmp,"-");
		if(sizeof(exp_str) != 2) {
			send_user(me,"%c%s",'!',"错误的格式！");
		} else {
			"sys/party/guess_true_tiger"->set_active_time(to_int(exp_str[0]),to_int(exp_str[1]));
		}		
		break;		


	//====================wg=================
	case 135:
		send_user(me, "%c%c%w%s", ':',3,0,
			"七夕活动操作:\n"
			+ sprintf(ESC"开始测试\nparty 136\n")
			+ sprintf(ESC"结束测试\nparty 137\n")
			+ ESC"离开"
		);
		break;
	case 136:
		"sys/party/qixi"->check_time2();
		break;
	case 137:
		"sys/party/qixi"->check_time3();
		break;
	case 138:
		send_user(me, "%c%c%w%s", ':',3,0,
			"中秋节活动操作:\n"
			+ sprintf(ESC"开始测试\nparty 139\n")
			+ sprintf(ESC"开始领取抓兔奖励\nparty 144\n")
			+ sprintf(ESC"结束测试\nparty 143\n")
			+ ESC"离开");
		break;
	case 139:
		set_party_time(2007,9,24,8,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 143:
		set_party_time(2007,10,3,22,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 144:
		set_party_time(2007,9,26,22,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 145:
		send_user(me, "%c%c%w%s", ':',3,0,
			"国庆节活动之——西瓜伯伯的操作:\n"
			+ sprintf(ESC"开启国庆节活动之——西瓜伯伯\nparty 146\n")
			+ sprintf(ESC"调整当前时间至国庆节活动之——西瓜伯伯的起始时间\nparty 147\n")
			+ sprintf(ESC"检查国庆节活动之——西瓜伯伯状态\nparty 148\n")
			+ sprintf(ESC"把时间还原为标准的系统时间\nparty 149\n")
			+ sprintf(ESC"中止国庆节活动之——西瓜伯伯\nparty 150\n")
			+ ESC"离开");
		break;
	case 146:
		"sys/party/national"->set_open();
		send_user(me,"%c%s",';',"成功开启国庆节活动之——西瓜伯伯！");
		break;
	case 147:
		set_party_time(2007,10,1,8,0,0);
		"sys/party/national"->check_time();
        	tell_user(me,"当前时间调整为：%s",short_time(get_party_time()));
		break;
	case 148:
        	tell_user(me,"当前活动时间是：%s",short_time(get_party_time()));
		if ("sys/party/national"->get_status()==0) tell_user(me,"国庆节活动之——西瓜伯伯处于关闭状态");
		else tell_user(me,"国庆节活动之——西瓜伯伯处于开启状态");
		break;
	case 149:
		iTime = time();
		mixTime=localtime(iTime);
		set_party_time(mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]);
		"sys/party/national"->destruct_xigua_uncle();
		"sys/party/national"->destruct_xigua();
		"sys/party/national"->destruct_bad_npc();
		"sys/party/national"->check_time();
        	tell_user(me,"当前时间还原到准确的系统时间：%s",short_time(time()));
		break;
	case 150:
		"sys/party/national"->set_close();
		send_user(me,"%c%s",';',"成功中止国庆节活动之——西瓜伯伯！");
		break;

	case 151:
		send_user(me, "%c%c%w%s", ':',3,0,
			"国庆节活动操作:\n"
			+ sprintf(ESC"西瓜伯伯的活动\nparty 145\n")
			+ sprintf(ESC"国庆赠礼活动\nparty 152\n")
			+ ESC"离开");
		break;
	case 152://国庆赠礼活动
		result = "请选择国庆节活动之——国庆赠礼操作：\n";
		result += ESC"开启\nparty 153\n";
		result += ESC"关闭\nparty 154\n";
		result += ESC"检查活动状态\nparty 156\n";
		result += ESC"离开";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 153:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入国庆节活动之——国庆赠礼的开始时间和结束时间（比如：200706190900-200706192300 ）：\n"ESC"party 155.%s\n");
		break;
	case 154:
		"npc/party/exchange_angel"->set_close(me);
		break;
	case 155:
		"npc/party/exchange_angel"->set_open(me,tmp);
		break;
	case 156:
		if ("npc/party/exchange_angel"->is_open()) tell_user(me,"国庆节活动之——国庆赠礼处于开启状态");
		else tell_user(me,"国庆节活动之——国庆赠礼处于关闭状态");
		break;

	case 157:
		send_user(me, "%c%c%w%s", ':',3,0,
			"重阳节活动操作:\n"
			+ sprintf(ESC"开启活动\nparty 158\n")
			+ sprintf(ESC"调整当前时间至重阳节活动的起始时间\nparty 159\n")
			+ sprintf(ESC"检查活动状态\nparty 160\n")
			+ sprintf(ESC"把时间还原为标准的系统时间\nparty 161\n")
			+ sprintf(ESC"中止活动\nparty 162\n")
			+ ESC"离开");
		break;
	case 158:
		"sys/party/chongyang"->set_open();
		send_user(me,"%c%s",';',"成功开启活动！");
		break;
	case 159:
		set_party_time(2007,10,19,9,50,0);
		"sys/party/chongyang"->check_time();
        	tell_user(me,"当前时间调整为：%s",short_time(get_party_time()));
		break;
	case 160:
        	tell_user(me,"当前活动时间是：%s",short_time(get_party_time()));
		if ("sys/party/chongyang"->get_status()==0) tell_user(me,"重阳节活动处于关闭状态");
		else tell_user(me,"重阳节活动处于开启状态");
		break;
	case 161:
		iTime = time();
		mixTime=localtime(iTime);
		set_party_time(mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]);
		"sys/party/chongyang"->destruct_party_npc();
		"sys/party/chongyang"->destruct_party_item();

		"sys/party/chongyang"->check_time();
        	tell_user(me,"当前时间还原到准确的系统时间：%s",short_time(time()));
		break;
	case 162:
		"sys/party/chongyang"->set_close();
		send_user(me,"%c%s",';',"成功中止活动！");
		break;

	//====================end=================



	/************************************XXY************************************/
	case 5000: 
		send_user(me,"%c%c%w%s",':',3,0,"古墓探险操作:\n"
		           +sprintf(ESC HIY"开始测试\nparty 5001\n")
		           +sprintf(ESC HIY"关闭测试\nparty 5002\n")
		           +sprintf(ESC HIY"检查活动状态\nparty 5005\n")
		           +sprintf(ESC HIY"开始活动(正常开启)\nparty 5003\n")
		           +sprintf(ESC HIY"关闭活动(永久关闭)\nparty 5004\n")
		           +ESC"离开");
		break;
	case 5001:
		"sys/party/gumu_check_time"->set_gumu_party_open(1,1);
		break;
	case 5002:
		"sys/party/gumu_check_time"->set_gumu_party_open(0,1);
		break;
	case 5003:
		"sys/party/gumu_check_time"->set_gumu_party_open(1,0);
		break;
	case 5004:
		"sys/party/gumu_check_time"->set_gumu_party_open(0,0);
		break;
	case 5005:
		tell_user(me,sprintf(HIY"当前游戏时间为: %s",short_time(get_party_time())));
		tell_user(me,sprintf(HIY"%s","sys/party/gumu_check_time"->get_party_statue()));
		break;
	/************************************XXY************************************/
	//====================lyt================
	case 7000:
		send_user(me, "%c%c%w%s", ':',3,0,
			"无双攻城战操作:\n"
			+ sprintf(ESC"修改游戏的系统时间(测试用)\nparty 7001\n")
			+ sprintf(ESC"按活动的时间开启\nparty 7003\n")
			+ sprintf(ESC"强行关闭活动\nparty 7004\n")
			+ sprintf(ESC"活动状态\nparty 7005\n")
			+ ESC"离开");
		break;
	case 7001:
		send_user( me, "%c%c%d%s", '?', 16, 60, "请输入活动的当前时间（格式如：2007-9-18 19:29:30 ）：\n"ESC"party 7002.%s\n");		
		break;
	case 7002:
		WUSHUANG->set_wushuang_time(me,tmp);
		break;
	case 7003:
		WUSHUANG->set_flag(1);
		break;
	case 7004:
		WUSHUANG->set_flag(0);
		break;
	case 7005:
		WUSHUANG->get_status(me);
		break;
	case 7999:
		break;
	//====================end=================	
	}
        return 1;
}



