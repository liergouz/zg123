
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8654);
        set_picid_2(8654);

        set_level(100);
        set_value(62500);
        set_max_lasting(9099);
        set("cp", 0);
        set("pp", 95);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
