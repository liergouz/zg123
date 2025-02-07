
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string id;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, cmd9, cmd10, cmd11;
        int hp, mp, ap, dp, cp, pp, sp, speed, speed2, rate, flag;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg )
        {
                id = "?";
                hp = -1;  mp = -1;
                ap = -1;  dp = -1;
                cp = -1;  pp = -1;  sp = -1;
                speed = -1;  speed2 = -1;  rate = -1;
                flag = -1;
        }
        else if( sscanf( arg, "%s %d %d %d %d %d %d %d %d %d %d %d", id, hp, mp, ap, dp, cp, pp, sp, speed, speed2, rate, flag ) != 12 )
        {
                id = arg;
                hp = -1;  mp = -1;
                ap = -1;  dp = -1;
                cp = -1;  pp = -1;  sp = -1;
                speed = -1;  speed2 = -1;  rate = -1;
                flag = -1;
        }

        if( id == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 16, 16, sprintf( "设置ＮＰＣ数值。\n\n请输入ＮＰＣ的ＩＤ：\n"
                        ESC "setnpc %%s\n" ) );
                return 1;
        }
        if( !( who = find_char(id) ) ) 
        {
                notify( "您找不到这个人物。" );
                return 1;
        }
        if( who->is_user() )
        {
                notify( "您不能更改玩家的数值。" );
                return 1;
        }
        else if( flag < 0 )    // 初始化数值
        {
                if( hp < 0 ) hp = who->get_max_hp();
                if( mp < 0 ) mp = who->get_max_mp();
                if( ap < 0 ) ap = who->get_ap();
                if( dp < 0 ) dp = who->get_dp();
                if( cp < 0 ) cp = who->get_cp();
                if( pp < 0 ) pp = who->get_pp();
                if( sp < 0 ) sp = who->get_sp();
                if( speed < 0 ) speed = who->get_walk_speed();
                if( speed2 < 0 ) speed2 = who->get_attack_speed();
                if( rate < 0 ) rate = who->get_ap() < 1 ? 0 : who->get_ap_0() * 100 / who->get_ap();
                flag = 0;
        }

        if( hp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的气血：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_max_hp() ) +
                        sprintf( ESC "setnpc %s %%s %d %d %d %d %d %d %d %d %d 0\n", id, mp, ap, dp, cp, pp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( mp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的法力：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_max_mp() ) +
                        sprintf( ESC "setnpc %s %d %%s %d %d %d %d %d %d %d %d 0\n", id, hp, ap, dp, cp, pp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( ap < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的攻击：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_ap() ) +
                        sprintf( ESC "setnpc %s %d %d %%s %d %d %d %d %d %d %d 0\n", id, hp, mp, dp, cp, pp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( dp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的防御：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_dp() ) +
                        sprintf( ESC "setnpc %s %d %d %d %%s %d %d %d %d %d %d 0\n", id, hp, mp, ap, cp, pp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( cp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的法攻：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_cp() ) +
                        sprintf( ESC "setnpc %s %d %d %d %d %%s %d %d %d %d %d 0\n", id, hp, mp, ap, dp, pp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( pp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的法防：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_pp() ) +
                        sprintf( ESC "setnpc %s %d %d %d %d %d %%s %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, sp, speed, speed2, rate ) );
                return 1;
        }
        if( sp < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的速度：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_sp() ) +
                        sprintf( ESC "setnpc %s %d %d %d %d %d %d %%s %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, speed, speed2, rate ) );
                return 1;
        }
        if( speed < 0 )
        {
                cmd1 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 4, speed2, rate );
                cmd2 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 6, speed2, rate );
                cmd3 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 8, speed2, rate );
                cmd4 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 10, speed2, rate );
                cmd5 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 12, speed2, rate );
                cmd6 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 14, speed2, rate );
                cmd7 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 16, speed2, rate );
                cmd8 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, 18, speed2, rate );
                send_user( me, "%c%s", ':', sprintf( "%s(%x#)的走路：%d.%d秒，请输入新的数值：\n", 
                        who->get_name(), getoid(who), who->get_walk_speed() / 10, who->get_walk_speed() % 10 ) +
                        ESC "0.4秒。\n" + cmd1 +
                        ESC "0.6秒。\n" + cmd2 +
                        ESC "0.8秒。\n" + cmd3 +
                        ESC "1.0秒。\n" + cmd4 +
                        ESC "1.2秒。\n" + cmd5 +
                        ESC "1.4秒。\n" + cmd6 +
                        ESC "1.6秒。\n" + cmd7 +
                        ESC "1.8秒。\n" + cmd8 );
                return 1;
        }
        if( speed2 < 0 )
        {
                cmd1 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 10, rate );
                cmd2 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 15, rate );
                cmd3 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 20, rate );
                cmd4 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 25, rate );
                cmd5 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 30, rate );
                cmd6 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 35, rate );
                cmd7 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 40, rate );
                cmd8 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, 45, rate );
                send_user( me, "%c%s", ':', sprintf( "%s(%x#)的攻击：%d.%d秒，请输入新的数值：\n", 
                        who->get_name(), getoid(who), who->get_attack_speed() / 10, who->get_attack_speed() % 10 ) +
                        ESC "1.0秒。\n" + cmd1 +
                        ESC "1.5秒。\n" + cmd2 +
                        ESC "2.0秒。\n" + cmd3 +
                        ESC "2.5秒。\n" + cmd4 +
                        ESC "3.0秒。\n" + cmd5 +
                        ESC "3.5秒。\n" + cmd6 +
                        ESC "4.0秒。\n" + cmd7 +
                        ESC "4.5秒。\n" + cmd8 );
                return 1;
        }
        if( rate < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, 100000, 
                        sprintf( "%s(%x#)的最小／最大比率：%d，请输入新的数值：\n", who->get_name(), getoid(who), who->get_ap() < 1 ? 0 : who->get_ap_0() * 100 / who->get_ap() ) +
                        sprintf( ESC "setnpc %s %d %d %d %d %d %d %d %d %d %%s 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, speed2 ) );
                return 1;
        }

        if( flag < 1 )
        {
                cmd1 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, -1, mp, ap, dp, cp, pp, sp, speed, speed2, rate );
                cmd2 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, -1, ap, dp, cp, pp, sp, speed, speed2, rate );
                cmd3 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, -1, dp, cp, pp, sp, speed, speed2, rate );
                cmd4 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, -1, cp, pp, sp, speed, speed2, rate );
                cmd5 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, -1, pp, sp, speed, speed2, rate );
                cmd6 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, -1, sp, speed, speed2, rate );
                cmd7 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, -1, speed, speed2, rate );
                cmd8 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, -1, speed2, rate );
                cmd9 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, -1, rate );
                cmd10 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 0\n", id, hp, mp, ap, dp, cp, pp, sp, speed, speed2, -1 );
                cmd11 = sprintf( "setnpc %s %d %d %d %d %d %d %d %d %d %d 1\n", id, hp, mp, ap, dp, cp, pp, sp, speed, speed2, rate );
                send_user( me, "%c%s", ':', sprintf( "请设置%s(%x#)的数值：\n", who->get_name(), getoid(who) ) +
                        sprintf( ESC "气血: %d\n", hp ) + cmd1 +
                        sprintf( ESC "法力: %d\n", mp ) + cmd2 +
                        sprintf( ESC "攻击: %d\n", ap ) + cmd3 +
                        sprintf( ESC "防御: %d\n", dp ) + cmd4 +
                        sprintf( ESC "法攻: %d\n", cp ) + cmd5 +
                        sprintf( ESC "法防: %d\n", pp ) + cmd6 +
                        sprintf( ESC "速度: %d\n", sp ) + cmd7 +
                        sprintf( ESC "走路: %d.%d秒\n", speed / 10, speed % 10 ) + cmd8 +
                        sprintf( ESC "攻击: %d.%d秒\n", speed2 / 10, speed2 % 10 ) + cmd9 +
                        sprintf( ESC "比率: %d％\n", rate ) + cmd10 +
                        ESC "确认设置。\n" + cmd11 );
                return 1;
        }
        else
        {
                if( hp > 0 ) hp = who->set_max_hp(hp);
                if( mp > 0 ) mp = who->set_max_mp(mp);
                if( ap > 0 ) ap = who->set_ap(ap);
                if( dp > 0 ) dp = who->set_dp(dp);
                if( cp > 0 ) cp = who->set_cp(cp);
                if( pp > 0 ) pp = who->set_pp(pp);
                if( sp > 0 ) sp = who->set_sp(sp);
                if( speed > 0 ) speed = who->set_walk_speed(speed);
                if( speed2 > 0 ) speed2 = who->set_attack_speed(speed2);
                if( rate > -1 ) 
                {
                        who->set_ap_0( who->get_ap() * rate / 100 );
                        who->set_dp_0( who->get_dp() * rate / 100 );
                        who->set_cp_0( who->get_cp() * rate / 100 );
                        who->set_pp_0( who->get_pp() * rate / 100 );
//                      who->set_sp_0( who->get_sp() * rate / 100 );
                }
                tell_user( me, "设置%s(%x#)完成。", who->get_name(), getoid(who) );
        }

        return 1;
}
