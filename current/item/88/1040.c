
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8803);
        set_picid_2(8803);

        set_level(40);
        set_value(6000);
        set_max_lasting(7399);
        set("dp", 20);
        set("sp", 18);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
