
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��֮����");
        set_picid_1(8654);
        set_picid_2(8654);

        set_level(50);
        set_value(35000);
        set_max_lasting(5299);
        set("cp", 90);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��֮����";
}
