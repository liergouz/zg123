
#include <ansi.h>
#include <equip.h>

// �����������
int main( object me, string arg )
{
        mapping skls;
        object who, *inv, obj;
        string *name;
        int skill, p, i, size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg ) arg = "?";

        if( arg == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "������Ҽ��ܡ�װ����\n\n������Է������֣ɣģ�\n"
                        ESC "possess %%s\n" ) );
                return 1;
        }
        if( !( who = find_player(arg) ) ) 
        {
                notify( "���Ҳ�����λ��ҡ�" );
                return 1;
        }
        if( me == who )
        {
                notify( "�������Լ��ļ��ܡ�װ����" );
                return 1;
        }

        if( mapp( skls = me->get_skill_dbase() ) && sizeof(skls) )
        {
                name = keys(skls);
                for( i = 0, size = sizeof(name); i < size; i ++ )
                {
                        me->delete_skill( to_int( name[i] ) );
                }
        }
//      me->init_skill_dbase();

        if( mapp( skls = who->get_skill_dbase() ) && sizeof(skls) )
        {
                name = keys(skls);
                for( i = 0, size = sizeof(name); i < size; i ++ )
                {
                        skill = to_int( name[i] );
                        me->set_skill( skill, who->get_skill(skill) );
                }
        }

        me->set_reincarnation( who->get_reincarnation() );
        me->set_exp( who->get_exp(), who->get_billion_exp() );
        USER_EXP_D->recount_user_level(me);

        inv = me->get_all_equip();
        for( i = 0, size = sizeof(inv); i < size; i ++ ) if( inv[i] )
        {
                inv[i]->remove_from_user();
                destruct( inv[i] );
        }

        me->set_gender( who->get_gender() );    // �����Ա�

        inv = who->get_all_equip();
        for( i = 0, size = sizeof(inv); i < size; i ++ ) if( inv[i] )
        {
                obj = new( get_file_name(inv[i]) );

                if( p = obj->move(me, -1) ) 
                {
                        obj->add_to_user(p);
                        me->use_equip(obj);
                }
                else destruct(obj);
        }

        me->set_hp( me->get_max_hp() );
        me->set_mp( me->get_max_mp() );

        me->add_to_scene( get_z(me), get_x(me), get_y(me), get_d(me) );    // �ؽ�����

        tell_user( me, "�����Ѿ���ɣ�" );

        return 1;
}
