
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��ɽ�ñ");
        set_picid_1(6615);
        set_picid_2(6615);

        set_level(50);
        set_value(18000);
        set_max_lasting(6699);
        set("dp", 38);
        set("pp", 58);

        setup();

        set_gender(2);
        set_head_code(53);
}

// ��������ȡ����
string get_desc()
{
        return "��ɽ�ñ";
}
