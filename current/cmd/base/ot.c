
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string name, id, org;
        int t;

        if( ( org = me->get_org_name() ) == "" ) return 1;
        if (me->get_org_position()==0) return 1;

/*      if( me->is_die() )
        {
                notify( "您死了，帮派频道已被禁止。" );
                return 1;
        }       */

        if( !is_god(me) && gone_time( me->get_time("ot") ) < 3 )
        {
                notify( "请勿频繁使用帮派频道。" );
                return 1;
        }
        me->set_time( "ot", time() );

	if( !arg ) 
	{
                notify( "您想对大家说什么？" );
                return 1;
	}

        if( me->sizeof_chblk_dbase() )    // 判断能否使用频道
        {
                t = gone_time( me->get_chblk("time") );
                me->add_chblk("chat", -t );
                me->add_chblk("rumor", -t );
                me->add_chblk("trade", -t );
                me->add_chblk("city", -t );
                me->add_chblk("family", -t );
                me->add_chblk("org", -t );
                me->add_chblk("say", -t );
                me->set_chblk("time", time() );

                if(     me->get_chblk("chat") < 1 && me->get_chblk("rumor") < 1 && me->get_chblk("trade") < 1
                &&      me->get_chblk("city") < 1 && me->get_chblk("family") < 1 && me->get_chblk("org") < 1 && me->get_chblk("say") < 1 )
                        me->init_chblk_dbase();

                if( ( t = me->get_chblk("org") ) > 0 )
                {
                        notify( "%s频道将于 %d 分钟后开启。", org, t / 60 + 1 );
                        return 1;
                }
        }
	"/quest/help"->send_help_tips(me, 44);
	"/quest/help"->send_help_tips(me, 45);
        if( !me->get_org_open() )    // 使用可以打开频道
        {
                me->set_org_open(1);
                FAMILY_D->add_org(me);
        }
        //name = sprintf( NAME_LEFT "%s" NAME_RIGHT, me->get_name() );
        name = sprintf("%c+%d,%s=%d%c-", '\t', 255*256*256+102*256, me->get_name(), me->get_number(), '\t');
        name = replace_string(name, "#", "＃");

	if( arg[0] == '#' && ( arg[1] < '0' || arg[1] > '9' ) )
	{
	        arg = arg[1..<1];

                FAMILY_D->org_channel( org, me->get_number(), sprintf( CHAT "%s%s", name, arg ) );
	}
	else if( arg[0] == '*' )
	{
	        arg = arg[1..<1];

                if( sscanf( arg, "%s %s", arg, id ) == 2 )
                {
                        if( id == "i" || id == "me" )
                        {
                                who = me;
                        }
                        else if( !( who = find_char(id) ) )
                        {
                                notify( "您无法找到这个人。" );
	        	        return 1;
                        }
                        arg = EMOTE_D->do_emote(me, name, arg, who);
                }
                else    arg = EMOTE_D->do_emote(me, name, arg, 0);

                if( !arg ) return 1;

                FAMILY_D->org_channel( org, me->get_number(), CHAT + arg );
	}
	else    FAMILY_D->org_channel( org, me->get_number(), sprintf( CHAT "%s：%s", name, arg ) );

        return 1;
}
