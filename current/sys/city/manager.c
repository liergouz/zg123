
#include <ansi.h>
#include <city.h>

#define MIN_ORG_MEMBER  6               // 帮众人数下限

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：对话处理
void do_look( object who, object me )
{
        string cmd;
        string name1, name2, *name;
        int id, number, i, size;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )    // 本帮帮众
        {
                send_user( who, "%c%c%d%c%s", 0x95, 10, id, who->get_org_position(), me->get_org_name() );

                size = me->sizeof_member_dbase();
                name = me->get_all_member();

                for( i = 0; i < size; i ++ )
                {
                        number = to_int( name[i] );
                        send_user( who, "%c%c%d%d%c%d%d%c%s", 0x95, 11, number,
                                me->get_member_time(number), me->get_member_quit(number) ? 0 : 1,
                                me->get_member_gold(number), me->get_member_all_contribute(number), me->get_member_level(number), 
                                sprintf( "%-12s%s", me->get_member_name(number), me->get_member_rank(number) ) );
                }
        }
        else if( stringp(name1) && name1 != "" )    // 别帮人士
        {
                send_user( who, "%c%s", ':', me->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "，请问别来无恙？\n" );
        }
        else    // 无帮人士
        {
                cmd = sprintf( "talk %x# join.?\n", id );
                send_user( who, "%c%s", ':', me->get_name() + "：\n这位" + NPC_RANK_D->get_respect(who) + "，想加入本帮吗？\n"
                        ESC "申请入帮。\n" + cmd +
                        ESC "离开。\nCLOSE\n" );
        }
}

// 函数：查看信息
void do_info( object who, object me, string arg )
{
        string name1, name2, *name;
        int id, number, i, size;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )    // 本帮帮众
        {
                number = to_int(arg);

                if( !number )    // 显示帮派界面
                {
                        send_user( who, "%c%c%d%c%s", 0x95, 10, id, who->get_org_position(), me->get_org_name() );

                        size = me->sizeof_member_dbase();
                        name = me->get_all_member();

                        for( i = 0; i < size; i ++ )
                        {
                                number = to_int( name[i] );
                                if (me->get_member_id(number)==0) 
                                {
                                	me->delete_member_info(number);
                                	continue;
                                }                                
                                send_user( who, "%c%c%d%d%c%d%d%c%s", 0x95, 11, number,
                                        me->get_member_time(number), me->get_member_quit(number) ? 0 : 1,
                                        me->get_member_gold(number), me->get_member_all_contribute(number), me->get_member_level(number), 
                                        sprintf( "%-12s%s", me->get_member_name(number), me->get_member_rank(number) ) );
                        }
                }
                else if( me->get_member_id(number) )    // 显示个人信息
                {
                        if( number == who->get_number() )    // 点中自己，更新信息
                        {
                                me->set_member_name(number, who->get_name() );
                                me->set_member_gender(number, who->get_gender() );
                                me->set_member_level(number, who->get_level() );
                                me->set_member_family(number, who->get_fam_name() );
                                me->set_member_job(number, who->get_occupation() );
                                me->set_member_job_level(number, who->get_occupation_level() );
                        }
                        send_user( who, "%c%c%d%c%d%d%s", 0x95, 12, number,
                                me->get_member_gender(number), me->get_photo(number), 
                                me->get_member_quit(number), sprintf( "%-8s%-8s%s",
                                me->get_member_family(number), me->get_member_job(number), me->get_member_rank(number) ) );
                }
        }
}

// -------------------------------------------------------------

// 函数：任命帮众
void do_appoint( object who, object me, string arg )
{
        object char;
        string name1, name2, name3;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, id, *member;
        int number, level, flag, trader_flag;

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_org_position() >= ORG_PRESBYTER )    // 本帮官员
        {
                if( sscanf( arg, "%d.%d", number, level ) != 2 )
                {
                        number = to_int(arg);

                        if( me->get_member_id(number) )
                        {
                                cmd1 = sprintf("talk %x# appoint.%d.1\n", getoid(me), number);
                                cmd2 = sprintf("talk %x# appoint.%d.2\n", getoid(me), number);
                                cmd3 = sprintf("talk %x# appoint.%d.3\n", getoid(me), number);
                                cmd4 = sprintf("talk %x# appoint.%d.4\n", getoid(me), number);
                                cmd5 = sprintf("talk %x# appoint.%d.5\n", getoid(me), number);
                                cmd6 = sprintf("talk %x# appoint.%d.6\n", getoid(me), number);
                                cmd7 = sprintf("talk %x# appoint.%d.7\n", getoid(me), number);
                                send_user( who, "%c%s", ':', me->get_name() + "：\n您要任命" + me->get_member_name(number) + "什么职务？\n"
                                        ESC "副帮主。\n" + cmd1 +
                                        ESC "长老。\n" + cmd2 +
                                        ESC "堂主。\n" + cmd3 +
                                        ESC "香主。\n" + cmd4 +
                                        ESC "精英。\n" + cmd5 +
                                        ESC "商人。\n" + cmd6 +
                                        ESC "普通帮众。\n" + cmd7 +
                                        ESC "我再想想……\nCLOSE\n" );
                        }
                        return;
                }

                if( me->get_member_id(number) )
                {
			if ( who->get_org_position() < ORG_PRESBYTER )
                        {
                                send_user( who, "%c%s", '!', "您在“" + name2 + "”中职位太低。" );
                                return;
                        }
                        if( !( char = find_player( sprintf("%d", number) ) ) )
                        {
                                char = new( USER );
                                char->set_id( me->get_member_id(number) );
                                if( !char->restore() )
                                {
                                	id = me->get_member_id(number);
		                        if( id == me->get_master_id_2() )
		                        {
		                                me->set_master_2(0);
		                                me->set_master_id_2("");
		                                me->set_master_name_2("－－");
		                        }
		                        member = me->get_presbyter();
					if (arrayp(member) && member_array(id, member)!=-1 )
		                        {
		                        	member -= ({ id });
		                        	me->set_presbyter(member);
		                        }
		                        member = me->get_manager4();
		                        if (arrayp(member) && member_array(id, member)!=-1 )
		                        {
		                        	member -= ({ id });
		                        	me->set_manager4(member);
		                        }
		                        else
		                        if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
		                        {
		                        	member -= ({ id });
		                        	me->set_manager5(member);
		                        }
		                        else
		                        if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
		                        {
		                        	member -= ({ id });
		                        	me->set_manager6(member);
		                        }                                
		                        me->save();	
                                        send_user( who, "%c%s", '!', "这位玩家并不存在！" );
                                        destruct(char);  return;
                                }
                                flag = 1;    // 离线
                        }
                        if (char==who && level!=8)
                        {
                        	send_user( who, "%c%s", '!', "不能自己调整自己的职位！" );
                        	return ;
                        }

                        name3 = char->get_org_name();
                        if( !stringp(name3) || name3 == "" || name3 != name2 )    // 双保险，可删除
                        {                        	
                                id = me->get_member_id(number);
		                if( id == me->get_master_id_2() )
		                {
		                        me->set_master_2(0);
		                        me->set_master_id_2("");
		                        me->set_master_name_2("－－");
		                }
		                member = me->get_presbyter();
				if (arrayp(member) && member_array(id, member)!=-1 )
		                {
		                	member -= ({ id });
		                	me->set_presbyter(member);
		                }
		                member = me->get_manager4();
		                if (arrayp(member) && member_array(id, member)!=-1 )
		                {
		                	member -= ({ id });
		                	me->set_manager4(member);
		                }
		                else
		                if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
		                {
		                	member -= ({ id });
		                	me->set_manager5(member);
		                }
		                else
		                if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
		                {
		                	member -= ({ id });
		                	me->set_manager6(member);
		                }                                
		                me->save();	                        	
                                send_user( who, "%c%s", '!', char->get_name() + "不是“" + name2 + "”帮众。" );
                                if( flag ) destruct(char);
                                return;
                        }
                        if(     char->get_org_position() >= who->get_org_position()
                        &&      char->get_id() != who->get_id() )    // 权限判断！
                        {
                                send_user( who, "%c%s", '!', "您在“" + name2 + "”中职位太低。" );
                                if( flag ) destruct(char);
                                return;
                        }
                        else if( char->get_org_position() >= ORG_MASTER && level!=6 && level!=8 )    // 帮主
                        {
                                send_user( who, "%c%s", '!', char->get_name() + "是“" + name2 + "”帮主。" );
                                if( flag ) destruct(char);
                                return;
                        }

                        id = char->get_id();
			if (level!=6 && level!=8)
                        {                        
	                        if( id == me->get_master_id_2() )
	                        {
	                                me->set_master_2(0);
	                                me->set_master_id_2("");
	                                me->set_master_name_2("－－");
	                                char->delete_title("C002");
	                        }
	                        member = me->get_presbyter();
				if (arrayp(member) && member_array(id, member)!=-1 )
	                        {
	                        	member -= ({ id });
	                        	me->set_presbyter(member);
	                        	char->delete_title("C003");
	                        }
	                        member = me->get_manager4();
	                        if (arrayp(member) && member_array(id, member)!=-1 )
	                        {
	                        	member -= ({ id });
	                        	me->set_manager4(member);
	                        	char->delete_title("C004");
	                        }
	                        else
	                        if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
	                        {
	                        	member -= ({ id });
	                        	me->set_manager5(member);
	                        	char->delete_title("C005");
	                        }
	                        else
	                        if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
	                        {
	                        	member -= ({ id });
	                        	me->set_manager6(member);
	                        	char->delete_title("C006");
	                        }
			}
			member = me->get_trader();
			if (arrayp(member) && member_array(id, member)!=-1 )
				trader_flag = 1;
                        switch( level )
                        {
                       case 1 : if( who->get_org_position() < ORG_MASTER )    // 权限不足
                                {
                                        send_user( who, "%c%s", '!', "您在“" + name2 + "”中职位太低。" );
                                        if( flag ) destruct(char);
                                        return;
                                }
                                if( me->get_master_2() )
                                {
                                        send_user( who, "%c%s", '!', "“" + name2 + "”副帮主职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                                }
                                me->set_master_2( number );
                                me->set_master_id_2( me->get_member_id(number) );
                                me->set_master_name_2( me->get_member_name(number) );
                                me->set_member_rank(number, "副帮主");
                                if (trader_flag) me->set_member_rank(number, "副帮主商人");
                                char->set_org_position(ORG_MASTER_2);
                                char->set_org_title("副帮主");
                                char->add_title("C002");
                                char->show_title("C002");
                                break;
                       case 2 :
                       		member = me->get_presbyter();
                       		if (member ==0) member = ({ });
                       		if (sizeof(member)>=4)
                       		{
                                        send_user( who, "%c%s", '!', "“" + name2 + "”长老职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                       		}
                       		member -= ({ 0 });
                       		member -= ({ char->get_id() });                       		
                       		member += ({ char->get_id() });
                       		me->set_presbyter( member);
                                me->set_member_rank(number, "长老");
                                if (trader_flag) me->set_member_rank(number, "长老商人");
                                char->set_org_position(ORG_PRESBYTER);
                                char->set_org_title("长老");
                                char->add_title("C003");
                                char->show_title("C003");
                                break;
                       case 3 :
                       		member = me->get_manager4();
                       		if (member ==0) member = ({ });
                       		if (sizeof(member)>=6)
                       		{
                                        send_user( who, "%c%s", '!', "“" + name2 + "”堂主职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                       		}
                       		member -= ({ 0 });
                       		member -= ({ char->get_id() });                       		
                       		member += ({ char->get_id() });
                       		me->set_manager4( member);
                                me->set_member_rank(number, "堂主");
                                if (trader_flag) me->set_member_rank(number, "堂主商人");
                                char->set_org_position(ORG_TANGZHU);
                                char->set_org_title("堂主");
                                char->add_title("C004");
                                char->show_title("C004");
                                break;
		       case 4 :
                       		member = me->get_manager5();
                       		if (member ==0) member = ({ });
                       		if (sizeof(member)>=10)
                       		{
                                        send_user( who, "%c%s", '!', "“" + name2 + "”香主职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                       		}
                       		member -= ({ 0 });
                       		member -= ({ char->get_id() });                       		
                       		member += ({ char->get_id() });
                       		me->set_manager5( member);
                                me->set_member_rank(number, "香主");
                                if (trader_flag) me->set_member_rank(number, "香主商人");
                                char->set_org_position(ORG_XIANGZHU);
                                char->set_org_title("香主");
                                char->add_title("C005");
                                char->show_title("C005");
                                break;
		       case 5 :
                       		member = me->get_manager6();
                       		if (member ==0) member = ({ });
                       		if (sizeof(member)>=16)
                       		{
                                        send_user( who, "%c%s", '!', "“" + name2 + "”精英职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                       		}
                       		member -= ({ 0 });
                       		member -= ({ char->get_id() });                       		
                       		member += ({ char->get_id() });
                       		me->set_manager6( member);
                                me->set_member_rank(number, "精英");
                                if (trader_flag) me->set_member_rank(number, "精英商人");
                                char->set_org_position(ORG_JINGYING);
                                char->set_org_title("精英");
                                char->add_title("C006");
                                char->show_title("C006");
                                break;
		       case 6 :
		       		if (char->get_level()<40)
		       		{
                                        send_user( who, "%c%s", '!', "担任商人需要达到40级。" );
                                        if( flag ) destruct(char);
                                        return;
		       		}
                       		member = me->get_trader();
                       		if (member ==0) member = ({ });
                       		if (sizeof(member)>=4)
                       		{
                                        send_user( who, "%c%s", '!', "“" + name2 + "”商人职务没有空缺。" );
                                        if( flag ) destruct(char);
                                        return;
                       		}
                       		member -= ({ 0 });
                       		member -= ({ char->get_id() });
                       		member += ({ char->get_id() });
                       		me->set_trader( member);
                                me->set_member_rank(number, "商人");
                                if(char->get_org_position()>1)
                                	me->set_member_rank(number, char->get_org_title()+"商人");
//                                char->set_org_position(ORG_TRADER);
                                char->add_title("C007");
                                char->show_title("C007");
                                break;
                      case 7 :  me->set_member_rank(number, "－－");
                                char->set_org_position(ORG_MEMBER);
                                char->set_org_title("帮众");
                                if (trader_flag) me->set_member_rank(number, "商人");
                                char->add_title("C008");
                                char->show_title("C008");
                                break;
			case 8:
	                        if ( (member = me->get_trader()) && arrayp(member) && member_array(id, member)!=-1 )
	                        {
	                        	member -= ({ id });
	                        	me->set_trader(member);
	                        	char->delete_title("C007");
	                        	me->set_member_rank(char->get_number(), char->get_org_title());
	                        }
	                        break;
                        }
                        if (level!=7&& level!=6 && level!=8) char->delete_title("C008");
                        if (level!=8)
                        {
	                        write_user( who, ECHO "您任命%s(%d)为“%s”%s！",
	                                char->get_name(), char->get_number(), name2,
	                                me->get_member_rank(number)!="－－"?me->get_member_rank(number):"帮众" );
			}
			else
			{
	                        write_user( who, ECHO "您解除了%s(%d)的商人职务！",
	                                char->get_name(), char->get_number() );

			}
                        send_user( who, "%c%c%d%d%c%d%d%c%s", 0x95, 11, number,
                                me->get_member_time(number), me->get_member_quit(number) ? 0 : 1,
                                me->get_member_gold(number), me->get_member_all_contribute(number), me->get_member_level(number), 
                                sprintf( "%-12s%s", me->get_member_name(number), me->get_member_rank(number) ) );

                        char->save();
                        me->save();
                        if (level!=8)
	                        char->log_legend( sprintf( "您被%s(%d)任命为“%s”%s！",
        	                       who->get_name(), who->get_number(), name2, me->get_member_rank(number)!="－－"?me->get_member_rank(number):"帮众" ) );
			else
	                        char->log_legend( sprintf( "您被%s(%d)解除商人职位！",
        	                       who->get_name(), who->get_number() ) );
			if (level!=8)
                        	FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s任命%s(%d)为本帮%s！",
                                	who->get_name(), char->get_name(), char->get_number(),
                                	me->get_member_rank(number)!="－－"?me->get_member_rank(number):"帮众" ) );
			else
                        	FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s解除%s(%d)的商人职位！",
                                	who->get_name(), char->get_name(), char->get_number() ) );

                        if( flag ) destruct(char);
                        else 
				send_user( char, "%c%c%c%s", 0x3d, 49, 
                			char->get_org_position(), char->get_org_name() );              

                }
        }
}

// 函数：帮主让位
void do_demise( object who, object me, string arg )
{
        object char;
        string name1, name2, name3, *member;
        string cmd, id, result;
        int number;

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_org_position() >= ORG_MASTER )    // 帮主
        {
        	if (who->get_number()!=me->get_master())
                {
                        send_user( who, "%c%s", '!', "只有帮主才能退位。" );
                        return;
                }
                if( !sscanf( arg, "@.%d", number ) )
                {                     
                        if( number == who->get_number() )
                        {
                                send_user( who, "%c%s", '!', "不能禅让给自己。" );
                                return;
                        }                	   
                        if( !( char = find_player( arg ) ) )
                        {
	                        send_user( who, "%c%s", '!', "禅让的目标不在游戏中。" );
	                        return;                        	
                        }
                        number = to_int(arg);
			if (me->get_demisstime()>0)
			{
				me->set_demissnumber(0);
				me->set_demisstime(0);
				send_user( who, "%c%s", '!', "您取消了禅让。" );
	                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s(%d)取消了禅让！",
	                                who->get_name(), who->get_number() ) );
				return;
			}
                        if( me->get_member_id(number) )
                        {
                                cmd = sprintf( "talk %x# demise.@.%d\n", getoid(me), number );
                                send_user( who, "%c%s", ':', sprintf( "你即将把帮主之位禅让给%s(%d)，禅让后，你将继续做为普通成员存在帮中，确认吗？\n", me->get_member_name(number), number ) +
                                        ESC "是的。\n" + cmd +
                                        ESC "我再想想……\nCLOSE\n" );
                        }
                        return;
                }
                if( me->get_member_id(number) )
                {
                        if( number == who->get_number() )
                        {
                                send_user( who, "%c%s", '!', "不能禅让给自己。" );
                                return;
                        }
                        if( !( char = find_player( sprintf("%d", number) ) ) )
                        {
	                        send_user( who, "%c%s", '!', "禅让的目标不在游戏中。" );
	                        return;                        	
                        }                        
                        me->set_demissnumber(number);
                        me->set_demisstime(time()+24*3600);
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "帮主%s对帮中的%s(%d)青睐有加，计划让位与其，在24小时之后，禅让将完成。",
                                who->get_name(), me->get_member_name(number), number ) );
			return;
                }
	}
}

void do_demise2( object me, int number )
{
	object who;
        object char, char2;
        string name1, name2, name3, *member;
        string cmd, id, result;
        int flag1, flag2;
        name2 = me->get_org_name();
        if( me->get_member_id(number) )
        {
        	if (number==me->get_master()) return ;
                if( !( char = find_player( sprintf("%d", number) ) ) )
                {
                        char = new( USER );
                        char->set_id( me->get_member_id(number) );
                        if( !char->restore() )
                        {
                                return;
                        }
                        flag1 = 1;    // 离线
                }
                if( !( who = find_player( sprintf("%d", me->get_master()) ) ) )
                {
                        who = new( USER );
                        who->set_id( me->get_member_id(me->get_master()) );
                        if( !who->restore() )
                        {
                        	if (flag1==1) destruct(char);
                                return;
                        }
                        flag2 = 1;    // 离线
                }

                name3 = char->get_org_name();
                if( !stringp(name3) || name3 == "" || name3 != name2 )    // 双保险，可删除
                {
                        send_user( who, "%c%s", '!', char->get_name() + "不是“" + name2 + "”帮众。" );
                        if (flag1==1) destruct(char);
                        if (flag2==1) destruct(who);
                        return;
                }

                id = char->get_id();
                if( id == me->get_master_id_2() )
                {
                        me->set_master_2(0);
                        me->set_master_id_2("");
                        me->set_master_name_2("－－");
                        char->delete_title("C002");
                }
                member = me->get_presbyter();
		if (arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_presbyter(member);
                	char->delete_title("C003");
                }
		member = me->get_manager4();
                if (arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager4(member);
                	char->delete_title("C004");
                }
                if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager5(member);
                	char->delete_title("C005");
                }
                if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager6(member);
                	char->delete_title("C006");
                }
                if ( (member = me->get_trader()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_trader(member);
                }
                me->set_master( number );
                me->set_master_id( me->get_member_id(number) );
                me->set_master_name( me->get_member_name(number) );
                me->set_member_rank(number, "帮主");
                me->set_member_rank( who->get_number(), "－－" );

                char->set_org_position(ORG_MASTER);
                char->set_org_title("帮主");
                char->delete_title("C008");
                char->delete_title("C007");
                char->delete_title("C006");
                char->delete_title("C005");
                char->delete_title("C004");
                char->delete_title("C003");
                char->delete_title("C002");
                char->add_title("C001");
		char->show_title("C001");
		who->delete_title("C001");
                who->set_org_position(ORG_MEMBER);
                who->set_org_title("－－");
                who->add_title("C008");
                who->show_title("C008");

                result = sprintf( "您禅让帮主之位给%s(%d)！", char->get_name(), char->get_number() );
                write_user(who, ECHO + result);
                who->log_legend(result);
                result = sprintf( "%s(%d)禅让帮主之位给您！", who->get_name(), who->get_number() );
                write_user(char, ECHO + result);
                me->add_favour(-100);
                me->add_stable(-300);                               
                char->log_legend(result);
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s将帮主之位禅让给%s(%d)！",
                        who->get_name(), char->get_name(), char->get_number() ) ); 
		WUSHUANG->check_org_title(char);
		WUSHUANG->check_org_title(who);
		if (flag1)
		{
			char->save();
			destruct(char);
		}
		else
		{
			send_user( char, "%c%c%c%s", 0x3d, 49, 
                		char->get_org_position(), char->get_org_name() );              
			
		}
		if (flag2)
		{
			who->save();
			destruct(who);
		}
		else
		{
			send_user( who, "%c%c%c%s", 0x3d, 49, 
                		who->get_org_position(), who->get_org_name() );              
			
		}
		me->set_demissnumber(0);
		me->set_demisstime(0);
        }
}

// 函数：放逐出帮
void do_banish( object who, object me, string arg )
{
        object char;
        string name1, name2, name3, cmd, id, *member;
        int number, flag, contrib;

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 && who->get_org_position() > ORG_PRESBYTER )    // 本帮官员
        {
        	sscanf( arg, "%d", number);
/*        	
                if( !sscanf( arg, "@.%d", number ) )
                {
                        number = to_int(arg);
                        if( me->get_member_id(number) )
                        {
                                cmd = sprintf( "talk %x# banish.@.%d\n", getoid(me), number );
                                send_user( who, "%c%s", ':', "您确定要放逐" + me->get_member_name(number) + "出帮吗？\n"
                                        ESC "是的。\n" + cmd +
                                        ESC "我再想想……\nCLOSE\n" );
                        }
                        return;
                }
*/
                if( me->get_member_id(number) )
                {
                        if( !( char = find_player( sprintf("%d", number) ) ) )
                        {
                                char = new( USER );
                                char->set_id( me->get_member_id(number) );
                                if( !char->restore() )
                                {
		                        me->delete_member_info(number);   
		                        me->add_total(-1);                            	
                                        send_user( who, "%c%s", '!', "这位玩家并不存在！" );
                                        destruct(char);  return;
                                }
                                flag = 1;    // 离线
                        }

                        name3 = char->get_org_name();
                        if( !stringp(name3) || name3 == "" || name3 != name2 )    // 双保险，可删除
                        {
		                me->delete_member_info(number);  
		                me->add_total(-1);                          	
                                send_user( who, "%c%s", '!', char->get_name() + "不是“" + name2 + "”帮众。" );
                                if( flag ) destruct(char);
                                return;
                        }

                        if( char->get_org_position() >= who->get_org_position() )    // 权限判断！
                        {
                                send_user( who, "%c%s", '!', "您在“" + name2 + "”中职位太低。" );
                                if( flag ) destruct(char);
                                return;
                        }

                        id = char->get_id();
                        if( id == me->get_master_id_2() )
                        {
                                me->set_master_2(0);
                                me->set_master_id_2("");
                                me->set_master_name_2("－－");
                        }
                        member = me->get_presbyter();
			if (arrayp(member) && member_array(id, member)!=-1 )
                        {
                        	member -= ({ id });
                        	me->set_presbyter(member);
                        }
                        member = me->get_manager4();
                        if (arrayp(member) && member_array(id, member)!=-1 )
                        {
                        	member -= ({ id });
                        	me->set_manager4(member);
                        }
                        if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
                        {
                        	member -= ({ id });
                        	me->set_manager5(member);
                        }
                        if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
                        {
                        	member -= ({ id });
                        	me->set_manager6(member);
                        }
                        if ( (member = me->get_trader()) && arrayp(member) && member_array(id, member)!=-1 )
                        {
                        	member -= ({ id });
                        	me->set_trader(member);
                        }
			contrib = me->get_member_contribute(number);
                        me->delete_member_info(number);                             
                        send_user( who, "%c%c%d", 0x95, 13, number );
                        send_user( who, "%c%c%d", 0x95, 95, number );
                        me->add_total(-1);
                        // 如果对方是禅让的, 则取消禅让
                        if (me->get_demisstime()>0)
                        {
                        	if (me->get_demissnumber()==number)
                        	{
                        		me->set_demisstime(0);
                        		me->set_demissnumber(0);
                        	}
                        }

                        char->set_org_name("");
                        char->set_org_position(0);
                        char->set_org_title("");
                        char->set_org_time( time() );
                        char->delete_title("C001");
                        char->delete_title("C002");
                        char->delete_title("C003");
                        char->delete_title("C004");
                        char->delete_title("C005");
                        char->delete_title("C006");
                        char->delete_title("C007");
                        char->delete_title("C008");
                        char->save();
                        char->log_legend( sprintf( "您被%s(%d)放逐出“%s”，帮贡:%d！", who->get_name(), who->get_number(), name2, contrib ) );
                        FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s将%s(%d)放逐出帮！",
                                who->get_name(), char->get_name(), char->get_number() ) );
			WUSHUANG->check_org_title(char);
                        if( flag ) destruct(char);
                        else 
                        {
                        	send_user(char, "%c%c", 0x95, 255);    // 关闭所有帮派界面
				send_user( char, "%c%c%c%c", 0x3d, 49, 
		                	0, 0 );                                      	
                        }
                }
                else
                {
                	me->delete_member_info(number);                 	
                }
        }
}

// 函数：退出帮派 (有钱票不能离帮)
void do_exit( object who, object me, string arg )
{
        string name1, name2, cmd, *member, id;
        int number, flag, contrib;
        object item;

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )    // 本帮帮众
        {
                if( present("钱票", who, 1, MAX_CARRY*4) )
                {
                        send_user(me, "%c%s", '!', "您有钱票在身，不能离帮。");
                        return;
                }
                if( who->get_org_position() >= ORG_MASTER )
                {
                        send_user( who, "%c%s", '!', "您在“" + name2 + "”中职务过高，不能主动离帮。" );
                        return;
                }
                id = who->get_id();
                if( !arg || arg != "@" )
                {
                        cmd = sprintf( "talk %x# exit.@\n", getoid(me) );
                        send_user( who, "%c%s", ':', "您确定即使牺牲帮贡，也要退出“" + name2 + "”吗？\n"
                                ESC "是的。\n" + cmd +
                                ESC "我再想想……\nCLOSE\n" );
                        return;
                }
		if( id == me->get_master_id_2() )
		{
		        me->set_master_2(0);
		        me->set_master_id_2("");
		        me->set_master_name_2("－－");
		}                
                member = me->get_presbyter();
		if (arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_presbyter(member);
                }
                member = me->get_manager4();
                if (arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager4(member);
                }
                if ( (member = me->get_manager5()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager5(member);
                }
                if ( (member = me->get_manager6()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_manager6(member);
                }
                if ( (member = me->get_trader()) && arrayp(member) && member_array(id, member)!=-1 )
                {
                	member -= ({ id });
                	me->set_trader(member);
                }
                number = who->get_number();
                contrib = me->get_member_contribute(number);
                me->delete_member_info(number);
                send_user( who, "%c%c%d", 0x95, 23, number );
                send_user( who, "%c%c%d", 0x95, 96, number );
                me->add_total(-1);

                who->set_org_name("");
                who->set_org_position(0);
                who->set_org_title("");
                who->set_org_time( time() );
                who->delete_title("C001");
                who->delete_title("C002");
                who->delete_title("C003");
                who->delete_title("C004");
                who->delete_title("C005");
                who->delete_title("C006");
                who->delete_title("C007");
                who->delete_title("C008");
                who->log_legend( sprintf( "您退出“%s”，帮贡:%d！", name2, contrib ) );
                FAMILY_D->org_channel( name2, 0, sprintf( HIR "%s退出本帮！", who->get_name() ) );

                send_user(who, "%c%c", 0x95, 255);    // 关闭所有帮派界面
		send_user( who, "%c%c%c%c", 0x3d, 49, 
                	0, 0 );
                WUSHUANG->check_org_title(who);              
                
        }
}

// -------------------------------------------------------------

// 函数：帮派金库
void do_savings( object who, object me, string arg )
{
        string name1, name2, result;
        int id, gold, i, size, number;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )    // 本帮帮众
        {
                gold = to_int(arg);

                if( !gold )
                {
                        send_user( who, "%c%c%d%d%s", 0x95, 60, id, me->get_gold(), me->get_org_name() );
                }
                else
                {
                        if( gold < 1 )
                        {
                                send_user( who, "%c%s", '!', "捐款必须是正整数。" );
                                return;
                        }
                        if( gold > who->get_cash() )
                        {
                                send_user( who, "%c%s", '!', sprintf( "您手上只有 %d 金。", who->get_cash() ) );
                                return;
                        }
                        if( me->get_gold() >= me->get_grade()*40000000 )
                        {
                                send_user( who, "%c%s", '!', sprintf( "“%s”帮派资金已达上限！", me->get_org_name() ) );
                                return;
                        }
                        if (gold+ me->get_gold() >= me->get_grade()*40000000 ) gold = me->get_grade()*40000000 - me->get_gold();

                        who->add_cash( -gold );  who->add_gold_log("org", gold);
                        who->log_money("帮派", -gold);
                        "/sys/sys/count"->add_use("org", gold);
                        send_user( who, "%c%c%d", 0x95, 61, me->add_gold(gold) );

                        id = who->get_number();
                        send_user( who, "%c%c%d", 0x95, 62, me->set_member_gold( id, me->get_member_gold(id) + gold ) );

                        result = sprintf( "您拿出 %d 金捐献给“%s”。", gold, me->get_org_name() );
                        send_user(who, "%c%s", '!', result);
                        write_user(who, ECHO + result);

                        result = sprintf( HIR "%s(%d)拿出 %d 金捐献给本帮！", who->get_name(), who->get_number(), gold );
                        if( gold >= 100000 ) FAMILY_D->org_channel(name2, 0, result);
                        if (gold >= 10000)
                        {
                        	number = who->get_number();
                        	me->set_member_contribute(number, me->get_member_contribute(number)+gold/10000);
                        	send_user(who, "%c%c%w%s", ':', 3, 0, sprintf("因为你对帮派作出的贡献，得到了%d点帮派贡献点的回报。", gold/10000) );
                        }
                }
        }
}
