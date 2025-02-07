
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who, *user;
        string name, *key;
        int id, i, size;
        mapping friends;

        if( !arg ) return 1;
	if (arg=="refresh")
	{
		if( is_player(me) && gone_time( me->get_time("friend") ) < 10 )
		{
			return 1;
		}
		me->set_time( "friend", time() );
		me->refresh_friend();
		return 1;
	}
        if( sscanf( arg, "+ %d", id ) )
        {
                if( !( who = find_player( sprintf( "%d", id ) ) ) )
                {
                        notify( "您找不到这位玩家。" );
                        return 1;
                }
                if( me == who ) 
                {
                        notify( "您不能把自己加为好友。" );
                        return 1;
                }
                if( who->get_no_friend() )
                {
                        notify( "对方关闭了交友开关。" );
                        return 1;
                }
                friends = me->get_friend_dbase();
                key = keys(friends);
                size = sizeof( key );
                if (size>=100)
                {
                        notify( "您的好友数目已达上限。" );
                        return 1;
                }                
                me->add_friend(who, 0);
                "/cmd/base/black"->main(me, sprintf("- %d", who->get_number()) );
		if ( who->get_friend_id(me->get_number()) )
		{
			send_user( who, "%c%c%d", 0x46, 9, me->get_number() ); 
			send_user( me, "%c%c%d", 0x46, 9, who->get_number() ); 
		}        
		else         
			send_user( me, "%c%c%d", 0x46, 9, who->get_number() ); 
        }
        else if( sscanf( arg, "* %d", id ) )
        {
                if( !( who = find_player( sprintf( "%d", id ) ) ) )
                {
                        notify( "您找不到这位玩家。" );
                        return 1;
                }
                if( me == who ) 
                {
                        notify( "您不能把自己加为好友。" );
                        return 1;
                }
                if( who->get_no_friend() )
                {
                        notify( "对方关闭了交友开关。" );
                        return 1;
                }
                friends = me->get_friend_dbase();
                key = keys(friends);
                size = sizeof( key );
                if (size>=100)
                {
                        notify( "您的好友数目已达上限。" );
                        return 1;
                }                 
                me->add_friend(who, 1);
                send_user( me, "%c%c%d", 0x46, 9, who->get_number() ); 
        }
        else if( sscanf( arg, "/ %d", id ) )
        {
                me->set_notify(id, 0);
        }
        else if( sscanf( arg, "! %d", id ) )
        {
                me->set_notify(id, 1);
        }
        else if( sscanf( arg, "- %d", id ) )
        {
                send_user( me, "%c%s", ':', sprintf( "您确定要删除好友" HIR "%s(%d)" NOR "吗？\n" 
                        ESC "我决定同他断交了。\nfriend x %d\n"
                        ESC "要不先留着吧……。\nCLOSE\n", 
                        me->get_friend_name(id), id, id ) );
        }
        else if( sscanf( arg, "x %d", id ) )
        {
                me->remove_friend(id);
        }
        else if( sscanf( arg, "? %s", name ) )
        {
                if( !objectp( who = find_player(name) ) )
                {
                        if(    !arrayp( user = users() )    // 获取所有玩家
                        ||     !arrayp( user = filter_array( user - ({ me }), (: $1->get_name() == $2 :), name ) )    // 判断名字吻合(除自己外)
                        ||     !sizeof(user)    // 用户个数大于０
                        ||     !objectp( who = user[0] ) )    // 取第一个用户
                        {
                        	notify( "查询无此人。" );
                                return 1;
			}                               
                }

                if( !objectp(who) ) 
                {
                        notify( "查询无此人。" );
                        return 1;
                }

                send_user( me, "%c%c%d%s", 0x46, 2, who->get_number(), 
                        sprintf( "%-12s姓　名：%s\n数字ID：%d\n性　别：%s\n"
                                "国　家：%s\n门　派：%s\n帮　派：%s\n等　级：%d\n",
                                who->get_name(), who->get_name(), who->get_number(), 
                                who->get_gender() == 1 ? "男性" : "女性", 
                                who->get_city_name(), who->get_fam_name(), who->get_org_position()>0 ? who->get_org_name() : "",
                                who->get_level() ) );
        }

        return 1;
}
