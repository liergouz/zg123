
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(35);
        set_value(4400);
        set_max_lasting(7099);
        set("dp", 18);
        set("sp", 19);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
