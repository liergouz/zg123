
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(70);
        set_value(18000);
        set_max_lasting(6999);
        set("dp", 16);
        set("sp", 27);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
