
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("�ط�����");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(25);
        set_value(6250);
        set_max_lasting(5499);
        set("dp", 12);
        set("pp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ط�����";
}
