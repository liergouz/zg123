
#include <ansi.h>
#include <skill.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
        mapping skls;
        object *inv, item;
        string cmd0, cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7;
        string cmd10, cmd20, cmd30, cmd40, cmd50, cmd60, cmd70;
        string *name, file;
        int family, level, level2, weapon, armor, skill;
        int p, i, size;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }
        if( !is_gm2(me) && !is_god(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }        
        if( !arg )
        {
                family = -1;  level = -1;  weapon = -1;
        }
        else if( sscanf( arg, "%d %d %d", family, level, weapon ) == 3 )
                ;
        else if( sscanf( arg, "%d %d", family, level ) == 2 )
                weapon = -1;
        else 
        {
                family = -1;  level = -1;  weapon = -1;
        }

        if( family < 0 )
        {
                cmd1 = sprintf( "family 1 %d\n", level );
                cmd2 = sprintf( "family 2 %d\n", level );
                cmd3 = sprintf( "family 3 %d\n", level );
                cmd4 = sprintf( "family 4 %d\n", level );
                cmd5 = sprintf( "family 5 %d\n", level );
                cmd6 = sprintf( "family 6 %d\n", level );
                cmd7 = sprintf( "family 7 %d\n", level );
                cmd10 = sprintf( "family 10 %d\n", level );
                cmd20 = sprintf( "family 20 %d\n", level );
                cmd30 = sprintf( "family 30 %d\n", level );
                cmd40 = sprintf( "family 40 %d\n", level );
                cmd50 = sprintf( "family 50 %d\n", level );
                cmd60 = sprintf( "family 60 %d\n", level );
                cmd70 = sprintf( "family 70 %d\n", level );
                cmd0 = sprintf( "family 0 %d\n", level );
                send_user( me, "%c%s", ':', "您想把自己设为哪种门派？\n"
                        ESC "桃花源\n" + cmd1 +
                        ESC "蜀山\n" + cmd2 +
                        ESC "禁卫军\n" + cmd3 +
                        ESC "唐门\n" + cmd4 +
                        ESC "茅山\n" + cmd5 +
                        ESC "昆仑山\n" + cmd6 +
                        ESC "云梦泽\n" + cmd7 +
                        ESC "桃花源(基本)\n" + cmd10 +
                        ESC "蜀山(基本)\n" + cmd20 +
                        ESC "禁卫军(基本)\n" + cmd30 +
                        ESC "唐门(基本)\n" + cmd40 +
                        ESC "茅山(基本)\n" + cmd50 +
                        ESC "昆仑山(基本)\n" + cmd60 +
                        ESC "云梦泽(基本)\n" + cmd70 +
                        ESC "无门派\n" + cmd0 );
                return 1;
        }
        else switch( family )
        {
              default : file = "无门派";  break;
     case 1 : case 10 : file = "桃花源";  break;
     case 2 : case 20 : file = "蜀山";  break;
     case 3 : case 30 : file = "禁卫军";  break;
     case 4 : case 40 : file = "唐门";  break;
     case 5 : case 50 : file = "茅山";  break;
     case 6 : case 60 : file = "昆仑山";  break;
     case 7 : case 70 : file = "云梦泽";  break;
        }

        if( level < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, me->get_max_skill_level_2(), sprintf( "生成“%s”技能、装备。\n\n请输入技能等级：\n"
                        ESC "family %d %%s\n", file, family ) );
                return 1;
        }

        if( mapp( skls = me->get_skill_dbase() ) && sizeof(skls) )
        {
                name = keys(skls);
                for( i = 0, size = sizeof(name); i < size; i ++ )
                {
                	skill = to_int( name[i] );
                	if (skill<610) me->delete_skill( skill );
                }
        }
//      me->init_skill_dbase();    // 删除所有技能

        inv = me->get_all_equip();
        for( i = 0, size = sizeof(inv); i < size; i ++ ) if( inv[i] )
        {
                inv[i]->remove_from_user();    // 删除所有装备
                destruct( inv[i] );
        }
        me->set_upgrade_exp(0);
        if (level==0) me->set_exp(0, 0);
        else
        	me->set_exp( USER_EXP_D->get_level_exp_low( me->get_reincarnation(), level - 1 ),
                     USER_EXP_D->get_level_exp_high( me->get_reincarnation(), level - 1 ) );        
        
//      USER_EXP_D->recount_user_level(me);

        NPC_ENERGY_2_D->init_family(me, family, level, weapon);
        USER_ENERGY_D->count_all_prop(me);
        USER_ENERGY_D->count_max_yuan(me);
	me->set_max_level(me->get_level());

        me->set_hp( me->get_max_hp() );
        me->set_mp( me->get_max_mp() );

        tell_user( me, "技能已设置好！" );

        return 1;
}
