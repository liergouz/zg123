
#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�¸�������");
        set_picid_1(6003);
        set_picid_2(6003);
        set_unit("��");

        set_level(0);
        set_value(1);
        set_max_lasting(10099);
        set("dp", 20);
        set_no_give(1);

        setup();

        set_gender(1);
        set_armor_code(M_BUYI);
}

// ��������ȡ����
string get_desc()
{
        return "���¸���ʹ�ã��޵ȼ����ơ����������ơ�";
}
