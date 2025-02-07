
#include <ansi.h>
#include <skill.h>
#include <effect.h>

void effect_herb_break( object me );

// �������Զ��ɼ���ҩ
void into_effect( object me )
{
        object map, item;
        string file;
        int total, amount, z, x, y, p, status;

        z = get_z(me);  x = get_x(me);  y = get_y(me);

        switch( get_d(me) )
        {
       case 1 : x ++;         break;
       case 2 : x ++;  y --;  break;
      default :        y --;  break;
       case 4 : x --;  y --;  break;
       case 5 : x --;         break;
       case 6 : x --;  y ++;  break;
       case 7 :        y ++;  break;
       case 8 : x ++;  y ++;  break;
        }

        if( !inside_jumpin(z, x, y, 16) )
        {
                send_user( me, "%c%s", '!', "���õ���زɼ���ҩ��" );
                effect_herb_break(me);
                return;
        }
        if( !( map = get_map_object(z) ) )
        {
//              send_user( me, "%c%s", '!', "���õ���زɼ���ҩ��" );
                effect_herb_break(me);
                return;
        }

        if( ( total = map->get_herb(x, y) ) >= 3 )
        {
                send_user( me, "%c%s", '!', "����Ĳ�ҩ�Ѿ��ɼ����ˡ�" );
                effect_herb_break(me);
                return;
        }

        p = random(1000);

        switch( total )
        {
       case 0 : if( p >= 20 ) 
                {
                        set_effect(me, EFFECT_USER_HERB_OK, 1);
                        send_user(me, "%c%c%c", 0x5a, 1, 0);
                        return;
                }
                break;
       case 1 : if( p >= 10 ) 
                {
                        set_effect(me, EFFECT_USER_HERB_OK, 1);
                        send_user(me, "%c%c%c", 0x5a, 1, 0);
                        return;
                }
                break;
      default : if( p >= 5 ) 
                {
                        set_effect(me, EFFECT_USER_HERB_OK, 1);
                        send_user(me, "%c%c%c", 0x5a, 1, 0);
                        return;
                }
                break;
        }
        map->add_herb(x, y, 1);

        p = random(100);

        if( p < 3 )    // ͻ���¼�
        {
                switch( p )
                {
               case 0 : p = random(100);

                        if( p < 35 ) file = "/item/91/9101";
                        else if( p < 50 ) file = "/item/91/9102";
                        else if( p < 85 ) file = "/item/91/9111";
                        else file = "/item/91/9112";

                        if( !load_object(file) )
                        {
                                effect_herb_break(me);
                                return;
                        }

                        item = new( file );

                        if( ( total = USER_INVENTORY_D->can_carry(me, item) ) < 1 )
                        {
                                destruct(item);
                                send_user( me, "%c%s", '!', "��Я���Ķ���̫���ˡ�" );
                                effect_herb_break(me);
                                return;
                        }

                        if( item->is_combined() )
                        {
                                if( total > item->get_amount() ) total = item->get_amount();
                                printf( ECHO "����� %s��", item->get_name() );
                                send_user( me, "%c%s", '!', sprintf( "����� " HIY "%s" NOR "��", item->get_name() ) );

                                amount = USER_INVENTORY_D->carry_combined_item(me, item, total);
                
                                if( amount > 0 && item->set_amount(amount) )
                                {
                                        if( p = item->move(me, -1) )
                                        {
//                                              item->remove_from_scene();
                                                item->add_to_user(p);
                                        }
                                }
                                else    item->add_amount( -total );
                        }
                        else if( p = item->move(me, -1) )
                        {
                                printf( ECHO "�����%s��", item->get_name() );
                                send_user( me, "%c%s", '!', sprintf( "�����" HIY "%s" NOR "��", item->get_name() ) );

//                              item->remove_from_scene();
                                item->add_to_user(p);
                        }

                        break;

               case 1 : 
                        if(    !get_effect(me, EFFECT_CHAR_POISON)
                        &&     !get_effect(me, EFFECT_CHAR_9140) )    // �ٶ�ɢ
                        {
                                printf( ECHO "��һ��С���ж��ˣ�" );
                                send_user( me, "%c%s", '!', "��һ��С���ж��ˣ�" );

                                me->set_poison(50);    // ���� 500 / 10
                                set_effect_2(me, EFFECT_CHAR_POISON, 10, 2);
                                send_user( me, "%c%w%w%c", 0x81, 9096, get_effect_3(me, EFFECT_CHAR_POISON), EFFECT_BAD );
                                send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 9096, 1, EFFECT_BAD );
                        }

                        break;

              default : 
                        if(     gone_time( map->get("herbman#") ) >= 600    // 10 ����
                        &&     !objectp( map->get("herbman") ) )
                        {
                                item = new( "/npc/std/1088" );    // ��ҩ��
                                if( !( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) ) )
                                {
                                        destruct(item);  break;
                                }

                                item->add_to_scene(z, p / 1000, p % 1000, 3);

                                map->set( "herbman#", time() );
                                map->set( "herbman", item );
                        }

                        break;
                }

                effect_herb_break(me);
                return;
        }
        else switch( z )    // ��ò�ҩ
        {
      default : if( p < 33 ) file = "/item/90/9041";
                else if( p < 63 ) file = "/item/90/9052";
                else if( p < 79 ) file = "/item/90/9051";
                else if( p < 95 ) file = "/item/90/9074";
                else file = "/item/90/9085";
                break;
     case 020 : if( p < 33 ) file = "/item/90/9023";
                else if( p < 63 ) file = "/item/90/9030";
                else if( p < 79 ) file = "/item/90/9032";
                else if( p < 95 ) file = "/item/90/9040";
                else file = "/item/90/9084";
                break;
     case 030 : if( p < 33 ) file = "/item/90/9011";
                else if( p < 63 ) file = "/item/90/9012";
                else if( p < 79 ) file = "/item/90/9020";
                else if( p < 95 ) file = "/item/90/9022";
                else file = "/item/90/9083";
                break;
     case 040 : if( p < 33 ) file = "/item/90/9001";
                else if( p < 63 ) file = "/item/90/9003";
                else if( p < 79 ) file = "/item/90/9004";
                else if( p < 95 ) file = "/item/90/9010";
                else file = "/item/90/9082";
                break;
     case 050 : if( p < 33 ) file = "/item/90/9061";
                else if( p < 63 ) file = "/item/90/9062";
                else if( p < 79 ) file = "/item/90/9070";
                else if( p < 95 ) file = "/item/90/9071";
                else file = "/item/90/9086";
                break;
     case 060 : if( p < 33 ) file = "/item/90/9031";
                else if( p < 63 ) file = "/item/90/9021";
                else if( p < 79 ) file = "/item/90/9002";
                else if( p < 95 ) file = "/item/90/9050";
                else file = "/item/90/9080";
                break;
     case 070 : if( p < 33 ) file = "/item/90/9072";
                else if( p < 63 ) file = "/item/90/9073";
                else if( p < 79 ) file = "/item/90/9042";
                else if( p < 95 ) file = "/item/90/9060";
                else file = "/item/90/9081";
                break;
        }

        if( !load_object(file) )
        {
                effect_herb_break(me);
                return;
        }

        item = new( file );

        if( ( total = USER_INVENTORY_D->can_carry(me, item) ) < 1 )
        {
                destruct(item);
                send_user( me, "%c%s", '!', "��Я���Ķ���̫���ˡ�" );
                effect_herb_break(me);
                return;
        }
        status = me->get_save("tips_status");   
	if ((status & 16)==0)
	{
		QUEST_TIPS->send_tips(me, "5");
		status |= 16;
		me->set_save("tips_status", status);
	}   
        if( item->is_combined() )
        {
                if( total > item->get_amount() ) total = item->get_amount();
                printf( ECHO "���ɼ��� %s��", item->get_name() );
                send_user( me, "%c%s", '!', sprintf( "���ɼ��� " HIY "%s" NOR "��", item->get_name() ) );

                amount = USER_INVENTORY_D->carry_combined_item(me, item, total);
                
                if( amount > 0 && item->set_amount(amount) )
                {
                        if( p = item->move(me, -1) )
                        {
//                              item->remove_from_scene();
                                item->add_to_user(p);
                        }
                }
                else    item->add_amount( -total );
        }
        else if( p = item->move(me, -1) )
        {
                printf( ECHO "���ɼ���%s��", item->get_name() );
                send_user( me, "%c%s", '!', sprintf( "���ɼ���" HIY "%s" NOR "��", item->get_name() ) );

//              item->remove_from_scene();
                item->add_to_user(p);
        }

        set_effect(me, EFFECT_USER_HERB, 0);
        send_user(me, "%c%c%c", 0x5a, 1, 1);
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 00131, 10, OVER_BODY, PF_STOP );
}

// �������ɼ���ҩ����
void into_effect_ok( object me )
{
        set_effect(me, EFFECT_USER_HERB, 2);    // �����ɼ�
        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "�ɼ���ҩ�С���");
}

// ������ֹͣ�ɼ���ҩ
void effect_herb_break( object me )
{
        set_effect(me, EFFECT_USER_HERB, 0);
        send_user(me, "%c%c", 0x5a, 255);
        CHAR_CHAR_D->init_loop_perform(me);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 00131, 10, OVER_BODY, PF_STOP );
}
