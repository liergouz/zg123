
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8803);
        set_picid_2(8803);

        set_level(30);
        set_value(4000);
        set_max_lasting(5199);
        set("dp", 8);
        set("sp", 11);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
