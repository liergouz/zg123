
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�Ƶ�Ь");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(40);
        set_value(6000);
        set_max_lasting(7399);
        set("dp", 20);
        set("sp", 16);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�Ƶ�Ь";
}
